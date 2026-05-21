// Level 3-4 - castle. Approximated from SMB1 L_CastleArea4.
#pragma once
#include "level_format.h"

static const char level_3_4_src[LEVEL_H][LEVEL_W + 1] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB               ",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB               ",
    "                      B               B               B               B                 B               B                 B                 B               B                 B                                 ",
    "                      B               B               B               B                 B               B                 B                 B               B                 B                                 ",
    "                      B               B               B               B                 B               B     BB          B                 B               B                 B                                 ",
    "                              B               B               B                 B               B             BB  B                 B               B                 B                                 F       ",
    "                              B               B               B                 B               B                 B                 B               B                 B                                 P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_3_4[] = {
    {  24 * 8, 6 * 8, 0 },
    {  32 * 8, 6 * 8, 0 },
    {  50 * 8, 6 * 8, 0 },
    {  60 * 8, 6 * 8, 0 },
    {  78 * 8, 6 * 8, 0 },
    {  96 * 8, 6 * 8, 0 },
    { 116 * 8, 6 * 8, 1 },
    { 132 * 8, 6 * 8, 0 },
    { 148 * 8, 6 * 8, 1 },
    { 166 * 8, 6 * 8, 0 },
    { 180 * 8, 6 * 8, 0 },
};
#define LEVEL_3_4_ENEMY_COUNT (sizeof(enemy_spawns_3_4) / sizeof(EnemySpawn))
