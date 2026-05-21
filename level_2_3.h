// Level 2-3 - athletic bridges over pits
#pragma once
#include "level_format.h"

static const char level_2_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C            C            C            C            C            C            C            C            C            C            C            C            C            C            C            C      ",
    "                                                                                                                                                                                                                ",
    "                        cc                                                            cc                                                          cc                                                            ",
    "                      BBBB                          BBB                             BBBB                            BBBB                        BBBB                              BBBB                          ",
    "                                    BB                                BBB                           BBB                             BBB                           BBB                                   F       ",
    "                                                                                                                                                                                                        P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_2_3[] = {
    {  18 * 8, 6 * 8, 0 },
    {  40 * 8, 6 * 8, 0 },
    {  48 * 8, 6 * 8, 1 },
    {  78 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 0 },
    { 108 * 8, 6 * 8, 1 },
    { 140 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 0 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_2_3_ENEMY_COUNT (sizeof(enemy_spawns_2_3) / sizeof(EnemySpawn))
