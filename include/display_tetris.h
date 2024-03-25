#ifndef DISPLAY_TETRIS_H
#define DISPLAY_TETRIS_H

#include <stdio.h>
#include <stdlib.h>

#define RESET_COLOR   "\x1b[0m"
#define RED_COLOR     "\x1b[31m"
#define GREEN_COLOR   "\x1b[32m"
#define YELLOW_COLOR  "\x1b[33m"
#define BLUE_COLOR    "\x1b[34m"
#define MAGENTA_COLOR "\x1b[35m"
#define CYAN_COLOR    "\x1b[36m"
#define WHITE_COLOR   "\x1b[37m"

int block[4][4][4] = {
    {{1, 1, 1, 1},
     {0, 0, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    {{0, 0, 0, 1},
     {0, 0, 0, 1},
     {0, 0, 0, 1},
     {0, 0, 0, 1}},
    {{0, 0, 0, 0},
     {0, 0, 0, 0},
     {1, 1, 1, 1},
     {0, 0, 0, 0}},
    {{1, 0, 0, 0},
     {1, 0, 0, 0},
     {1, 0, 0, 0},
     {1, 0, 0, 0}}};

int tetris_table[21][10];
extern int block_state;
#endif // DISPLAY_TETRIS_H
