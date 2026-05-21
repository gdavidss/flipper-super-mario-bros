// Level 1-2 - underground level. Geometry derived from SMB1
// L_UndergroundArea1 / E_UndergroundArea1 in the disassembly: full ceiling
// of ground tiles, brick formations hanging from the ceiling, several coin
// rows, two short pipes, goombas only. Compressed to 8 rows for Flipper.
#pragma once
#include "level_format.h"

static const char level_1_2_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                                                                                                                                                                                                                ",
    "                              BBBB                          BBB                         BBBB                            BBBBB                         BBB                                                       ",
    "                    ?                       BBBB       ?              BBBBB                         !                                  ?                             ?                                          ",
    "                        BBBBBB                    BBBBBBBB                      BBBBBB                      BBBBBBBBBB                      BBBBBBBB                      BBBBBBBB                              ",
    "                         cccc                       ccccc                         ccc                         cccccc                          cccc                          cccc                        F       ",
    "                                                                                               L                                                              L                                         P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_1_2[] = {
    {  20 * 8, 6 * 8, 0 },
    {  36 * 8, 6 * 8, 0 },
    {  48 * 8, 6 * 8, 0 },
    {  64 * 8, 6 * 8, 0 },
    {  78 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 0 },
    { 118 * 8, 6 * 8, 0 },
    { 128 * 8, 6 * 8, 0 },
    { 138 * 8, 6 * 8, 0 },
    { 150 * 8, 6 * 8, 0 },
    { 166 * 8, 6 * 8, 0 },
    { 180 * 8, 6 * 8, 0 },
    { 190 * 8, 6 * 8, 0 },
};
#define LEVEL_1_2_ENEMY_COUNT (sizeof(enemy_spawns_1_2) / sizeof(EnemySpawn))
