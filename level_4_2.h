// Level 4-2 - Underground (from L_UndergroundArea2, bonus rooms cut)
#pragma once
#include "level_format.h"

static const char level_4_2_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "          BBBBBB              BBB           BBBBBBB                   BBBB                BBBBBBB             BBB               BBBBBB                BBBBBB                BBB             BBBB                ",
    "                      BBBB                                BB?BB                                     BB?BB                                   BBBB                    BBB                                         ",
    "                      cccc                  ccccccc                   cccc                ccccccc                               cccccc                cccccc                                                    ",
    "                                    BBBB                                        BB?BB                                 BBBB                                      BBB                                             ",
    "              ccc                                     cccc                                               ccc                                    cccc                                cccc                F       ",
    "                                        GG                                  GGG                                                         GGG                                                             P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGGGGGGG",
};

static const EnemySpawn enemy_spawns_4_2[] = {
    {  18 * 8, 6 * 8, 0 },
    {  30 * 8, 6 * 8, 0 },
    {  52 * 8, 6 * 8, 0 },
    {  65 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 1 },
    { 108 * 8, 6 * 8, 0 },
    { 124 * 8, 6 * 8, 0 },
    { 145 * 8, 6 * 8, 0 },
    { 158 * 8, 6 * 8, 1 },
    { 170 * 8, 6 * 8, 0 },
    { 185 * 8, 6 * 8, 0 },
};
#define LEVEL_4_2_ENEMY_COUNT (sizeof(enemy_spawns_4_2) / sizeof(EnemySpawn))
