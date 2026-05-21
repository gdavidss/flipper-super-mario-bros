// Level 1-1. Geometry follows SMB1's area-1 object stream from the
// disassembly: three brick groups, two pits, multiple pipes, ?-blocks with
// coins/mushroom, flagpole + castle at the end.
#pragma once
#include "level_format.h"

static const char level_1_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "    C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C     ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                    ?     B?B?B                                 BBBBBB   BBBBBB                                 BB      BB          BBBBBBBB               BB    BB    BB    BB                                 ",
    "                                                                                          cc                                                                                                              F     ",
    " h     h                    L                  L            L  L                                    L L                                                                                 L L        h      P     ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_1_1[] = {
    {  22 * 8, 6 * 8, 0 },
    {  40 * 8, 6 * 8, 0 },
    {  50 * 8, 6 * 8, 0 },
    {  52 * 8, 6 * 8, 0 },
    {  78 * 8, 6 * 8, 0 },
    {  80 * 8, 6 * 8, 0 },
    {  96 * 8, 6 * 8, 1 },
    { 112 * 8, 6 * 8, 0 },
    { 130 * 8, 6 * 8, 0 },
    { 132 * 8, 6 * 8, 0 },
    { 154 * 8, 6 * 8, 0 },
    { 156 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 1 },
    { 180 * 8, 6 * 8, 0 },
};
#define LEVEL_1_1_ENEMY_COUNT (sizeof(enemy_spawns_1_1) / sizeof(EnemySpawn))
