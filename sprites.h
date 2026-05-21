// 8x8 monochrome sprite bitmaps. 1 bit per pixel, MSB = leftmost pixel.
// Sprites are drawn in screen-space with optional horizontal flip.
//
// SMB1's original art is 16x16 with 4-color palettes. At 8x8 monochrome we
// keep silhouettes that read at a glance: cap+brim+face+overall pattern for
// Mario, antennae+wide-base for Goomba, shell-on-back for Koopa, etc.
#pragma once
#include <stdint.h>

// Original 8x8 Mario sprites - kept simple. Mario small is 1 tile, big is
// two stacked 8x8 tiles.
#define MARIO_SMALL_SPR_H 8
#define MARIO_BIG_SPR_H   16

// Small Mario - 8x8. Solid silhouette (no holes), 2-pixel-wide legs and
// boots, full-width arms. Symmetric so the flip for left-facing doesn't
// distort the silhouette.
static const uint8_t spr_mario_stand[8] = {
    0b00111100,  // 0: cap top
    0b01111110,  // 1: cap brim
    0b01101100,  // 2: face with eyes
    0b01111110,  // 3: face full
    0b11111111,  // 4: shoulders + arms (solid)
    0b01111110,  // 5: chest narrows, arms tuck in
    0b01100110,  // 6: legs apart
    0b11000011,  // 7: boots
};

static const uint8_t spr_mario_walk[8] = {
    0b00111100,
    0b01111110,
    0b01101100,
    0b01111110,
    0b11111111,
    0b01111110,
    0b00110110,
    0b01100011,
};

static const uint8_t spr_mario_walk2[8] = {
    0b00111100,
    0b01111110,
    0b01101100,
    0b01111110,
    0b11111111,
    0b01111110,
    0b01101100,
    0b11000110,
};

static const uint8_t spr_mario_jump[8] = {
    0b00111100,
    0b01111110,
    0b01101100,
    0b01111110,
    0b11111111,
    0b01111110,
    0b01111110,
    0b01100110,
};

// Big Mario top half (head). Wider brim and a proper mustache band.
static const uint8_t spr_mario_big_top[8] = {
    0b00111000,  // cap top
    0b01111100,  // cap brim
    0b11111110,  // brim wide (extends right)
    0b11011000,  // hair tuft + face + eye
    0b11011000,  // eye + face
    0b01111000,  // nose
    0b01010100,  // mustache halves
    0b00111000,  // chin
};

// Big Mario bottom half (chest, overalls, legs, boots).
static const uint8_t spr_mario_big_bot[8] = {
    0b01111100,  // shoulders
    0b11011110,  // arms + body
    0b01011010,  // overall buttons
    0b01111100,  // belt
    0b01111000,  // hips
    0b01010100,  // legs apart
    0b11011010,  // boots
    0b11001100,  // soles
};

// Goomba - wide antennae, two eyes, split feet.
static const uint8_t spr_goomba[8] = {
    0b01100110, // antennae
    0b00111100,
    0b01111110,
    0b11011011, // eyes
    0b11111111,
    0b11111111,
    0b01111110,
    0b11000011, // feet
};

// Goomba - squished (flat).
static const uint8_t spr_goomba_dead[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b01111110,
    0b11011011,
    0b11111111,
};

// Koopa troopa - head sticks out of shell.
static const uint8_t spr_koopa[8] = {
    0b00011000, // head top
    0b00111100,
    0b00100100, // eye
    0b00111100,
    0b01111110, // shell rim
    0b11011011, // shell pattern
    0b01111110, // shell rim
    0b01000010, // feet
};

// Loose shell.
static const uint8_t spr_shell[8] = {
    0b00000000,
    0b00111100,
    0b01111110,
    0b11011011,
    0b11011011,
    0b01111110,
    0b00111100,
    0b00000000,
};

// Ground block - SMB1's bricked-dirt look at 8x8.
static const uint8_t spr_ground[8] = {
    0b11111111,
    0b10110111,
    0b10110111,
    0b11111111,
    0b11101101,
    0b11101101,
    0b11111111,
    0b01011010,
};

// Brick - rows of small bricks staggered.
static const uint8_t spr_brick[8] = {
    0b11111111,
    0b10101011,
    0b10101011,
    0b11111111,
    0b11010101,
    0b11010101,
    0b11111111,
    0b10101011,
};

// Question block - frame with small "?" centered.
static const uint8_t spr_qblock[8] = {
    0b11111111,
    0b10011001,
    0b10110101,
    0b11110101,
    0b11101001,
    0b11111101,
    0b11101001,
    0b11111111,
};

// Used (hit) block - flat-bumped frame.
static const uint8_t spr_used_block[8] = {
    0b11111111,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b11111111,
};

// Coin - tall thin oval, classic SMB1 silhouette.
static const uint8_t spr_coin[8] = {
    0b00011000,
    0b00100100,
    0b00101100,
    0b00110100,
    0b00110100,
    0b00101100,
    0b00100100,
    0b00011000,
};

// Pipe top - left half. Drawn next to right half to form a 16x8 lip.
static const uint8_t spr_pipe_topL[8] = {
    0b00111111,
    0b01000000,
    0b01011111,
    0b01011111,
    0b01011111,
    0b01111111,
    0b00010000,
    0b00010000,
};

// Pipe top - right half.
static const uint8_t spr_pipe_topR[8] = {
    0b11111100,
    0b00000010,
    0b11111010,
    0b11111010,
    0b11111010,
    0b11111110,
    0b00001000,
    0b00001000,
};

// Pipe body - left half.
static const uint8_t spr_pipe_bodyL[8] = {
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
};

// Pipe body - right half.
static const uint8_t spr_pipe_bodyR[8] = {
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
};

// Cloud (decoration).
static const uint8_t spr_cloud[8] = {
    0b00000000,
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00000000,
    0b00000000,
};

// Bush (decoration).
static const uint8_t spr_bush[8] = {
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011100,
    0b00111110,
    0b01111111,
    0b11111111,
    0b11111111,
};

// Flagpole top (ball).
static const uint8_t spr_flagtop[8] = {
    0b00001000,
    0b00011100,
    0b00111110,
    0b00011100,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
};

// Flagpole shaft.
static const uint8_t spr_flagpole[8] = {
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
};

// Castle (end-of-level marker).
static const uint8_t spr_castle[8] = {
    0b10101010,
    0b11111111,
    0b00111100,
    0b01100110,
    0b11000011,
    0b11000011,
    0b11011011,
    0b11111111,
};

// Mushroom power-up.
static const uint8_t spr_mushroom[8] = {
    0b00111100,
    0b01011010,
    0b11100111,
    0b11011011,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00111100,
};
