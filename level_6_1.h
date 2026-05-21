// Level 6-1 - overworld. Original SMB1 uses L_GroundArea15 with Lakitu
// throwing spinies; this port has no Lakitu so the difficulty is conveyed
// with packs of koopas and goombas across stair/platform clusters.
// Geometry follows the area-15 object stream: ground holes, brick
// stacks, ?-blocks, scattered pipes and a final flagpole+castle.
#pragma once
#include "level_format.h"

static const char level_6_1_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "        C            C            C            C            C            C            C            C            C            C            C            C            C            C            C                 ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "                       B?BB                  BB?BB              BBBB                   B?B          BBBBB              B?B?B               BBBB                BBBB                  BBBB                       ",
    "                                                       cc                cc                                  cc                       cc            cc                                                    F     ",
    "  h        h               L              L                  L                 h         L                                  L                          L              L          h     h           h      P     ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG     GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGG",
};

static const EnemySpawn enemy_spawns_6_1[] = {
    {  18 * 8, 6 * 8, 1 },
    {  28 * 8, 6 * 8, 0 },
    {  30 * 8, 6 * 8, 0 },
    {  48 * 8, 6 * 8, 1 },
    {  62 * 8, 6 * 8, 0 },
    {  64 * 8, 6 * 8, 0 },
    {  82 * 8, 6 * 8, 1 },
    {  96 * 8, 6 * 8, 0 },
    {  98 * 8, 6 * 8, 0 },
    { 114 * 8, 6 * 8, 1 },
    { 128 * 8, 6 * 8, 0 },
    { 144 * 8, 6 * 8, 1 },
    { 158 * 8, 6 * 8, 0 },
    { 160 * 8, 6 * 8, 0 },
    { 176 * 8, 6 * 8, 1 },
    { 188 * 8, 6 * 8, 0 },
};
#define LEVEL_6_1_ENEMY_COUNT (sizeof(enemy_spawns_6_1) / sizeof(EnemySpawn))
