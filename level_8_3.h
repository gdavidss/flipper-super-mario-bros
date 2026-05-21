// Level 8-3 - athletic. Approximated from SMB1 L_GroundArea2. Hammer Bros replaced with paired koopas.
#pragma once
#include "level_format.h"

static const char level_8_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "          C                       C                       C                       C                       C                       C                       C                       C                             ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                      BBB                 BBBB              BBB             BBBB                    BBB         BBBB                      BBB                             BBBB                                  ",
    "                            ?                                       ?           ccc                       !         ccc                           ?                                                     F       ",
    "        h                           L                                                           L                                 h                     L                                               P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_8_3[] = {
    {  24 * 8, 6 * 8, 1 },
    {  26 * 8, 6 * 8, 1 },
    {  44 * 8, 6 * 8, 0 },
    {  56 * 8, 6 * 8, 1 },
    {  64 * 8, 6 * 8, 1 },
    {  66 * 8, 6 * 8, 1 },
    {  78 * 8, 6 * 8, 0 },
    {  94 * 8, 6 * 8, 1 },
    { 104 * 8, 6 * 8, 1 },
    { 106 * 8, 6 * 8, 1 },
    { 118 * 8, 6 * 8, 0 },
    { 134 * 8, 6 * 8, 0 },
    { 142 * 8, 6 * 8, 1 },
    { 144 * 8, 6 * 8, 1 },
    { 168 * 8, 6 * 8, 0 },
    { 180 * 8, 6 * 8, 1 },
};
#define LEVEL_8_3_ENEMY_COUNT (sizeof(enemy_spawns_8_3) / sizeof(EnemySpawn))
