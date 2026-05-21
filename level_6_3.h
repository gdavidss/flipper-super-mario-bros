// Level 6-3 - athletic / sky bridges. Original SMB1 uses
// L_GroundArea14 with terrain control $11 (bridge style) and many $9x
// (rope/island) objects; this port flattens that into a series of
// long elevated brick "bridges" separated by wide pits, with koopas
// patrolling each bridge - the classic 6-3 character.
#pragma once
#include "level_format.h"

static const char level_6_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "         C              C              C              C              C              C              C              C              C              C              C              C              C                  ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                  BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBBBBBB    BBBBBBBBB                            ",
    "                      cc cc            cc cc            cc cc            cc cc            cc cc            cc cc            cc cc            cc cc            cc cc          cc cc                      F       ",
    "                                                                                                                                                                                                        P       ",
    "GGGGGGGGGGGGGGGGGG                                                                                                                                                                  GGGGGGGGGGGGGGGGGGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_6_3[] = {
    {  22 * 8, 3 * 8, 1 },
    {  28 * 8, 3 * 8, 1 },
    {  40 * 8, 3 * 8, 1 },
    {  58 * 8, 3 * 8, 0 },
    {  72 * 8, 3 * 8, 1 },
    {  90 * 8, 3 * 8, 1 },
    { 108 * 8, 3 * 8, 0 },
    { 124 * 8, 3 * 8, 1 },
    { 140 * 8, 3 * 8, 1 },
    { 158 * 8, 3 * 8, 0 },
    { 174 * 8, 3 * 8, 1 },
};
#define LEVEL_6_3_ENEMY_COUNT (sizeof(enemy_spawns_6_3) / sizeof(EnemySpawn))
