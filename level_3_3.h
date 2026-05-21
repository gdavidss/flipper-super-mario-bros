// Level 3-3 - athletic, cloud/bridge over water. Approximated from SMB1 L_GroundArea1.
#pragma once
#include "level_format.h"

static const char level_3_3_src[LEVEL_H][LEVEL_W + 1] = {
    "                                                                                                                                                                                                                ",
    "          C                     C                       C                     C                     C                     C                     C                     C                     C                   ",
    "                                                                                                                                                                                                                ",
    "                      cccc                        ccccc                                                       cccc                                                                         G                    ",
    "                          ?           BBB             !           BBBB                  BBBB?                 BBBB                BBBB?                       BBB                         G                     ",
    "                      BBBB                        BBBBB                   BBB                     BBB                 BBB                             BBBB                BBBB           G              F       ",
    "                                                                                                                                                                                        G               P       ",
    "GGGGGGGGGGGGGGGGGG      GGGGGGGGGGGGGG      GGGGGGGGGGGG    GGGGGGGGGGGGGG      GGGGGGGGGGGGGGGG      GGGGGGGGGGGGGG      GGGGGGGGGGGG      GGGGGGGGGGGGGGGG      GGGGGGGGGGGGGG      GGGGGGGGGGGGGGGGGGKGGGGGGG",
};

static const EnemySpawn enemy_spawns_3_3[] = {
    {  28 * 8, 6 * 8, 0 },
    {  44 * 8, 6 * 8, 1 },
    {  60 * 8, 6 * 8, 0 },
    {  80 * 8, 6 * 8, 0 },
    {  88 * 8, 6 * 8, 1 },
    { 104 * 8, 6 * 8, 0 },
    { 124 * 8, 6 * 8, 0 },
    { 142 * 8, 6 * 8, 1 },
    { 162 * 8, 6 * 8, 0 },
    { 170 * 8, 6 * 8, 0 },
};
#define LEVEL_3_3_ENEMY_COUNT (sizeof(enemy_spawns_3_3) / sizeof(EnemySpawn))
