// Level 5-3 - Overworld (SMBDIS L_GroundArea7 / E_GroundArea7).
// Original 5-3 features rows of Bullet Bill cannons. We have no Bullet Bills,
// so the cannons are stand-in single-brick pillars (some stacked two tall)
// with sparse goombas patrolling between them.
#pragma once
#include "level_format.h"

static const char level_5_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "       C             C             C             C             C             C             C             C             C             C             C             C             C             C                  ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                      ?         BBB             B?B                   BBBB                    ?B?B?                 BBBB                    BB                  BBBB                ?                           ",
    "                                                  cc            B                                   ccc     B                                    cc     B                                               F       ",
    " h          h             L             B                 L     B             B     L                       B               B   L                       B               L     B                 B     h P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_5_3[] = {
    {  20 * 8, 6 * 8, 0 },
    {  34 * 8, 6 * 8, 0 },
    {  46 * 8, 6 * 8, 1 },
    {  56 * 8, 6 * 8, 0 },
    {  72 * 8, 6 * 8, 0 },
    {  82 * 8, 6 * 8, 0 },
    { 100 * 8, 6 * 8, 1 },
    { 114 * 8, 6 * 8, 0 },
    { 122 * 8, 6 * 8, 0 },
    { 144 * 8, 6 * 8, 0 },
    { 158 * 8, 6 * 8, 1 },
    { 172 * 8, 6 * 8, 0 },
    { 184 * 8, 6 * 8, 0 },
    { 194 * 8, 6 * 8, 0 },
};
#define LEVEL_5_3_ENEMY_COUNT (sizeof(enemy_spawns_5_3) / sizeof(EnemySpawn))
