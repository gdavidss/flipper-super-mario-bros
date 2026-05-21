// Level 2-1 - overworld with piranha pipes
#pragma once
#include "level_format.h"

static const char level_2_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C            C            C            C            C            C            C            C            C            C            C            C            C            C            C            C      ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                        ?  B!B                BBBB                              BB BB                           BBBBBB              ?BB?              BBBB BBBB                          BB BB                  ",
    "                                                                cc      cc                                                                                                                              F       ",
    "   h          h                       L           L   L     L                       L          h              L                                               L   L            h            h           P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_2_1[] = {
    {  20 * 8, 6 * 8, 0 },
    {  34 * 8, 6 * 8, 0 },
    {  48 * 8, 6 * 8, 0 },
    {  56 * 8, 6 * 8, 0 },
    {  72 * 8, 6 * 8, 0 },
    {  84 * 8, 6 * 8, 1 },
    {  92 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 0 },
    { 118 * 8, 6 * 8, 0 },
    { 130 * 8, 6 * 8, 1 },
    { 144 * 8, 6 * 8, 0 },
    { 158 * 8, 6 * 8, 0 },
    { 172 * 8, 6 * 8, 0 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_2_1_ENEMY_COUNT (sizeof(enemy_spawns_2_1) / sizeof(EnemySpawn))
