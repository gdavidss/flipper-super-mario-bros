// Level 1-3 - athletic / tree-top level. Geometry derived from SMB1
// L_GroundArea7 / E_GroundArea7 in the disassembly: many small floating
// brick platforms at varying heights (the tree-top "mushroom" platforms),
// pits in the ground, koopa troopas. Compressed to 8 rows for Flipper -
// the tall mushroom platforms collapse to two stacked brick rows.
#pragma once
#include "level_format.h"

static const char level_1_3_src[LEVEL_H][LEVEL_W + 1] = {
    "          C                        C                                  C                                  C                                  C                                  C                                ",
    "                    C                             C                                  C                                  C                                  C                                  C                 ",
    "                            BBBBB                           BBBBB                                             BBBBBBB                             BBBBB                                                         ",
    "                  BBBBB       B           BBBBBBB             B               BBBBB             BBBBB            B              BBBBBBB             B           BBBBBBB                                         ",
    "        BBBBBBB     B         B              B    BBBBBBB     B       BBBBBBB   B       BBBBBBB   B              B    BBBBBBB      B        BBBBB   B              B      BBBBBBB                               ",
    "          ccc                                       ccc                                   ccc       ?                     cc                               ?                cc                          F       ",
    "     h                h                                                         h                                       h                                               h                               P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_1_3[] = {
    {  16 * 8, 6 * 8, 1 },
    {  26 * 8, 6 * 8, 1 },
    {  44 * 8, 6 * 8, 1 },
    {  58 * 8, 6 * 8, 0 },
    {  74 * 8, 6 * 8, 1 },
    {  84 * 8, 6 * 8, 1 },
    {  94 * 8, 6 * 8, 0 },
    { 112 * 8, 6 * 8, 1 },
    { 126 * 8, 6 * 8, 1 },
    { 146 * 8, 6 * 8, 1 },
    { 158 * 8, 6 * 8, 0 },
    { 172 * 8, 6 * 8, 1 },
    { 188 * 8, 6 * 8, 1 },
};
#define LEVEL_1_3_ENEMY_COUNT (sizeof(enemy_spawns_1_3) / sizeof(EnemySpawn))
