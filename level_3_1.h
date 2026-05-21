// Level 3-1 - overworld (night). Approximated from SMB1 L_GroundArea5.
#pragma once
#include "level_format.h"

static const char level_3_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C                     C                           C                       C                       C                       C                       C                       C                               ",
    "                                                                                                                                                                                    cccc                        ",
    "                                                                                                                     cccc                                                                       G               ",
    "                      ?         B?B!B                 ?               BBBBL             B?B                         BBBBBB                                              B?B         BBBB       GG               ",
    "                                                            L                                                 L                                                                               GGG       F       ",
    "    h         h                       h       L                                                 h                                 L             h             L                         h    GGGG       P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_3_1[] = {
    {  22 * 8, 6 * 8, 0 },
    {  40 * 8, 6 * 8, 0 },
    {  58 * 8, 6 * 8, 1 },
    {  76 * 8, 6 * 8, 0 },
    {  78 * 8, 6 * 8, 0 },
    {  94 * 8, 6 * 8, 0 },
    { 112 * 8, 6 * 8, 1 },
    { 130 * 8, 6 * 8, 0 },
    { 132 * 8, 6 * 8, 0 },
    { 150 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 1 },
    { 186 * 8, 6 * 8, 0 },
};
#define LEVEL_3_1_ENEMY_COUNT (sizeof(enemy_spawns_3_1) / sizeof(EnemySpawn))
