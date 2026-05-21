// Level 7-3 - SMB1 area $27/bridge level. Mario crosses a series of bridges
// over water; this engine has no water, so falls into the gaps simply remove
// Mario like any pit. Brick segments serve as the bridge planks, with koopas
// and goombas crossing on top.
#pragma once
#include "level_format.h"

static const char level_7_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "        C                  C                  C                  C                  C                  C                  C                  C                  C                  C                            ",
    "                                                                                                                                                                                                                ",
    "                                                                                                                                                                                                                ",
    "               ?B?                  BB?B                B!B                  BBBB                B?B                   BB?BB                BBBB                 B?B                                            ",
    "                                                                                                                                                                                                        F       ",
    "  h        h                  h                h                  h                h                  h                h                  h                h         h                                  P       ",
    "GGGGGGGGGGGGBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBB    BBBBBBBBBBBBGGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_7_3[] = {
    {  20 * 8, 6 * 8, 1 },
    {  32 * 8, 6 * 8, 1 },
    {  46 * 8, 6 * 8, 0 },
    {  60 * 8, 6 * 8, 1 },
    {  74 * 8, 6 * 8, 1 },
    {  88 * 8, 6 * 8, 0 },
    { 102 * 8, 6 * 8, 1 },
    { 116 * 8, 6 * 8, 1 },
    { 130 * 8, 6 * 8, 0 },
    { 144 * 8, 6 * 8, 1 },
    { 158 * 8, 6 * 8, 1 },
    { 172 * 8, 6 * 8, 0 },
    { 186 * 8, 6 * 8, 1 },
};
#define LEVEL_7_3_ENEMY_COUNT (sizeof(enemy_spawns_7_3) / sizeof(EnemySpawn))
