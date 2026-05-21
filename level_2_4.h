// Level 2-4 - castle
#pragma once
#include "level_format.h"

static const char level_2_4_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                    BBB                           BBBB                                                BBB               BBBB                                      BBB                                           ",
    "                    B                             B                                                   B                 BB                                        B                                             ",
    "                                                                                                                                                                                                                ",
    "                                                            ?                                                 !                                                                                                 ",
    "                                        B                                   BBB           BB                                      BB                      BBB                  BB                       F       ",
    "                                        B                                                 BB                                      BB                                           BB                       P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_2_4[] = {
    {  24 * 8, 6 * 8, 0 },
    {  46 * 8, 6 * 8, 0 },
    {  66 * 8, 6 * 8, 1 },
    {  96 * 8, 6 * 8, 0 },
    { 124 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 1 },
    { 166 * 8, 6 * 8, 0 },
    { 186 * 8, 6 * 8, 0 },
};
#define LEVEL_2_4_ENEMY_COUNT (sizeof(enemy_spawns_2_4) / sizeof(EnemySpawn))
