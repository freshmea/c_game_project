#ifndef DISPLAY_TETRIS_H
#define DISPLAY_TETRIS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "update.h"

// 내부 함수 선언
int display_tetris_table(int *);

// 외부 참조 변수
// update.h
extern char i_block[4][4][4];
extern char t_block[4][4][4];
extern char s_block[4][4][4];
extern char z_block[4][4][4];
extern char l_block[4][4][4];
extern char j_block[4][4][4];
extern char o_block[4][4][4];
extern int next_block_number;
// tetrisV01.h
extern long point;
extern int best_point;
extern char tetris_table[21][10];

#endif // DISPLAY_TETRIS_H