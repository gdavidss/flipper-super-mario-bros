// Level 3-2 - overworld. Approximated from SMB1 L_GroundArea22.
#pragma once
#include "level_format.h"

static const char level_3_2_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "    C                   C                         C                       C                       C                       C                       C                       C                     C               ",
    "                                          BBBB                                                                                                                                                                  ",
    "                                                                                                                                                                                           G                    ",
    "                  ?         ?             BBBB              B?B!B                   BBBBBB                  B?B             BBBBB               ?B?               BBBB                    G                     ",
    "                                                                            L                       L                                                                                    G              F       ",
    "        h                     h     L                                 h                                       h                     L                 h     L                           G   h           P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_3_2[] = {
    {  20 * 8, 6 * 8, 0 },
    {  32 * 8, 6 * 8, 0 },
    {  44 * 8, 6 * 8, 1 },
    {  62 * 8, 6 * 8, 0 },
    {  78 * 8, 6 * 8, 0 },
    {  96 * 8, 6 * 8, 1 },
    { 110 * 8, 6 * 8, 0 },
    { 128 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 1 },
    { 158 * 8, 6 * 8, 0 },
    { 168 * 8, 6 * 8, 0 },
    { 180 * 8, 6 * 8, 1 },
};
#define LEVEL_3_2_ENEMY_COUNT (sizeof(enemy_spawns_3_2) / sizeof(EnemySpawn))
