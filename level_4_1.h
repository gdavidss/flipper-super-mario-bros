// Level 4-1 - Overworld (from L_GroundArea3)
#pragma once
#include "level_format.h"

static const char level_4_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "        C                       C                       C                       C                       C                       C                       C                       C                   C           ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                  ? BBBB          BB!BB             BBBB              BBBBBB            B?BB             BBBB             BBBBBB            B?BB              BBBBBB              BBBB                          ",
    "                                          cccc                                                                     ccc                                                                    GGGG          F       ",
    "    h     h                 L                                 L                                   L                                   L               h     h           L               GGGGGG          P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG  GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGGGGGGG",
};

static const EnemySpawn enemy_spawns_4_1[] = {
    {  22 * 8, 6 * 8, 0 },
    {  36 * 8, 6 * 8, 0 },
    {  50 * 8, 6 * 8, 0 },
    {  70 * 8, 6 * 8, 1 },
    {  80 * 8, 6 * 8, 0 },
    {  82 * 8, 6 * 8, 0 },
    { 100 * 8, 6 * 8, 0 },
    { 120 * 8, 6 * 8, 1 },
    { 130 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 0 },
    { 155 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 1 },
    { 180 * 8, 6 * 8, 0 },
    { 185 * 8, 6 * 8, 0 },
};
#define LEVEL_4_1_ENEMY_COUNT (sizeof(enemy_spawns_4_1) / sizeof(EnemySpawn))
