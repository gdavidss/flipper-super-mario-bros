// Tiny single-voice sequencer for the Flipper piezo.
//
// SMB1's APU runs four channels (square1, square2, triangle, noise) via the
// SPC700 emulator in smw/smb1/smb1_spc_player.c. We only have one tone
// generator, so we collapse everything to a melody line: SFX preempt music
// for their duration, music resumes from where it was.
#pragma once
#include <furi.h>
#include <furi_hal_speaker.h>
#include <stdint.h>
#include <stdbool.h>

// Note frequencies (Hz). 0 = rest.
#define N_REST 0
#define N_C4   262
#define N_CS4  277
#define N_D4   294
#define N_DS4  311
#define N_E4   330
#define N_F4   349
#define N_FS4  370
#define N_G4   392
#define N_GS4  415
#define N_A4   440
#define N_AS4  466
#define N_B4   494
#define N_C5   523
#define N_CS5  554
#define N_D5   587
#define N_DS5  622
#define N_E5   659
#define N_F5   698
#define N_FS5  740
#define N_G5   784
#define N_GS5  831
#define N_A5   880
#define N_AS5  932
#define N_B5   988
#define N_C6  1046
#define N_CS6 1109
#define N_D6  1175
#define N_DS6 1245
#define N_E6  1318
#define N_F6  1397
#define N_FS6 1480
#define N_G6  1568

typedef struct {
    uint16_t freq;  // Hz, 0 = rest
    uint16_t ms;    // duration in ms
} Note;

// SMB1 overworld theme - DECODED from the published SMB1 disassembly
// "SMBDIS.ASM" (Doppelganger). The Square-2 channel (lead melody) is
// transcribed byte-for-byte from `GroundMLdInData` and `GroundM_P1Data`
// using the documented byte format:
//   - bit 7 set:  length-change command, idx = byte & 0x07
//   - bit 7 clear (and nonzero): note byte, freq table offset = byte
//   - byte $04: rest (since FreqRegLookupTbl[4] = $00 $00)
//   - byte $00: end-of-stream
// Note pitches: FreqRegLookupTbl (NES APU timer values -> Hz via 1789773 /
// (16*(T+1))). Lengths: MusicLengthLookupTbl[24..31] = {54,3,9,6,18,27,36,12}
// frames at 60 fps, with GroundLevel header `NoteLenLookupTblOfs=$18`.
//
// This is the AUTHENTIC tempo (~200 bpm) and exact note/duration set as
// shipped in the 1985 ROM. Source: github.com/nwoeanhinnogaehr/smb-assembler.
//
// Length idx -> ms (60fps): 0=900 1=50 2=150 3=100 4=300 5=450 6=600 7=200
static const Note music_overworld[] = {
    // ===== GroundMLdInData (Square 2): $82 $34 $84 $34 $34 $82 $2c $84 $34 $86 $3a $04
    {N_E5, 150}, {N_E5, 300}, {N_E5, 300},
    {N_C5, 150}, {N_E5, 300},
    {N_G5, 600}, {N_REST, 600},

    // ===== GroundM_P1Data (Square 2), played twice per the music layout
    // $85 $2c $22 $1c  -> C5 G4 E4 @ 450ms each
    {N_C5, 450}, {N_G4, 450}, {N_E4, 450},
    // $84 $26 $2a  -> A4 B4 @ 300ms
    {N_A4, 300}, {N_B4, 300},
    // $82 $28 $26 $04  -> Bb4 A4 rest @ 150ms
    {N_AS4, 150}, {N_A4, 150}, {N_REST, 150},
    // $87 $22 $34 $3a  -> G4 E5 G5 @ 200ms
    {N_G4, 200}, {N_E5, 200}, {N_G5, 200},
    // $82 $40 $04 $36  -> A5 rest F5 @ 150ms
    {N_A5, 150}, {N_REST, 150}, {N_F5, 150},
    // $84 $3a $34  -> G5 E5 @ 300ms
    {N_G5, 300}, {N_E5, 300},
    // $82 $2c $30  -> C5 D5 @ 150ms
    {N_C5, 150}, {N_D5, 150},
    // $85 $2a  -> B4 @ 450ms
    {N_B4, 450},

    // Part 1 again (per music layout: Part1, Part1)
    {N_C5, 450}, {N_G4, 450}, {N_E4, 450},
    {N_A4, 300}, {N_B4, 300},
    {N_AS4, 150}, {N_A4, 150}, {N_REST, 150},
    {N_G4, 200}, {N_E5, 200}, {N_G5, 200},
    {N_A5, 150}, {N_REST, 150}, {N_F5, 150},
    {N_G5, 300}, {N_E5, 300},
    {N_C5, 150}, {N_D5, 150},
    {N_B4, 450},

    // Small pause before loop restart (the LeadIn naturally re-establishes)
    {N_REST, 600},
};
#define MUSIC_OVERWORLD_LEN ((int)(sizeof(music_overworld) / sizeof(Note)))

static const Note sfx_jump[]    = { {N_C5, 30}, {N_E5, 30}, {N_G5, 30}, {N_C6, 50} };
static const Note sfx_coin[]    = { {N_B5, 60}, {N_E6, 200} };
static const Note sfx_stomp[]   = { {N_C5, 50}, {N_G4, 80} };
static const Note sfx_brick[]   = { {N_G4, 30}, {N_C4, 30}, {N_REST, 20} };
static const Note sfx_powerup[] = {
    {N_C5, 60}, {N_G5, 60}, {N_C6, 60},
    {N_E5, 60}, {N_A5, 60}, {N_C6, 60},
    {N_F5, 60}, {N_B5, 60}, {N_D6, 120},
};
static const Note sfx_1up[] = {
    {N_E5, 80}, {N_G5, 80}, {N_E6, 80}, {N_C6, 80}, {N_D6, 80}, {N_G6, 120},
};
static const Note sfx_death[] = {
    {N_C5, 100}, {N_REST, 80},
    {N_G4, 80}, {N_F4, 80}, {N_E4, 80}, {N_D4, 80},
    {N_C4, 300},
};
static const Note sfx_pause[]  = { {N_E5, 80} };
static const Note sfx_win[]    = {
    {N_G4, 120}, {N_C5, 120}, {N_E5, 120}, {N_G5, 120},
    {N_C6, 120}, {N_E6, 240}, {N_C6, 240},
    {N_GS4, 120}, {N_C5, 120}, {N_DS5, 120}, {N_GS5, 120},
    {N_C6, 120}, {N_DS6, 240}, {N_C6, 240},
};

typedef enum {
    SFX_JUMP,
    SFX_COIN,
    SFX_STOMP,
    SFX_BRICK,
    SFX_POWERUP,
    SFX_1UP,
    SFX_DEATH,
    SFX_PAUSE,
    SFX_WIN,
} SfxId;

typedef struct {
    const Note* notes;
    int len;
} Track;

static const Track sfx_tracks[] = {
    { sfx_jump,    sizeof(sfx_jump)/sizeof(Note) },
    { sfx_coin,    sizeof(sfx_coin)/sizeof(Note) },
    { sfx_stomp,   sizeof(sfx_stomp)/sizeof(Note) },
    { sfx_brick,   sizeof(sfx_brick)/sizeof(Note) },
    { sfx_powerup, sizeof(sfx_powerup)/sizeof(Note) },
    { sfx_1up,     sizeof(sfx_1up)/sizeof(Note) },
    { sfx_death,   sizeof(sfx_death)/sizeof(Note) },
    { sfx_pause,   sizeof(sfx_pause)/sizeof(Note) },
    { sfx_win,     sizeof(sfx_win)/sizeof(Note) },
};

typedef struct {
    bool     owned;          // do we currently hold the speaker?
    bool     enabled;        // sound output enabled at all
    float    music_volume;   // 0.0..1.0
    float    sfx_volume;     // 0.0..1.0

    // Current playing voice
    const Note* track;
    int      track_len;
    int      idx;
    uint32_t note_end_ms;

    // Background music (looped) - resumed after SFX
    const Note* music;
    int      music_len;
    int      music_idx;
    bool     in_sfx;

    uint16_t last_freq;
} Sound;

static inline void sound_init(Sound* s) {
    memset(s, 0, sizeof(*s));
    s->enabled = true;
    s->music_volume = 1.0f;
    s->sfx_volume = 1.0f;
}

static inline void sound_acquire(Sound* s) {
    if(!s->enabled || s->owned) return;
    if(furi_hal_speaker_is_mine() || furi_hal_speaker_acquire(30)) s->owned = true;
}

static inline void sound_release(Sound* s) {
    if(!s->owned) return;
    furi_hal_speaker_stop();
    if(furi_hal_speaker_is_mine()) furi_hal_speaker_release();
    s->owned = false;
    s->last_freq = 0;
}

static inline void sound_play_freq(Sound* s, uint16_t f) {
    if(!s->owned) return;
    if(f == 0) {
        if(s->last_freq != 0) furi_hal_speaker_stop();
    } else if(f == s->last_freq) {
        // Same pitch as previous note - articulate so two adjacent same-
        // pitch notes are heard as two hits, not one sustained buzz.
        furi_hal_speaker_stop();
        furi_hal_speaker_start((float)f, s->in_sfx ? s->sfx_volume : s->music_volume);
    } else {
        // Different pitch - just retune without stopping. Avoids the click
        // a stop+start would produce on every note boundary.
        furi_hal_speaker_start((float)f, s->in_sfx ? s->sfx_volume : s->music_volume);
    }
    s->last_freq = f;
}

static inline void sound_set_music(Sound* s, const Note* notes, int len) {
    s->music = notes;
    s->music_len = len;
    s->music_idx = 0;
    if(!s->in_sfx) {
        s->track = notes;
        s->track_len = len;
        s->idx = 0;
        s->note_end_ms = 0;
    }
}

static inline void sound_stop_music(Sound* s) {
    s->music = NULL;
    s->music_len = 0;
    if(!s->in_sfx) {
        s->track = NULL;
        s->track_len = 0;
        sound_play_freq(s, 0);
    }
}

static inline void sound_play_sfx(Sound* s, SfxId id) {
    if(id >= sizeof(sfx_tracks)/sizeof(sfx_tracks[0])) return;
    sound_acquire(s);
    s->in_sfx = true;
    s->track = sfx_tracks[id].notes;
    s->track_len = sfx_tracks[id].len;
    s->idx = 0;
    s->note_end_ms = 0;
}

// Advance sequencer; pass milliseconds since boot (furi_get_tick / ms_per_tick).
static inline void sound_tick(Sound* s, uint32_t now_ms) {
    if(!s->enabled) return;
    sound_acquire(s);
    if(!s->owned) return;

    if(s->track == NULL || s->track_len == 0) {
        sound_play_freq(s, 0);
        return;
    }
    if(now_ms < s->note_end_ms) return;

    if(s->idx >= s->track_len) {
        if(s->in_sfx) {
            // SFX done -> resume music if any
            s->in_sfx = false;
            s->track = s->music;
            s->track_len = s->music_len;
            s->idx = s->music_idx;
            if(s->track == NULL) {
                sound_play_freq(s, 0);
                return;
            }
        } else {
            // loop music
            s->idx = 0;
        }
    }

    Note n = s->track[s->idx];
    sound_play_freq(s, n.freq);
    s->note_end_ms = now_ms + n.ms;
    s->idx++;
    if(!s->in_sfx) s->music_idx = s->idx;
}
