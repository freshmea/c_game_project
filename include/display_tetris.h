/**
 * @file display_tetris.h
 * @brief 테트리스 게임의 출력을 담당하는 헤더 파일
 * @details 테트리스 게임의 출력을 담당하는 함수들을 선언한다.
 * @date 2021-03-21
 * @author 최수길, 김진호, 강민우, 정현우
 */

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

/**
 * @brief update 함수에서 호출되는 게임 정보를 출력하는 함수
 * @details 다음 블록을 출력하고, 색상을 입힌다.
 */
void display_tetris(void);

#endif // DISPLAY_TETRIS_H
