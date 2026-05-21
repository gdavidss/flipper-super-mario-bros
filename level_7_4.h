// Level 7-4 - castle (Bowser fight). SMB1 area $27 castle, simplified to a
// single brick-ceiling corridor leading to a castle - no firebars or moving
// platforms in this engine, so the difficulty comes from koopas and goombas
// patrolling the gaps.
#pragma once
#include "level_format.h"

static const char level_7_4_src[LEVEL_H][LEVEL_W + 1] = {
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB        ",
    "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB        ",
    "                  B                   B                     B                       B                         B                       B                       B                     B                           ",
    "                  B                   B                     B                       B                         B                       B                       B                     B                           ",
    "                          BBB                 BB                      BB                   cc                     BB                      BBB                                         BB                        ",
    "                           cc                                          cc                 BBB                                              cc                     BB                                    F       ",
    "                                                                                                                                                                                                        P       ",
    "GGGGGGGGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGGGGGGGGGGG    GGGGGGGGGGGGG   GGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_7_4[] = {
    {  18 * 8, 6 * 8, 1 },
    {  26 * 8, 6 * 8, 0 },
    {  38 * 8, 6 * 8, 1 },
    {  50 * 8, 6 * 8, 0 },
    {  64 * 8, 6 * 8, 1 },
    {  76 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 1 },
    { 100 * 8, 6 * 8, 0 },
    { 114 * 8, 6 * 8, 1 },
    { 126 * 8, 6 * 8, 0 },
    { 140 * 8, 6 * 8, 1 },
    { 152 * 8, 6 * 8, 0 },
    { 166 * 8, 6 * 8, 1 },
    { 178 * 8, 6 * 8, 0 },
    { 192 * 8, 6 * 8, 1 },
};
#define LEVEL_7_4_ENEMY_COUNT (sizeof(enemy_spawns_7_4) / sizeof(EnemySpawn))
