// Flipper Zero side-scrolling Mario.
//
// Game logic was hand-ported from the SMB1 disassembly in ./smw/smb1/ - the
// physics constants, jump/friction model, enemy state IDs, and level 1-1
// object stream all come from that source, restructured for a 128x64
// monochrome screen and a tiny RAM budget.
//
// The SNES decompilation emulates the 6502/PPU/OAM/SPC stack and can't be
// compiled directly here; what is ported is the gameplay model.

#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>
#include <string.h>

#include "sprites.h"
#include "level_format.h"
#include "level_1_1.h"
#include "level_1_2.h"
#include "level_1_3.h"
#include "level_1_4.h"
#include "level_2_1.h"
#include "level_2_2.h"
#include "level_2_3.h"
#include "level_2_4.h"
#include "level_3_1.h"
#include "level_3_2.h"
#include "level_3_3.h"
#include "level_3_4.h"
#include "level_4_1.h"
#include "level_4_2.h"
#include "level_4_3.h"
#include "level_4_4.h"
#include "level_5_1.h"
#include "level_5_2.h"
#include "level_5_3.h"
#include "level_5_4.h"
#include "level_6_1.h"
#include "level_6_2.h"
#include "level_6_3.h"
#include "level_6_4.h"
#include "level_7_1.h"
#include "level_7_2.h"
#include "level_7_3.h"
#include "level_7_4.h"
#include "level_8_1.h"
#include "level_8_2.h"
#include "level_8_3.h"
#include "level_8_4.h"
#include "sound.h"

// Runtime tile grid (one definition for the whole app).
uint8_t level_grid[LEVEL_H][LEVEL_W];

// Level registry. All 32 SMB1 levels are listed in play order.
// SMB1 timer: 400 for normal levels, 300 for castle (X-4) levels.
static const Level levels[] = {
    { "1-1", 400, level_1_1_src, LEVEL_1_1_ENEMY_COUNT, enemy_spawns_1_1 },
    { "1-2", 400, level_1_2_src, LEVEL_1_2_ENEMY_COUNT, enemy_spawns_1_2 },
    { "1-3", 300, level_1_3_src, LEVEL_1_3_ENEMY_COUNT, enemy_spawns_1_3 },
    { "1-4", 300, level_1_4_src, LEVEL_1_4_ENEMY_COUNT, enemy_spawns_1_4 },
    { "2-1", 400, level_2_1_src, LEVEL_2_1_ENEMY_COUNT, enemy_spawns_2_1 },
    { "2-2", 400, level_2_2_src, LEVEL_2_2_ENEMY_COUNT, enemy_spawns_2_2 },
    { "2-3", 300, level_2_3_src, LEVEL_2_3_ENEMY_COUNT, enemy_spawns_2_3 },
    { "2-4", 300, level_2_4_src, LEVEL_2_4_ENEMY_COUNT, enemy_spawns_2_4 },
    { "3-1", 400, level_3_1_src, LEVEL_3_1_ENEMY_COUNT, enemy_spawns_3_1 },
    { "3-2", 400, level_3_2_src, LEVEL_3_2_ENEMY_COUNT, enemy_spawns_3_2 },
    { "3-3", 300, level_3_3_src, LEVEL_3_3_ENEMY_COUNT, enemy_spawns_3_3 },
    { "3-4", 300, level_3_4_src, LEVEL_3_4_ENEMY_COUNT, enemy_spawns_3_4 },
    { "4-1", 400, level_4_1_src, LEVEL_4_1_ENEMY_COUNT, enemy_spawns_4_1 },
    { "4-2", 400, level_4_2_src, LEVEL_4_2_ENEMY_COUNT, enemy_spawns_4_2 },
    { "4-3", 300, level_4_3_src, LEVEL_4_3_ENEMY_COUNT, enemy_spawns_4_3 },
    { "4-4", 300, level_4_4_src, LEVEL_4_4_ENEMY_COUNT, enemy_spawns_4_4 },
    { "5-1", 400, level_5_1_src, LEVEL_5_1_ENEMY_COUNT, enemy_spawns_5_1 },
    { "5-2", 400, level_5_2_src, LEVEL_5_2_ENEMY_COUNT, enemy_spawns_5_2 },
    { "5-3", 300, level_5_3_src, LEVEL_5_3_ENEMY_COUNT, enemy_spawns_5_3 },
    { "5-4", 300, level_5_4_src, LEVEL_5_4_ENEMY_COUNT, enemy_spawns_5_4 },
    { "6-1", 400, level_6_1_src, LEVEL_6_1_ENEMY_COUNT, enemy_spawns_6_1 },
    { "6-2", 400, level_6_2_src, LEVEL_6_2_ENEMY_COUNT, enemy_spawns_6_2 },
    { "6-3", 300, level_6_3_src, LEVEL_6_3_ENEMY_COUNT, enemy_spawns_6_3 },
    { "6-4", 300, level_6_4_src, LEVEL_6_4_ENEMY_COUNT, enemy_spawns_6_4 },
    { "7-1", 400, level_7_1_src, LEVEL_7_1_ENEMY_COUNT, enemy_spawns_7_1 },
    { "7-2", 400, level_7_2_src, LEVEL_7_2_ENEMY_COUNT, enemy_spawns_7_2 },
    { "7-3", 300, level_7_3_src, LEVEL_7_3_ENEMY_COUNT, enemy_spawns_7_3 },
    { "7-4", 300, level_7_4_src, LEVEL_7_4_ENEMY_COUNT, enemy_spawns_7_4 },
    { "8-1", 400, level_8_1_src, LEVEL_8_1_ENEMY_COUNT, enemy_spawns_8_1 },
    { "8-2", 400, level_8_2_src, LEVEL_8_2_ENEMY_COUNT, enemy_spawns_8_2 },
    { "8-3", 300, level_8_3_src, LEVEL_8_3_ENEMY_COUNT, enemy_spawns_8_3 },
    { "8-4", 300, level_8_4_src, LEVEL_8_4_ENEMY_COUNT, enemy_spawns_8_4 },
};
#define NUM_LEVELS ((int)(sizeof(levels) / sizeof(Level)))

// Forward-declared SFX trigger; the App struct and g_app pointer are defined
// further down. Game logic above calls this freely.
static void sfx(SfxId id);
struct Game;
static void load_level(struct Game* g, uint8_t idx);  // implemented below

// --- Screen / world geometry -----------------------------------------------
#define SCREEN_W 128
#define SCREEN_H 64
#define TILE     8
#define VIEW_TILES_W (SCREEN_W / TILE) // 16
#define VIEW_TILES_H (SCREEN_H / TILE) // 8

#define SUBPX 16   // sub-pixels per pixel (matches SMB1 16-step subpos)
// Floor division by SUBPX: arithmetic right shift rounds toward -inf, so a
// position of -10 subpx maps to pixel -1 (not 0 like C's truncating division).
#define SUB_TO_PX(s) ((int16_t)((int16_t)(s) >> 4))

// --- Player / physics tunables (derived from SMB1's tables) ----------------
// SMB1 runs at 60 fps on a 256-wide playfield. The Flipper screen is 128 px
// wide and we run at 50 fps, so for the game to *look* like SMB1 plays on a
// CRT, on-screen px/sec should be ~half SMB1's number (the world is half as
// wide per unit of player view). No run/dash button - movement is just walk.
#define MAX_WALK_SPEED   18   // 18/16 px/f * 50 fps = ~56 px/s
#define MAX_RUN_SPEED    32   // sprint mode after double-tapping a direction
#define ACCEL_WALK        2
#define ACCEL_RUN         3
#define FRICTION_GROUND   1
#define FRICTION_AIR      1

#define DBL_TAP_WINDOW   12   // frames (~240 ms at 50 fps)

#define JUMP_VEL_BASE   (-42)  // tap jump apex ~1.5 tiles, held ~3 tiles
#define GRAV_HOLD         2    // gravity while jump held and rising
#define GRAV_NORMAL       4    // gravity otherwise (fast-fall after release)
#define MAX_FALL_SPEED   90

#define JUMP_BUFFER_FRAMES  6  // press registered up to this many frames early
#define COYOTE_FRAMES       5  // grace window after walking off a ledge

#define PLAYER_W      8
#define PLAYER_H_S    8     // small
#define PLAYER_H_B    16    // big

// --- Enemy types -----------------------------------------------------------
typedef enum {
    E_NONE = 0,
    E_GOOMBA,
    E_KOOPA,
    E_SHELL,
    E_MUSHROOM,
    E_COIN_POP,
} EnemyType;

typedef struct {
    EnemyType type;
    int16_t   x, y;      // subpixel
    int16_t   vx, vy;    // subpixel/frame
    uint8_t   dir;       // 0=left, 1=right
    uint8_t   state;     // 0 alive/moving, 1 squished, 2 shell still, 3 shell sliding
    uint8_t   timer;
    uint8_t   spawn_idx; // which spawn slot this came from, 0xFF for ad-hoc
} Enemy;

#define MAX_ENEMIES 8

// --- Game state ------------------------------------------------------------
typedef enum {
    SCENE_TITLE = 0,
    SCENE_PLAY,
    SCENE_GAMEOVER,
    SCENE_WIN,
} Scene;

typedef struct Game {
    Scene scene;
    uint32_t frame;

    // Player
    int16_t px, py;        // subpixel top-left
    int16_t pvx, pvy;
    uint8_t pdir;          // 0 left, 1 right
    uint8_t pbig;          // 0 small, 1 big
    uint8_t pgrounded;
    uint8_t pjump_held;
    uint8_t pwalk_anim;
    uint8_t pinvuln;       // frames of invulnerability after taking hit
    uint8_t pdead;         // death animation timer
    uint8_t pjump_buffer;  // frames remaining where a press will trigger a jump
    uint8_t pcoyote;       // frames remaining where leaving ground still allows jump
    uint8_t pcrouching;    // 1 if big Mario is crouching (down-arrow held)
    uint8_t level_clear_timer; // counts down while win SFX plays; 0 = play next level
    uint8_t btn_held_prev; // for detecting key release edges
    uint8_t dbl_tap_left;  // frames remaining in re-press window after LEFT release
    uint8_t dbl_tap_right; // same for RIGHT
    uint8_t sprinting;     // 1 while a direction is held after a double-tap

    // Camera (in pixels, left edge of viewport in world coords)
    int16_t cam_x;

    // Enemies. spawned[] is sized for the largest known spawn list across
    // all levels; per-level count is in levels[current_level_idx].spawn_count.
    Enemy enemies[MAX_ENEMIES];
    uint8_t spawned[64];
    uint8_t current_level_idx;

    // HUD
    uint16_t score;
    uint8_t  lives;
    uint16_t coins;
    uint16_t timer_seconds;
    uint8_t  timer_subframe;

    // Input mask (bit per InputKey)
    uint8_t  btn_held;
    uint8_t  btn_pressed; // edge-triggered, cleared each frame after consumption

    // UI state

    // Settings
    bool     music_on;
    bool     sfx_on;
    uint8_t  gameover_timer;    // counts up; auto-returns to menu when full
} Game;

// InputKey bits
#define BIT_UP    (1 << InputKeyUp)
#define BIT_DOWN  (1 << InputKeyDown)
#define BIT_LEFT  (1 << InputKeyLeft)
#define BIT_RIGHT (1 << InputKeyRight)
#define BIT_OK    (1 << InputKeyOk)
#define BIT_BACK  (1 << InputKeyBack)

// --- Level helpers ---------------------------------------------------------
static inline uint8_t world_tile(int16_t tx, int16_t ty) {
    if(tx < 0 || tx >= LEVEL_W) return T_GROUND; // walls at edges
    if(ty < 0) return T_AIR;
    if(ty >= LEVEL_H) return T_AIR;              // bottomless pit
    return level_grid[ty][tx];
}

static inline void world_set(int16_t tx, int16_t ty, uint8_t v) {
    if(tx < 0 || tx >= LEVEL_W || ty < 0 || ty >= LEVEL_H) return;
    level_grid[ty][tx] = v;
}

// --- Collision -------------------------------------------------------------
// Resolve axis-aligned collision against tile grid. Returns true if the move
// hit something solid; updates pos in-place to the clamped value.
typedef struct { int16_t x, y, w, h; } AABB;

static bool solid_at_px(int16_t px, int16_t py) {
    return tile_is_solid(world_tile(px / TILE, py / TILE));
}

// Move an AABB along x by dx pixels, clamping at solid tiles.
static bool move_x(int16_t* x, int16_t y, int16_t w, int16_t h, int16_t dx) {
    if(dx == 0) return false;
    int16_t step = dx > 0 ? 1 : -1;
    int16_t n = dx > 0 ? dx : -dx;
    for(int16_t i = 0; i < n; i++) {
        int16_t nx = *x + step;
        int16_t probe_x = step > 0 ? nx + w - 1 : nx;
        bool blocked = false;
        for(int16_t py = y; py < y + h; py += TILE) {
            if(solid_at_px(probe_x, py)) { blocked = true; break; }
        }
        if(!blocked && solid_at_px(step > 0 ? nx + w - 1 : nx, y + h - 1)) blocked = true;
        if(blocked) return true;
        *x = nx;
    }
    return false;
}

static bool move_y(int16_t x, int16_t* y, int16_t w, int16_t h, int16_t dy) {
    if(dy == 0) return false;
    int16_t step = dy > 0 ? 1 : -1;
    int16_t n = dy > 0 ? dy : -dy;
    for(int16_t i = 0; i < n; i++) {
        int16_t ny = *y + step;
        int16_t probe_y = step > 0 ? ny + h - 1 : ny;
        bool blocked = false;
        for(int16_t px = x; px < x + w; px += TILE) {
            if(solid_at_px(px, probe_y)) { blocked = true; break; }
        }
        if(!blocked && solid_at_px(x + w - 1, probe_y)) blocked = true;
        if(blocked) return true;
        *y = ny;
    }
    return false;
}

// --- Enemies ---------------------------------------------------------------
static Enemy* spawn_enemy(Game* g, EnemyType type, int16_t x_px, int16_t y_px) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(g->enemies[i].type == E_NONE) {
            Enemy* e = &g->enemies[i];
            e->type = type;
            e->x = (int16_t)(x_px * SUBPX);
            e->y = (int16_t)(y_px * SUBPX);
            // SMB1 kNormalXSpdData at 60 fps -> ~0.5 px/f; 50 fps equiv ~0.6.
            // Mushroom slides right at constant speed in SMB1.
            switch(type) {
            // SMB1: both goomba and red koopa init via NormalEnemy_Init and
            // share the same kNormalXSpdData entry.
            case E_GOOMBA:   e->vx = -10; break;
            case E_KOOPA:    e->vx = -10; break;
            case E_MUSHROOM: e->vx =  16; break;
            default:         e->vx =   0; break;
            }
            e->vy = 0;
            e->dir = 0;
            e->state = 0;
            e->timer = 0;
            e->spawn_idx = 0xFF;
            return e;
        }
    }
    return NULL;
}

static void check_spawns(Game* g) {
    int16_t cam_right = g->cam_x + SCREEN_W + 16;
    int16_t cam_left  = g->cam_x - 24;
    const Level* lvl = &levels[g->current_level_idx];
    for(int i = 0; i < lvl->spawn_count; i++) {
        if(g->spawned[i]) continue;
        int16_t sx = lvl->spawns[i].spawn_x;
        if(sx > cam_left && sx < cam_right) {
            EnemyType t = lvl->spawns[i].type == 1 ? E_KOOPA : E_GOOMBA;
            Enemy* e = spawn_enemy(g, t, sx, lvl->spawns[i].y);
            if(e) {
                e->spawn_idx = i;
                g->spawned[i] = 1;
            }
        }
    }
    // Despawn enemies that fell offscreen far behind camera
    for(int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* e = &g->enemies[i];
        if(e->type == E_NONE) continue;
        int16_t ex = e->x / SUBPX;
        if(ex < g->cam_x - 32 || e->y / SUBPX > SCREEN_H + 64) {
            e->type = E_NONE;
        }
    }
}

static void update_enemy(Game* g, Enemy* e) {
    if(e->type == E_NONE) return;
    if(e->state == 1) { // squished
        if(++e->timer > 16) e->type = E_NONE;
        return;
    }

    e->vy += GRAV_NORMAL;
    if(e->vy > MAX_FALL_SPEED) e->vy = MAX_FALL_SPEED;

    int16_t x_px = SUB_TO_PX(e->x);
    int16_t y_px = SUB_TO_PX(e->y);
    int16_t dx = SUB_TO_PX(e->x + e->vx) - x_px;
    int16_t dy = SUB_TO_PX(e->y + e->vy) - y_px;

    int16_t w = 8, h = 8;
    int16_t nx = x_px, ny = y_px;

    bool hit_x = move_x(&nx, y_px, w, h, dx);
    if(hit_x) {
        e->vx = -e->vx;
        e->dir ^= 1;
    }
    bool hit_y = move_y(nx, &ny, w, h, dy);
    if(hit_y) e->vy = 0;

    // Red-koopa ledge turn (SMB1 RedKoopa behavior). Mushroom slides past
    // ledges in SMB1 - falls and keeps going. Goombas fall off.
    if(e->type == E_KOOPA && hit_y) {
        int16_t lead = (e->vx < 0) ? nx : (nx + w - 1);
        if(!solid_at_px(lead, ny + h)) {
            e->vx = -e->vx;
            e->dir ^= 1;
        }
    }

    // Sliding shell kills other enemies it collides with (SMB1 shell chain).
    if(e->type == E_SHELL && e->state == 3) {
        for(int i = 0; i < MAX_ENEMIES; i++) {
            Enemy* o = &g->enemies[i];
            if(o == e || o->type == E_NONE || o->state == 1) continue;
            if(o->type == E_MUSHROOM) continue;
            int16_t ox = SUB_TO_PX(o->x);
            int16_t oy = SUB_TO_PX(o->y);
            if(nx + w <= ox || ox + 8 <= nx) continue;
            if(ny + h <= oy || oy + 8 <= ny) continue;
            if(o->type == E_SHELL) {
                e->type = E_NONE;
                o->type = E_NONE;
            } else {
                o->state = 1; o->vx = 0; o->timer = 0;
                g->score += 200;
            }
        }
    }

    e->x = hit_x ? (int16_t)(nx * SUBPX) : (int16_t)(e->x + e->vx);
    e->y = hit_y ? (int16_t)(ny * SUBPX) : (int16_t)(e->y + e->vy);

    if(ny > SCREEN_H + 32) e->type = E_NONE;
}

// --- Player update ---------------------------------------------------------
// Mirrors SMB1's PlayerPhysicsSub: pick target speed, apply friction toward
// it, then variable-gravity jump that switches to faster gravity when A is
// released.
static void player_update(Game* g) {
    if(g->pdead) {
        if(g->pdead == 1) {
            g->pvy = -100; g->pvx = 0;
            sfx(SFX_DEATH);
        }
        g->pdead++;
        g->pvy += GRAV_NORMAL;
        if(g->pvy > MAX_FALL_SPEED) g->pvy = MAX_FALL_SPEED;
        g->py += g->pvy;
        if(g->pdead > 60) {
            if(g->lives == 0) {
                g->scene = SCENE_GAMEOVER;
            } else {
                g->lives--;
                // SMB1: any death (pit fall, timer-out, hit-while-small)
                // resets the player to small. Big Mario only persists across
                // shrink-on-hit, not across actual death.
                g->pbig = 0;
                g->pcrouching = 0;
                load_level(g, g->current_level_idx);
                g->pdead = 0;
                g->pinvuln = 60;
            }
        }
        return;
    }

    uint8_t held = g->btn_held;
    uint8_t pressed = g->btn_pressed;
    uint8_t releases = g->btn_held_prev & ~held;  // edge: held last frame, not now
    g->btn_held_prev = held;
    bool left  = held & BIT_LEFT;
    bool right = held & BIT_RIGHT;
    bool down  = held & BIT_DOWN;
    bool jump_held = held & BIT_BACK;
    bool jump_just = pressed & BIT_BACK;

    // Double-tap-to-sprint (Minecraft-style). After releasing LEFT/RIGHT, a
    // re-press of the SAME direction within DBL_TAP_WINDOW frames enters
    // sprint mode. Sprint persists while the direction is held; releasing
    // the direction exits sprint.
    if(releases & BIT_LEFT)  { g->dbl_tap_left  = DBL_TAP_WINDOW;
        if(g->sprinting && g->pdir == 0) g->sprinting = 0; }
    if(releases & BIT_RIGHT) { g->dbl_tap_right = DBL_TAP_WINDOW;
        if(g->sprinting && g->pdir == 1) g->sprinting = 0; }
    if((pressed & BIT_LEFT)  && g->dbl_tap_left)  { g->sprinting = 1; g->dbl_tap_left  = 0; }
    if((pressed & BIT_RIGHT) && g->dbl_tap_right) { g->sprinting = 1; g->dbl_tap_right = 0; }
    if(g->dbl_tap_left)  g->dbl_tap_left--;
    if(g->dbl_tap_right) g->dbl_tap_right--;
    // Switching directions cancels sprint immediately.
    if(g->sprinting && !left && !right) g->sprinting = 0;

    // Crouching (big Mario only). On enter: shift py DOWN by 8 px so the
    // head pulls down to shoulder level and feet stay planted. On exit:
    // shift py back UP, but only if the row above the small hitbox is air
    // (otherwise we'd clip into a ceiling).
    if(g->pbig && down && g->pgrounded && !g->pcrouching) {
        g->pcrouching = 1;
        g->py += 8 * SUBPX;
    } else if(g->pcrouching && (!down || !g->pbig)) {
        int16_t hx = SUB_TO_PX(g->px);
        int16_t hy_new = SUB_TO_PX(g->py) - 8;
        if(!solid_at_px(hx, hy_new) && !solid_at_px(hx + PLAYER_W - 1, hy_new)) {
            g->pcrouching = 0;
            g->py -= 8 * SUBPX;
        }
    }
    if(!g->pbig) g->pcrouching = 0;

    // Horizontal input -> target velocity. Skid: double accel when input is
    // opposite to current motion on ground. Air with no input preserves
    // momentum (no air friction - matches SMB1).
    int16_t max_speed = g->sprinting ? MAX_RUN_SPEED : MAX_WALK_SPEED;
    int16_t accel = g->sprinting ? ACCEL_RUN : ACCEL_WALK;
    if(left && !right) {
        int16_t a = (g->pvx > 0 && g->pgrounded) ? accel * 2 : accel;
        g->pvx -= a;
        if(g->pvx < -max_speed) g->pvx = -max_speed;
        g->pdir = 0;
    } else if(right && !left) {
        int16_t a = (g->pvx < 0 && g->pgrounded) ? accel * 2 : accel;
        g->pvx += a;
        if(g->pvx > max_speed) g->pvx = max_speed;
        g->pdir = 1;
    } else if(g->pgrounded) {
        if(g->pvx > 0) { g->pvx -= FRICTION_GROUND; if(g->pvx < 0) g->pvx = 0; }
        else if(g->pvx < 0) { g->pvx += FRICTION_GROUND; if(g->pvx > 0) g->pvx = 0; }
    }

    // Jump = SMB1's PlayerPhysicsSub jump branch: edge-triggered (must release
    // between jumps), variable height while jump is held during ascent
    // ("diff_to_halt_jump"). Jump buffer lets a slightly-early press still
    // fire on landing; coyote time lets a press just after a ledge still fire.
    if(jump_just) g->pjump_buffer = JUMP_BUFFER_FRAMES;
    bool can_jump = g->pgrounded || g->pcoyote > 0;
    if(g->pjump_buffer && can_jump && !g->pjump_held) {
        g->pvy = JUMP_VEL_BASE;
        g->pgrounded = 0;
        g->pcoyote = 0;
        g->pjump_buffer = 0;
        g->pjump_held = 1;
        sfx(SFX_JUMP);
    } else {
        if(g->pjump_buffer) g->pjump_buffer--;
        if(!jump_held) g->pjump_held = 0;
    }

    // Variable-height gravity: light while ascending and still holding jump.
    int16_t grav = (jump_held && g->pvy < 0) ? GRAV_HOLD : GRAV_NORMAL;
    g->pvy += grav;
    if(g->pvy > MAX_FALL_SPEED) g->pvy = MAX_FALL_SPEED;

    // Move with collision. Subpixel position is preserved across frames when
    // the move is unblocked - if we wrote back nx*SUBPX every frame, any
    // velocity below 16 sub/f would be silently lost and the entity would
    // freeze against walls.
    int16_t w = PLAYER_W;
    // Hitbox height: big = 16, big-crouching = 8 (py was already shifted on
    // crouch toggle so feet stay where they were), small = 8.
    int16_t h = (g->pbig && !g->pcrouching) ? PLAYER_H_B : PLAYER_H_S;

    int16_t x_px = SUB_TO_PX(g->px);
    int16_t y_px = SUB_TO_PX(g->py);
    int16_t want_px_x = SUB_TO_PX(g->px + g->pvx);
    int16_t want_px_y = SUB_TO_PX(g->py + g->pvy);
    int16_t dx = want_px_x - x_px;
    int16_t dy = want_px_y - y_px;

    int16_t nx = x_px, ny = y_px;
    bool hit_x = move_x(&nx, y_px, w, h, dx);
    if(hit_x) g->pvx = 0;
    bool hit_y = move_y(nx, &ny, w, h, dy);
    if(hit_y) {
        if(g->pvy < 0) {
            // Hit head on a block - check tile directly above
            int16_t tx_left = nx / TILE;
            int16_t tx_right = (nx + w - 1) / TILE;
            int16_t ty = (ny - 1) / TILE;
            for(int16_t tx = tx_left; tx <= tx_right; tx++) {
                uint8_t t = world_tile(tx, ty);
                if(tile_is_hittable(t)) {
                    if(t == T_QBLOCK) {
                        world_set(tx, ty, T_USED);
                        g->coins++;
                        if(g->coins >= 100) { g->coins = 0; g->lives++; sfx(SFX_1UP); }
                        else sfx(SFX_COIN);
                        g->score += 200;
                    } else if(t == T_QPOWER) {
                        world_set(tx, ty, T_USED);
                        spawn_enemy(g, E_MUSHROOM, tx * TILE, ty * TILE - 8);
                        sfx(SFX_POWERUP);
                    } else if(t == T_BRICK) {
                        if(g->pbig) {
                            world_set(tx, ty, T_AIR);
                            g->score += 50;
                            sfx(SFX_BRICK);
                        } else {
                            sfx(SFX_BRICK);
                        }
                    }
                }
            }
            g->pvy = 0;
        } else {
            if(!g->pgrounded) g->pjump_held = 0; // landed - allow next jump
            g->pgrounded = 1;
            g->pcoyote = COYOTE_FRAMES;
        }
        g->pvy = 0;
    } else {
        g->pgrounded = 0;
    }

    // Write back: if blocked on an axis, snap to the integer-pixel boundary
    // we reached; otherwise keep the sub-pixel accumulator.
    g->px = hit_x ? (int16_t)(nx * SUBPX) : (int16_t)(g->px + g->pvx);
    g->py = hit_y ? (int16_t)(ny * SUBPX) : (int16_t)(g->py + g->pvy);

    // Ground re-check: are we standing on something?
    if(g->pgrounded) {
        if(!solid_at_px(nx + 1, ny + h) && !solid_at_px(nx + w - 2, ny + h)) {
            g->pgrounded = 0;
        }
    }
    if(g->pcoyote && !g->pgrounded) g->pcoyote--;

    // Walk-cycle anim: alternate between two distinct walking poses. Frame
    // swap every ~4 ticks at 50 fps so a full cycle is ~8 frames = 160 ms
    // = ~6 steps/sec.
    if(g->pgrounded && (g->pvx > 2 || g->pvx < -2)) {
        if((g->frame & 3) == 0) g->pwalk_anim++;
    } else if(g->pgrounded) {
        g->pwalk_anim = 0;
    }

    // Death from falling
    if(ny > SCREEN_H + 32) {
        g->pdead = 1;
        return;
    }

    // Camera: scroll so player stays around 1/3 of screen. Never scroll back.
    int16_t want_cam = (g->px / SUBPX) - SCREEN_W / 3;
    if(want_cam > g->cam_x) g->cam_x = want_cam;
    if(g->cam_x < 0) g->cam_x = 0;
    int16_t max_cam = LEVEL_W * TILE - SCREEN_W;
    if(g->cam_x > max_cam) g->cam_x = max_cam;
    // Don't allow player to walk back past camera left edge.
    if(g->px / SUBPX < g->cam_x) g->px = g->cam_x * SUBPX;

    // Reaching the castle: arm the level-clear timer so the win SFX has
    // time to finish before the next level loads. The actual transition
    // happens in game_step when the timer hits zero.
    if((g->px / SUBPX) > 200 * TILE && !g->level_clear_timer) {
        g->level_clear_timer = 130;  // ~2.6 s at 50 fps - longer than SFX_WIN
        sfx(SFX_WIN);
        g->pvx = 0;  // freeze horizontal motion during the celebration
    }

    if(g->pinvuln) g->pinvuln--;
}

static void player_take_hit(Game* g) {
    if(g->pinvuln) return;
    if(g->pbig) {
        g->pbig = 0;
        // Shrink: feet stay put. Hitbox top (py) drops 8 px so total height
        // halves from 16 to 8 with feet at the same y.
        g->py += 8 * SUBPX;
        g->pcrouching = 0;
        g->pinvuln = 90;
        sfx(SFX_POWERUP);
    } else {
        g->pdead = 1; // SFX played by the death handler in player_update
    }
}

// --- Player vs Enemy collisions --------------------------------------------
static void resolve_pvp(Game* g) {
    int16_t px = g->px / SUBPX;
    int16_t py = g->py / SUBPX;
    int16_t pw = PLAYER_W;
    int16_t ph = (g->pbig && !g->pcrouching) ? PLAYER_H_B : PLAYER_H_S;

    for(int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* e = &g->enemies[i];
        if(e->type == E_NONE || e->state == 1) continue;
        int16_t ex = e->x / SUBPX;
        int16_t ey = e->y / SUBPX;
        if(px + pw <= ex || ex + 8 <= px) continue;
        if(py + ph <= ey || ey + 8 <= py) continue;

        if(e->type == E_MUSHROOM) {
            e->type = E_NONE;
            if(!g->pbig) {
                g->pbig = 1;
                // Grow upward: feet stay on the ground, hitbox top (py) rises
                // 8 px so the head now occupies the row above the old hitbox.
                g->py -= 8 * SUBPX;
            }
            g->score += 1000;
            sfx(SFX_POWERUP);
            continue;
        }

        // SMB1 ChkForPlayerInjury treats any downward player velocity as a
        // stomp on contact, with no proximity restriction.
        bool stomp = (g->pvy > 0);
        if(stomp) {
            // SMB1 awards 100 for goomba/koopa stomp; shells award 400
            // only when transitioning idle->sliding (not when stopping one).
            if(e->type == E_GOOMBA) {
                e->state = 1; e->timer = 0; e->vx = 0;
                g->score += 100;
            } else if(e->type == E_KOOPA) {
                e->type = E_SHELL; e->state = 2; e->vx = 0;
                g->score += 100;
            } else if(e->type == E_SHELL) {
                if(e->state == 2) {
                    e->state = 3;
                    e->vx = (px < ex) ? 60 : -60; // ~3 px/f at 50 fps
                    g->score += 400;
                } else {
                    e->vx = 0; e->state = 2;
                }
            }
            // Bounce stronger than a standing jump (SMB1 sets player yspeed
            // to -5 vs jump's -4); held-jump = super bounce.
            g->pvy = (g->btn_held & BIT_BACK) ? -56 : -44;
            sfx(SFX_STOMP);
        } else {
            if(e->type == E_SHELL && e->state == 2) {
                e->state = 3;
                e->vx = (px < ex) ? 60 : -60;
                g->score += 400;
                sfx(SFX_STOMP);
            } else {
                player_take_hit(g);
            }
        }
    }
}

// --- HUD timer -------------------------------------------------------------
static void update_timer(Game* g) {
    if(g->scene != SCENE_PLAY) return;
    // SMB1 RunGameTimer reloads game_paused_timer with 24 frames at 60 fps
    // (~0.40 s per game-sec); scaled to 20 frames at 50 fps for the same wall
    // time per game-second.
    if(++g->timer_subframe >= 20) {
        g->timer_subframe = 0;
        if(g->timer_seconds > 0) g->timer_seconds--;
        else if(!g->pdead) g->pdead = 1;
    }
}

// --- Tile/sprite renderer --------------------------------------------------
static const uint8_t* tile_sprite(uint8_t t) {
    switch(t) {
    case T_GROUND:   return spr_ground;
    case T_BRICK:    return spr_brick;
    case T_QBLOCK:   return spr_qblock;
    case T_QPOWER:   return spr_qblock;
    case T_USED:     return spr_used_block;
    case T_PIPETL:   return spr_pipe_topL;
    case T_PIPETR:   return spr_pipe_topR;
    case T_PIPEBL:   return spr_pipe_bodyL;
    case T_PIPEBR:   return spr_pipe_bodyR;
    case T_COIN:     return spr_coin;
    case T_CLOUD:    return spr_cloud;
    case T_BUSH:     return spr_bush;
    case T_FLAGTOP:  return spr_flagtop;
    case T_FLAGPOLE: return spr_flagpole;
    case T_CASTLE:   return spr_castle;
    default:         return NULL;
    }
}

// Draw an 8-wide 1bpp sprite of `h` rows at pixel (sx,sy) in screen coords.
static void draw_sprite_h(Canvas* c, int16_t sx, int16_t sy, const uint8_t* spr, int h) {
    for(int row = 0; row < h; row++) {
        uint8_t bits = spr[row];
        int16_t y = sy + row;
        if(y < 0 || y >= SCREEN_H) continue;
        for(int col = 0; col < 8; col++) {
            if(bits & (0x80 >> col)) {
                int16_t x = sx + col;
                if(x >= 0 && x < SCREEN_W) canvas_draw_dot(c, x, y);
            }
        }
    }
}

static void draw_sprite_flip_h(Canvas* c, int16_t sx, int16_t sy, const uint8_t* spr, int h, bool flip) {
    for(int row = 0; row < h; row++) {
        uint8_t bits = spr[row];
        int16_t y = sy + row;
        if(y < 0 || y >= SCREEN_H) continue;
        for(int col = 0; col < 8; col++) {
            int bit = flip ? col : (7 - col);
            if(bits & (1 << bit)) {
                int16_t x = sx + col;
                if(x >= 0 && x < SCREEN_W) canvas_draw_dot(c, x, y);
            }
        }
    }
}

static inline void draw_sprite(Canvas* c, int16_t sx, int16_t sy, const uint8_t spr[8]) {
    draw_sprite_h(c, sx, sy, spr, 8);
}

// --- Rendering -------------------------------------------------------------
static void draw_world(Canvas* c, Game* g) {
    int16_t cam_tx = g->cam_x / TILE;
    int16_t cam_ox = g->cam_x % TILE;
    for(int ty = 0; ty < LEVEL_H; ty++) {
        for(int dx = 0; dx <= VIEW_TILES_W; dx++) {
            int tx = cam_tx + dx;
            if(tx < 0 || tx >= LEVEL_W) continue;
            uint8_t t = level_grid[ty][tx];
            const uint8_t* spr = tile_sprite(t);
            if(spr) draw_sprite(c, dx * TILE - cam_ox, ty * TILE, spr);
        }
    }
}

static void draw_player(Canvas* c, Game* g) {
    if(g->pinvuln && (g->frame & 2)) return; // flicker
    int16_t sx = SUB_TO_PX(g->px) - g->cam_x;
    int16_t sy = SUB_TO_PX(g->py);
    bool flip = (g->pdir == 0);
    const uint8_t* body;
    if(!g->pgrounded) {
        body = spr_mario_jump;
    } else if(g->pvx == 0) {
        body = spr_mario_stand;
    } else {
        // Alternate between two distinct walking poses each animation tick.
        body = (g->pwalk_anim & 1) ? spr_mario_walk2 : spr_mario_walk;
    }
    if(g->pbig && g->pcrouching) {
        // Crouched: only draw the lower half (squat pose). py was shifted on
        // crouch toggle so sy is already at the crouched head position.
        draw_sprite_flip_h(c, sx, sy, spr_mario_big_bot, 8, flip);
    } else if(g->pbig) {
        draw_sprite_flip_h(c, sx, sy, spr_mario_big_top, 8, flip);
        draw_sprite_flip_h(c, sx, sy + 8, spr_mario_big_bot, 8, flip);
    } else {
        draw_sprite_flip_h(c, sx, sy, body, 8, flip);
    }
}

static void draw_enemies(Canvas* c, Game* g) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        Enemy* e = &g->enemies[i];
        if(e->type == E_NONE) continue;
        int16_t sx = e->x / SUBPX - g->cam_x;
        int16_t sy = e->y / SUBPX;
        const uint8_t* spr;
        if(e->state == 1) spr = spr_goomba_dead;
        else if(e->type == E_GOOMBA) spr = spr_goomba;
        else if(e->type == E_KOOPA) spr = spr_koopa;
        else if(e->type == E_SHELL) spr = spr_shell;
        else if(e->type == E_MUSHROOM) spr = spr_mushroom;
        else continue;
        draw_sprite(c, sx, sy, spr);
    }
}

static void draw_number(Canvas* c, int16_t x, int16_t y, uint32_t v, uint8_t pad) {
    char buf[8];
    snprintf(buf, sizeof(buf), "%0*lu", pad, (unsigned long)v);
    canvas_draw_str(c, x, y, buf);
}

static void draw_hud(Canvas* c, Game* g) {
    canvas_set_font(c, FontSecondary);
    char line[24];
    snprintf(line, sizeof(line), "%06lu  x%u", (unsigned long)g->score, g->lives);
    canvas_draw_str(c, 1, 7, line);
    snprintf(line, sizeof(line), "C:%02u T:%03u", g->coins, g->timer_seconds);
    canvas_draw_str(c, 70, 7, line);
    (void)draw_number;
}

static void draw_centered(Canvas* c, int16_t y, const char* s) {
    canvas_set_font(c, FontPrimary);
    int16_t w = canvas_string_width(c, s);
    canvas_draw_str(c, (SCREEN_W - w) / 2, y, s);
}

static void render(Canvas* canvas, void* ctx);

// --- App container (defined here so game_step can reach g_app->sound) ------
typedef struct App {
    Game game;
    Sound sound;
    FuriMessageQueue* events;
    FuriMutex* mutex;
    bool running;
} App;

static App* g_app = NULL;
static void sfx(SfxId id) {
    if(!g_app) return;
    sound_play_sfx(&g_app->sound, id);
}




// --- Game lifecycle --------------------------------------------------------
static void load_level(Game* g, uint8_t idx) {
    g->current_level_idx = idx;
    level_compile_from(levels[idx].src);
    g->timer_seconds = levels[idx].timer_start;
    g->cam_x = 0;
    g->px = 16 * SUBPX;
    g->py = 40 * SUBPX;
    g->pvx = g->pvy = 0;
    g->pdir = 1;
    memset(g->spawned, 0, sizeof(g->spawned));
    for(int i = 0; i < MAX_ENEMIES; i++) g->enemies[i].type = E_NONE;
}

static void game_init(Game* g) {
    memset(g, 0, sizeof(*g));
    g->scene = SCENE_TITLE;
    g->lives = 3;
    load_level(g, 0);
}

static void game_restart(Game* g) {
    // Preserve user settings + carry-over lives/score across the wipe.
    uint8_t lives = g->lives;
    uint16_t score = g->score;
    memset(g, 0, sizeof(*g));
    g->scene = SCENE_PLAY;
    g->lives = lives ? lives : 3;
    g->score = score;
    load_level(g, 0);  // start over at the first level
    g->scene = SCENE_PLAY;
    g->pdir = 1;
}

static void game_step(Game* g) {
    Scene before = g->scene;
    g->frame++;
switch(g->scene) {
    case SCENE_TITLE:
        if(g->btn_pressed & BIT_OK) game_restart(g);
        break;
    case SCENE_PLAY:
        if(g->level_clear_timer) {
            // Holding for the win jingle. Tick down, then advance.
            if(--g->level_clear_timer == 0) {
                if(g->current_level_idx + 1 < NUM_LEVELS) {
                    load_level(g, g->current_level_idx + 1);
                } else {
                    g->scene = SCENE_WIN;
                }
            }
            break;
        }
        player_update(g);
        if(g->scene != SCENE_PLAY) break;
        check_spawns(g);
        for(int i = 0; i < MAX_ENEMIES; i++) update_enemy(g, &g->enemies[i]);
        resolve_pvp(g);
        update_timer(g);
        break;
    case SCENE_GAMEOVER:
        // Show GAME OVER briefly then go back to the title menu.
        if(g->gameover_timer < 255) g->gameover_timer++;
        if(g->gameover_timer > 100 || (g->btn_pressed & (BIT_OK | BIT_BACK))) {
            g->scene = SCENE_TITLE;
                            g->lives = 3;
            g->score = 0;
            g->coins = 0;
            g->gameover_timer = 0;
        }
        break;
    case SCENE_WIN:
        if(g->btn_pressed & (BIT_OK | BIT_BACK)) {
            g->scene = SCENE_TITLE;
                            g->lives = 3;
            g->score = 0;
            g->coins = 0;
        }
        break;
    }
    if(before == SCENE_PLAY && g->scene != SCENE_PLAY && g_app) {
        sound_stop_music(&g_app->sound);
        if(g->scene == SCENE_WIN) sfx(SFX_WIN);
    }
    g->btn_pressed = 0;
}

// --- App scaffolding (Furi + GUI) ------------------------------------------
static void render(Canvas* canvas, void* ctx) {
    App* app = ctx;
    if(furi_mutex_acquire(app->mutex, 25) != FuriStatusOk) return;
    Game* g = &app->game;
    canvas_clear(canvas);
    switch(g->scene) {
    case SCENE_TITLE:
        canvas_set_font(canvas, FontPrimary);
        draw_centered(canvas, 22, "SUPER MARIO BROS");
        canvas_set_font(canvas, FontSecondary);
        draw_centered(canvas, 38, "Press OK to start");
        break;
    case SCENE_PLAY:
        draw_world(canvas, g);
        draw_enemies(canvas, g);
        draw_player(canvas, g);
        draw_hud(canvas, g);
        break;
    case SCENE_GAMEOVER:
        draw_centered(canvas, 28, "GAME OVER");
        canvas_set_font(canvas, FontSecondary);
        draw_centered(canvas, 42, "Press OK");
        break;
    case SCENE_WIN:
        draw_centered(canvas, 28, "YOU WIN!");
        canvas_set_font(canvas, FontSecondary);
        draw_centered(canvas, 42, "Press OK");
        break;
    }
    if(g->confirm_quit) {
        // Centered modal. Box sized so FontSecondary lines fit with padding.
        const int16_t bw = 100, bh = 40;
        const int16_t bx = (SCREEN_W - bw) / 2;
        const int16_t by = (SCREEN_H - bh) / 2;
        canvas_set_color(canvas, ColorWhite);
        canvas_draw_box(canvas, bx, by, bw, bh);
        canvas_set_color(canvas, ColorBlack);
        canvas_draw_frame(canvas, bx, by, bw, bh);
        canvas_set_font(canvas, FontPrimary);
        draw_centered(canvas, by + 13, "Quit?");
        canvas_set_font(canvas, FontSecondary);
        draw_centered(canvas, by + 24, "OK = yes");
        draw_centered(canvas, by + 34, "Back = no");
    }
    furi_mutex_release(app->mutex);
}

static void input_cb(InputEvent* ev, void* ctx) {
    App* app = ctx;
    furi_message_queue_put(app->events, ev, 0);
}

int32_t flipper_mario_app(void* p) {
    UNUSED(p);
    App* app = malloc(sizeof(App));
    memset(app, 0, sizeof(*app));
    app->events = furi_message_queue_alloc(8, sizeof(InputEvent));
    app->mutex  = furi_mutex_alloc(FuriMutexTypeNormal);
    app->running = true;
    sound_init(&app->sound);
    game_init(&app->game);
    g_app = app;

    ViewPort* viewport = view_port_alloc();
    view_port_draw_callback_set(viewport, render, app);
    view_port_input_callback_set(viewport, input_cb, app);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);

    const uint32_t frame_ms = 20; // ~50 fps to keep input -> visual latency low
    uint32_t next = furi_get_tick();
    InputEvent ev;

    while(app->running) {
        // Drain input events until next frame. Only InputTypePress sets held;
        // InputTypeShort fires on release after a quick tap and would
        // erroneously re-arm the held bit if we listened to it.
        uint32_t now = furi_get_tick();
        uint32_t wait = next > now ? next - now : 0;
        while(furi_message_queue_get(app->events, &ev, wait) == FuriStatusOk) {
            wait = 0;
            if(furi_mutex_acquire(app->mutex, FuriWaitForever) == FuriStatusOk) {
                if(ev.type == InputTypePress) {
                    app->game.btn_held    |= (1 << ev.key);
                    app->game.btn_pressed |= (1 << ev.key);
                } else if(ev.type == InputTypeRelease) {
                    app->game.btn_held &= ~(1 << ev.key);

                furi_mutex_release(app->mutex);
            }
        }

        if(furi_mutex_acquire(app->mutex, FuriWaitForever) == FuriStatusOk) {
            game_step(&app->game);
            uint32_t now_ms = furi_get_tick() * 1000U / furi_kernel_get_tick_frequency();
            sound_tick(&app->sound, now_ms);
            furi_mutex_release(app->mutex);
        }
        view_port_update(viewport);

        next += frame_ms;
        if(next < furi_get_tick()) next = furi_get_tick();
    }

    sound_release(&app->sound);
    // Restore default (auto-off) backlight behavior on exit.
    g_app = NULL;
    view_port_enabled_set(viewport, false);
    gui_remove_view_port(gui, viewport);
    view_port_free(viewport);
    furi_record_close(RECORD_GUI);
    furi_message_queue_free(app->events);
    furi_mutex_free(app->mutex);
    free(app);
    return 0;
}
