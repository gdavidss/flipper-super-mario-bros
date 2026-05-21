// Level 8-2 - overworld with castle aesthetics. Approximated from SMB1 L_GroundArea19.
#pragma once
#include "level_format.h"

static const char level_8_2_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "            C                   C                   C                   C                   C                   C                   C                   C                   C                   C               ",
    "                                                                                        B                                                                                                                       ",
    "                          B                             B                               BB                            B                             B                         B                                 ",
    "          ?B?B?           BB                  BB!BB     BB                    BBB?B     BBB                 ?B?B!     BB                  BB?BB     BB                  B?B   B                                 ",
    "                          BB              ccc           BB                              BBB         cccc              BB                        ccc BB                        B                         F       ",
    "                  L       BB                            BB      L                       BBB                   L       BB                            BB      L                 B                         P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_8_2[] = {
    {  22 * 8, 6 * 8, 1 },
    {  30 * 8, 6 * 8, 0 },
    {  38 * 8, 6 * 8, 0 },
    {  50 * 8, 6 * 8, 1 },
    {  58 * 8, 6 * 8, 0 },
    {  68 * 8, 6 * 8, 0 },
    {  80 * 8, 6 * 8, 1 },
    {  94 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 1 },
    { 116 * 8, 6 * 8, 0 },
    { 126 * 8, 6 * 8, 0 },
    { 138 * 8, 6 * 8, 1 },
    { 152 * 8, 6 * 8, 0 },
    { 166 * 8, 6 * 8, 0 },
    { 178 * 8, 6 * 8, 1 },
    { 190 * 8, 6 * 8, 0 },
};
#define LEVEL_8_2_ENEMY_COUNT (sizeof(enemy_spawns_8_2) / sizeof(EnemySpawn))
