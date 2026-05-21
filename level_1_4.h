// Level 1-4 - Bowser's castle. Geometry derived from SMB1
// L_CastleArea1 / E_CastleArea1 in the disassembly: a brick-walled corridor
// with firebar columns and lava pits, ending at the bridge / castle. The
// SMB1 castle has no stompable foot soldiers (just firebars and Bowser
// himself); for this port we substitute a couple of goombas where firebars
// originally were. Firebars are simplified to 2-tile brick columns and
// hanging brick chunks since we don't render rotating fire.
#pragma once
#include "level_format.h"

static const char level_1_4_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGG                                                                                                                                                                                            GGGGGGGGGGGG",
    "GGGGGGGG                                                                                                                                                                                            GGGGGGGGGGGG",
    "                                                                                                                                                                                                                ",
    "                                                            BBBBBB                             BBBB                          BBBBBB                                                                             ",
    "                    BBBBBB                                                                BBBBBB                                                           BBBBBB                                               ",
    "                              B         ccc       B                        B                        ccc       B                                  B                   ccc       B                        F       ",
    "                              B                   B                        B                                  B                                  B                             B                        P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_1_4[] = {
    {  18 * 8, 6 * 8, 0 },
    {  46 * 8, 6 * 8, 0 },
    {  68 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 0 },
    { 124 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 0 },
};
#define LEVEL_1_4_ENEMY_COUNT (sizeof(enemy_spawns_1_4) / sizeof(EnemySpawn))
