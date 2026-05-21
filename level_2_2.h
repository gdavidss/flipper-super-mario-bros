// Level 2-2 - reskinned underground (no swimming)
#pragma once
#include "level_format.h"

static const char level_2_2_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                              BBB                               BBBB                            BBBBBB                              BBB                                     B?B!B?B                             ",
    "            BBBBB                                 BBBBBBBB                        B?BBB?B                           BBBBB                           BBBBBBBB                                BBBB                ",
    "                ccccccccc             cccccc                          cccccccc                      ccccc                   cccccc                                      cccccccc                        F       ",
    "                                                                                                                                                                                                    L   P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_2_2[] = {
    {  28 * 8, 6 * 8, 0 },
    {  44 * 8, 6 * 8, 0 },
    {  58 * 8, 6 * 8, 1 },
    {  76 * 8, 6 * 8, 0 },
    {  94 * 8, 6 * 8, 0 },
    { 110 * 8, 6 * 8, 0 },
    { 126 * 8, 6 * 8, 0 },
    { 138 * 8, 6 * 8, 1 },
    { 156 * 8, 6 * 8, 0 },
    { 174 * 8, 6 * 8, 0 },
    { 186 * 8, 6 * 8, 0 },
};
#define LEVEL_2_2_ENEMY_COUNT (sizeof(enemy_spawns_2_2) / sizeof(EnemySpawn))
