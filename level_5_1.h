// Level 5-1 - Overworld (SMBDIS L_GroundArea11 / E_GroundArea11).
// Original has Bullet Bill cannons and a Hammer Bros pair. We lack those
// enemies, so cannons are replaced with stair-shaped brick stacks and Hammer
// Bros become a sparse pair of goombas atop low brick platforms.
#pragma once
#include "level_format.h"

static const char level_5_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "         C            C            C            C            C            C            C            C            C            C            C            C            C            C            C                ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                  ?BB?                  B?B                 BB                  BBBB                B                                       BBBB           BB                  BBBB                             ",
    "                                                  c                                  cc                             BB              BB                                         c c                      F       ",
    " h           h         L          L          L         L          L      L      L         L         L                BB              BB               h       BBBB             h              h         P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_5_1[] = {
    {  26 * 8, 6 * 8, 0 },
    {  38 * 8, 6 * 8, 0 },
    {  52 * 8, 6 * 8, 1 },
    {  60 * 8, 6 * 8, 0 },
    {  84 * 8, 6 * 8, 0 },
    {  92 * 8, 6 * 8, 0 },
    { 108 * 8, 6 * 8, 0 },
    { 116 * 8, 6 * 8, 1 },
    { 138 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 0 },
    { 168 * 8, 6 * 8, 0 },
    { 178 * 8, 6 * 8, 1 },
    { 188 * 8, 6 * 8, 0 },
};
#define LEVEL_5_1_ENEMY_COUNT (sizeof(enemy_spawns_5_1) / sizeof(EnemySpawn))
