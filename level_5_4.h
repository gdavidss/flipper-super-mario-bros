// Level 5-4 - Castle (SMBDIS L_CastleArea3 / E_CastleArea3, shared with 2-4).
// Original castle has rotating fire bars, Podoboos, lava pits and a Bowser
// fight. We have none of these enemies, so the layout is simplified to a
// straight corridor with brick ceiling, hanging stalactites, brick pillars
// flanking lava-style pits, and a flagpole/castle at the exit. Sparse goombas
// and koopas substitute for the fire hazards.
#pragma once
#include "level_format.h"

static const char level_5_4_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB        ",
    "                    B               B                       B                           B                           B                       B                           B               B                       ",
    "                            BB                      BB                        B?B                             BB                    ?                         BB                  B                             ",
    "                      BB                    BBB                 BB                            BBBB                      BBB                           BBBB                    BB                                ",
    "                B                       B                               B             B                     B                   B                           B               B                           F       ",
    "                B                       B                               B             B                     B                   B                           B               B                           P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGG    GGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_5_4[] = {
    {  10 * 8, 6 * 8, 0 },
    {  24 * 8, 6 * 8, 0 },
    {  46 * 8, 6 * 8, 1 },
    {  64 * 8, 6 * 8, 0 },
    {  76 * 8, 6 * 8, 0 },
    {  92 * 8, 6 * 8, 0 },
    { 106 * 8, 6 * 8, 1 },
    { 124 * 8, 6 * 8, 0 },
    { 134 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 0 },
    { 168 * 8, 6 * 8, 1 },
    { 182 * 8, 6 * 8, 0 },
};
#define LEVEL_5_4_ENEMY_COUNT (sizeof(enemy_spawns_5_4) / sizeof(EnemySpawn))
