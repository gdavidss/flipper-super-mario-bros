// Level 7-2 - SMB1 area $29 is underwater. This engine has no water/swimming
// physics, so we reskin as an underground corridor: full ground ceiling on
// row 0, brick formations and coin rows hanging beneath, goombas on the floor.
#pragma once
#include "level_format.h"

static const char level_7_2_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                                                                                                                                                                                                                ",
    "                              BBBB                          BBB                         BBBB                            BBBBB                         BBB                                                       ",
    "                    ?                       BBBB       ?              BBBBB                         !                                  ?                             ?                                          ",
    "                        BBBBBB                    BBBBBBBB                      BBBBBB                      BBBBBBBBBB                      BBBBBBBB                      BBBBBBBB                              ",
    "                         cccc                       ccccc                         ccc                         cccccc                          cccc                          cccc                        F       ",
    "                                                                                               L                                                              L                                         P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_7_2[] = {
    {  20 * 8, 6 * 8, 0 },
    {  34 * 8, 6 * 8, 0 },
    {  48 * 8, 6 * 8, 0 },
    {  62 * 8, 6 * 8, 0 },
    {  76 * 8, 6 * 8, 0 },
    {  90 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 0 },
    { 118 * 8, 6 * 8, 0 },
    { 132 * 8, 6 * 8, 0 },
    { 146 * 8, 6 * 8, 0 },
    { 160 * 8, 6 * 8, 0 },
    { 174 * 8, 6 * 8, 0 },
    { 188 * 8, 6 * 8, 0 },
};
#define LEVEL_7_2_ENEMY_COUNT (sizeof(enemy_spawns_7_2) / sizeof(EnemySpawn))
