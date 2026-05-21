// Level 6-2 - overworld with many pipes. Original SMB1 uses
// L_GroundArea4: the area stream is heavy on $7x (pipe) and $6x
// (vertical) objects, ending with the standard flagpole/castle macro.
// Cloud sub-area and water sub-area are omitted; layout is the surface
// portion only, simplified to 8 rows.
#pragma once
#include "level_format.h"

static const char level_6_2_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "      C            C            C            C            C            C            C            C            C            C            C            C            C            C            C            C      ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "              B?B            BBB?BBB                  BBBB                B?BB                  BBBBBB             B?B!B?B               BBBB                 BBBB                BBBB                          ",
    "                                                cc                                   cc                                          cc                cc                       cc                          F       ",
    "  h      L         L            h        L            L     L              L                  L          L      h         L                  L            L      L                h        h         h  P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGKGGGGGG",
};

static const EnemySpawn enemy_spawns_6_2[] = {
    {  20 * 8, 6 * 8, 0 },
    {  22 * 8, 6 * 8, 0 },
    {  36 * 8, 6 * 8, 1 },
    {  50 * 8, 6 * 8, 0 },
    {  64 * 8, 6 * 8, 0 },
    {  66 * 8, 6 * 8, 0 },
    {  82 * 8, 6 * 8, 1 },
    {  96 * 8, 6 * 8, 0 },
    { 110 * 8, 6 * 8, 0 },
    { 112 * 8, 6 * 8, 0 },
    { 128 * 8, 6 * 8, 1 },
    { 142 * 8, 6 * 8, 0 },
    { 158 * 8, 6 * 8, 0 },
    { 172 * 8, 6 * 8, 1 },
    { 184 * 8, 6 * 8, 0 },
};
#define LEVEL_6_2_ENEMY_COUNT (sizeof(enemy_spawns_6_2) / sizeof(EnemySpawn))
