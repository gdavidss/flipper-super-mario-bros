// Level 6-4 - castle. Shares L_CastleArea1 with 1-4 in the original;
// this rendition has no clouds/bushes/coins, lava gaps in the floor,
// brick ceilings and pillar structures, ending at the castle. Timer
// is shorter (300) at registration time, not encoded here.
#pragma once
#include "level_format.h"

static const char level_6_4_src[LEVEL_H][LEVEL_W + 1] = {
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
    "                                                                                                                                                                                                                ",
    "          BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB           BBBBBB                      ",
    "                BB                BB              BB                BB              BB              BB              BB                BB              BB              BB              BB                        ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                        F       ",
    "          BB              BB              BB              BB              BB              BB              BB              BB              BB              BB              BB              BB            P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGG",
};

static const EnemySpawn enemy_spawns_6_4[] = {
    {  16 * 8, 6 * 8, 0 },
    {  28 * 8, 6 * 8, 1 },
    {  44 * 8, 6 * 8, 0 },
    {  58 * 8, 6 * 8, 0 },
    {  72 * 8, 6 * 8, 1 },
    {  84 * 8, 6 * 8, 0 },
    {  98 * 8, 6 * 8, 0 },
    { 112 * 8, 6 * 8, 1 },
    { 124 * 8, 6 * 8, 0 },
    { 138 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 1 },
    { 168 * 8, 6 * 8, 0 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_6_4_ENEMY_COUNT (sizeof(enemy_spawns_6_4) / sizeof(EnemySpawn))
