// Level 5-2 - Athletic (SMBDIS L_GroundArea18 / E_GroundArea18).
// Original 5-2 is the cloud/sky athletic course over water. Our renderer has
// no cloud-tile platforms, so we approximate the athletic feel with a string
// of short ground islands separated by pits, with floating brick stepping
// stones and elevated brick/q-block platforms above each gap.
#pragma once
#include "level_format.h"

static const char level_5_2_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "     C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C          C               ",
    "             C            C            C            C            C            C            C            C            C            C            C            C            C            C            C            ",
    "                                         c                                               c                                               c                                               c                      ",
    "                                        B?B                                             B?B                                             B?B                                             B?B                     ",
    "                BBB             BBB             BBB             BBB             BBB             BBB             BBB             BBB             BBB             BBB             BBB             BBB     F       ",
    "   h                                                                                                                                                                                                    P       ",
    "GGGGGGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGGGGGGGG    GGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_5_2[] = {
    {   8 * 8, 6 * 8, 0 },
    {  24 * 8, 6 * 8, 0 },
    {  40 * 8, 6 * 8, 1 },
    {  56 * 8, 6 * 8, 0 },
    {  72 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 0 },
    { 104 * 8, 6 * 8, 1 },
    { 120 * 8, 6 * 8, 0 },
    { 136 * 8, 6 * 8, 0 },
    { 152 * 8, 6 * 8, 0 },
    { 168 * 8, 6 * 8, 1 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_5_2_ENEMY_COUNT (sizeof(enemy_spawns_5_2) / sizeof(EnemySpawn))
