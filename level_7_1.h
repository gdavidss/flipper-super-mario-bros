// Level 7-1 - overworld. SMB1 area $33 (Bullet Bill turret level). Bullet
// Bills cannot be reproduced in this engine, so we substitute sparse goombas
// and koopas across a long ground-level run with brick clusters and pipes
// approximating the original layout (no turret platforms).
#pragma once
#include "level_format.h"

static const char level_7_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C            C            C            C            C            C            C            C            C            C            C            C            C            C            C                   ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                  BBBB         ?B?         BBBBBB              B?B          BBBB           BBBBB            B!B          BBBB          BBBBBB           ?B?           BBBB                                      ",
    "                                                                                                                                                                                                        F       ",
    "  h     h     h          L              L                  L              h        L              h                  L           h         L                    h        L           h      h        h  P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_7_1[] = {
    {  22 * 8, 6 * 8, 0 },
    {  34 * 8, 6 * 8, 1 },
    {  46 * 8, 6 * 8, 0 },
    {  60 * 8, 6 * 8, 0 },
    {  74 * 8, 6 * 8, 1 },
    {  88 * 8, 6 * 8, 0 },
    { 100 * 8, 6 * 8, 0 },
    { 114 * 8, 6 * 8, 1 },
    { 128 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 1 },
    { 164 * 8, 6 * 8, 0 },
    { 178 * 8, 6 * 8, 0 },
    { 190 * 8, 6 * 8, 1 },
};
#define LEVEL_7_1_ENEMY_COUNT (sizeof(enemy_spawns_7_1) / sizeof(EnemySpawn))
