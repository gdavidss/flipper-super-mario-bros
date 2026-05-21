// Level 8-4 - FINAL CASTLE - Bowser. Approximated from SMB1 L_CastleArea6, simplified to a single corridor.
#pragma once
#include "level_format.h"

static const char level_8_4_src[LEVEL_H][LEVEL_W + 1] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                ",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                ",
    "                  B                   B                     B                       B                         B                       B                       B                     B                           ",
    "                  B                   B                     B                       B                         B                       B                       B                     B                           ",
    "                          BBB                 BB                      BB                   cc                     BB                      BBB                                         BB                        ",
    "                           cc                                          cc                 BBB                                              cc                     BB                                    F       ",
    "                                                                                                                                                                                                        P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGG   GGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_8_4[] = {
    {  16 * 8, 6 * 8, 0 },
    {  22 * 8, 6 * 8, 1 },
    {  34 * 8, 6 * 8, 0 },
    {  40 * 8, 6 * 8, 1 },
    {  46 * 8, 6 * 8, 0 },
    {  58 * 8, 6 * 8, 1 },
    {  66 * 8, 6 * 8, 0 },
    {  80 * 8, 6 * 8, 1 },
    {  88 * 8, 6 * 8, 0 },
    { 100 * 8, 6 * 8, 1 },
    { 108 * 8, 6 * 8, 0 },
    { 124 * 8, 6 * 8, 1 },
    { 132 * 8, 6 * 8, 0 },
    { 148 * 8, 6 * 8, 1 },
    { 154 * 8, 6 * 8, 0 },
    { 166 * 8, 6 * 8, 1 },
    { 174 * 8, 6 * 8, 0 },
    { 178 * 8, 6 * 8, 1 },
    { 184 * 8, 6 * 8, 0 },
    { 192 * 8, 6 * 8, 1 },
};
#define LEVEL_8_4_ENEMY_COUNT (sizeof(enemy_spawns_8_4) / sizeof(EnemySpawn))
