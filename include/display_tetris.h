#ifndef DISPLAY_TETRIS_H
#define DISPLAY_TETRIS_H

#include <stdlib.h>
#include <stdio.h>

#define RESET_COLOR "\x1b[0m"
#define RED_COLOR "\x1b[31m"
#define GREEN_COLOR "\x1b[32m"
#define YELLOW_COLOR "\x1b[33m"
#define BLUE_COLOR "\x1b[34m"
#define MAGENTA_COLOR "\x1b[35m"
#define CYAN_COLOR "\x1b[36m"
#define WHITE_COLOR "\x1b[37m"

extern int i_block[4][4][4];
extern int t_block[4][4][4];
extern int s_block[4][4][4];
extern int z_block[4][4][4];
extern int l_block[4][4][4];
extern int j_block[4][4][4];
extern int o_block[4][4][4];
extern int next_block_number;
extern int tetris_table[21][10];
extern int block_state;

void display_tetris(void);

#endif // DISPLAY_TETRIS_H
