// Level 8-1 - long overworld. Approximated from SMB1 L_GroundArea17. Bullet Bills replaced with brick towers.
#pragma once
#include "level_format.h"

static const char level_8_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "        C                     C                     C                     C                     C                     C                     C                     C                     C                       ",
    "                                                                                                                                                                                                                ",
    "                                              BB                                                BB                                                                BB                                            ",
    "              ?  B?B  ?       BB              BB            BB?BB BB                            BB  B?B!B                           BB          BBB?BB            BB          ?B?                               ",
    "                              BB      L       BB        ccc       BB                cccc        BB                    cccc          BB                            BB                                    F       ",
    "      h           h           BB              BB                  BB  L                   L     BB          L                       BB    L                       BB    L                               P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGG   GGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_8_1[] = {
    {  20 * 8, 6 * 8, 0 },
    {  28 * 8, 6 * 8, 1 },
    {  36 * 8, 6 * 8, 0 },
    {  44 * 8, 6 * 8, 0 },
    {  52 * 8, 6 * 8, 1 },
    {  64 * 8, 6 * 8, 0 },
    {  74 * 8, 6 * 8, 1 },
    {  86 * 8, 6 * 8, 0 },
    {  94 * 8, 6 * 8, 0 },
    { 106 * 8, 6 * 8, 1 },
    { 122 * 8, 6 * 8, 0 },
    { 130 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 1 },
    { 156 * 8, 6 * 8, 0 },
    { 166 * 8, 6 * 8, 1 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_8_1_ENEMY_COUNT (sizeof(enemy_spawns_8_1) / sizeof(EnemySpawn))
