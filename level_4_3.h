// Level 4-3 - Athletic (from L_GroundArea13, Lakitu replaced with koopas)
#pragma once
#include "level_format.h"

static const char level_4_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C                       C                       C                       C                       C                       C                       C                       C                       C         ",
    "                                                                                                                                                                                                                ",
    "                                        GGGGG                                                     GGGGGG                                                      GGGGG                                             ",
    "                  B?B                                       BBBB                                                        B?B                                                         BBB                         ",
    "                                        ccccc                         GGGGGG                      cccccc                          GGGGG                       ccccc                                     F       ",
    "    h   h                                                                                                                                           h                                                   P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG         GGGGGGGGGGGGGGGGGGGGG          GGGGGGGGGGGGGGGGGG          GGGGGGGGGGGGGGGGGGGGGG         GGGGGGGGGGGGGGGGGGG         GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGGGGGGG",
};

static const EnemySpawn enemy_spawns_4_3[] = {
    {  16 * 8, 6 * 8, 0 },
    {  40 * 8, 2 * 8, 1 },
    {  60 * 8, 6 * 8, 1 },
    {  72 * 8, 4 * 8, 1 },
    {  90 * 8, 6 * 8, 0 },
    { 100 * 8, 2 * 8, 1 },
    { 115 * 8, 6 * 8, 0 },
    { 132 * 8, 4 * 8, 1 },
    { 145 * 8, 6 * 8, 1 },
    { 160 * 8, 2 * 8, 1 },
    { 175 * 8, 6 * 8, 0 },
    { 185 * 8, 6 * 8, 0 },
};
#define LEVEL_4_3_ENEMY_COUNT (sizeof(enemy_spawns_4_3) / sizeof(EnemySpawn))
