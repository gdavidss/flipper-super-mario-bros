// Shared level-format header. One file per level provides its own
// `level_X_Y_src[][]` and `enemy_spawns_X_Y[]`. flipper_mario.c builds a
// registry of Level entries pointing at those arrays.
#pragma once
#include <stdint.h>
#include <stdbool.h>

#define T_AIR      0
#define T_GROUND   1
#define T_BRICK    2
#define T_QBLOCK   3   // contains coin
#define T_QPOWER   4   // contains powerup (mushroom)
#define T_USED     5
#define T_PIPETL   6
#define T_PIPETR   7
#define T_PIPEBL   8
#define T_PIPEBR   9
#define T_COIN     10
#define T_CLOUD    11
#define T_BUSH     12
#define T_FLAGTOP  13
#define T_FLAGPOLE 14
#define T_CASTLE   15

#define LEVEL_W 208
#define LEVEL_H 8

static inline bool tile_is_solid(uint8_t t) {
    switch(t) {
    case T_GROUND:
    case T_BRICK:
    case T_QBLOCK:
    case T_QPOWER:
    case T_USED:
    case T_PIPETL:
    case T_PIPETR:
    case T_PIPEBL:
    case T_PIPEBR:
    case T_CASTLE:
        return true;
    default:
        return false;
    }
}

static inline bool tile_is_hittable(uint8_t t) {
    return t == T_BRICK || t == T_QBLOCK || t == T_QPOWER;
}

// Runtime tile grid (mutable - bricks break, ?-blocks become USED, etc.).
extern uint8_t level_grid[LEVEL_H][LEVEL_W];

// Enemy spawn descriptor. spawn_x in pixels; spawns when camera approaches.
typedef struct {
    int16_t spawn_x;
    int16_t y;
    uint8_t type;  // 0 = goomba, 1 = koopa
} EnemySpawn;

// Decoder for the level-source character set. Used by level_compile().
//   ' '=air  G=ground  B=brick  ?=qblock  !=qpower  L=pipe-top  c=coin
//   C=cloud  h=bush    F=flagtop P=flagpole K=castle
static inline uint8_t tile_from_char(char c) {
    switch(c) {
    case 'G': return T_GROUND;
    case 'B': return T_BRICK;
    case '?': return T_QBLOCK;
    case '!': return T_QPOWER;
    case 'L': return T_PIPETL;
    case 'c': return T_COIN;
    case 'C': return T_CLOUD;
    case 'h': return T_BUSH;
    case 'F': return T_FLAGTOP;
    case 'P': return T_FLAGPOLE;
    case 'K': return T_CASTLE;
    default:  return T_AIR;
    }
}

// Compile a printable source grid into the runtime grid. 'L' pipes are
// expanded into two-wide pipe tops, then stack body tiles downward until
// the column hits ground.
static inline void level_compile_from(const char src[LEVEL_H][LEVEL_W + 1]) {
    for(int y = 0; y < LEVEL_H; y++) {
        for(int x = 0; x < LEVEL_W; x++) {
            level_grid[y][x] = tile_from_char(src[y][x]);
        }
    }
    for(int y = 0; y < LEVEL_H; y++) {
        for(int x = 0; x < LEVEL_W - 1; x++) {
            if(level_grid[y][x] == T_PIPETL) {
                level_grid[y][x + 1] = T_PIPETR;
                for(int yy = y + 1; yy < LEVEL_H; yy++) {
                    if(level_grid[yy][x] == T_GROUND) break;
                    level_grid[yy][x]     = T_PIPEBL;
                    level_grid[yy][x + 1] = T_PIPEBR;
                }
            }
        }
    }
}

// One level definition - registered by flipper_mario.c's levels[] table.
typedef struct {
    const char* name;                 // e.g. "1-1", "8-4"
    uint16_t    timer_start;          // SMB1 typically 400 (300 for castles)
    const char  (*src)[LEVEL_W + 1];  // pointer to the LEVEL_H-row source
    uint8_t     spawn_count;
    const EnemySpawn* spawns;
} Level;
