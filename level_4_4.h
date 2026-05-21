// Level 4-4 - Castle (from L_CastleArea2, maze flattened to straight corridor)
#pragma once
#include "level_format.h"

static const char level_4_4_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                BBB                               BBBB                                  BBB                                 BBBB                                BBB                                             ",
    "                                                                                                                                                                                                                ",
    "                              BBBBB                                   BBB                                   BBBB                                BBB                                 BBBB                        ",
    "                      BBB                                   BBBB                                  BBB                                   BBBB                              BBB                                   ",
    "                                            GG                                    GG                                  GG                                  GG                                            F       ",
    "                                            GG                                    GG                                  GG                                  GG                                            P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGGGGGGG",
};

static const EnemySpawn enemy_spawns_4_4[] = {
    {  20 * 8, 6 * 8, 1 },
    {  38 * 8, 6 * 8, 0 },
    {  54 * 8, 6 * 8, 1 },
    {  72 * 8, 6 * 8, 0 },
    {  90 * 8, 6 * 8, 1 },
    { 108 * 8, 6 * 8, 0 },
    { 126 * 8, 6 * 8, 1 },
    { 144 * 8, 6 * 8, 0 },
    { 162 * 8, 6 * 8, 1 },
    { 180 * 8, 6 * 8, 0 },
};
#define LEVEL_4_4_ENEMY_COUNT (sizeof(enemy_spawns_4_4) / sizeof(EnemySpawn))
