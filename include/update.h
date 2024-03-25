/**
 * @file update.h
 * @brief 테트리스 게임의 내부 로직을 담당하는 헤더 파일
 * @details signal을 받아서 게임을 진행한다.
 * @details 1/60 초 마다 실행이 된다.

*/

#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "display_tetris.h"

#define GAME_START 0
#define GAME_END 1

typedef enum
{
    DOWN,
    LEFT,
    RIGHT,
    ROTATE
} COMMAND;

extern int x;
extern int y;
extern int block[4][4][4];
extern int point;
extern int tetris_table[21][10];
extern int game;

int block_state = 0;
int block_number;
int next_block_number;

/**
 * @brief 테트리스 게임의 내부 로직 함수
 * @details signal을 받아서 게임을 진행한다.
 * @details 1/60 초 마다 실행이 된다.
 */
int update(int signum);
/**
 * @brief 이동, 회전키가 입력되면, 충돌검사후 이동시킨다.
 */
int move_block(int command);
/**
 * @brief 블록이 이동, 회전하기 전에 충돌되는 블록이나 벽이 없는지 확인하는 함수
 */
int collision_test(int command);
/**
 * @brief 충돌되기 전까지 블록을 다운시킨다.
 */
int drop(void);
/**
 * @brief 한줄이 완성되었는지 확인하는 함수. 완성되면 한줄을 지우고, 점수에 1000점을 더한다
 */
int check_one_line(void);

char getch();

int i_block[4][4][4] =
    {
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
         {1, 0, 0, 0}}

};

int t_block[4][4][4] =
    {
        {{2, 0, 0, 0},
         {2, 2, 0, 0},
         {2, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 2, 0, 0},
         {2, 2, 0, 0},
         {0, 2, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 0, 0},
         {2, 2, 2, 0},
         {0, 2, 0, 0},
         {0, 0, 0, 0}},
        {{0, 2, 0, 0},
         {2, 2, 0, 0},
         {0, 2, 0, 0},
         {0, 0, 0, 0}}

};

int s_block[4][4][4] =
    {
        {{3, 0, 0, 0},
         {3, 3, 0, 0},
         {0, 3, 0, 0},
         {0, 0, 0, 0}},
        {{0, 3, 3, 0},
         {3, 3, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 3, 0, 0},
         {0, 3, 3, 0},
         {0, 0, 3, 0},
         {0, 0, 0, 0}},
        {{3, 3, 0, 0},
         {0, 3, 3, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}

};

int z_block[4][4][4] =
    {
        {{0, 4, 0, 0},
         {4, 4, 0, 0},
         {4, 0, 0, 0},
         {0, 0, 0, 0}},
        {{4, 4, 0, 0},
         {0, 4, 4, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 4, 0},
         {0, 4, 4, 0},
         {0, 4, 0, 0},
         {0, 0, 0, 0}},
        {{4, 4, 0, 0},
         {4, 0, 4, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}

};

int l_block[4][4][4] =
    {
        {{5, 0, 0, 0},
         {5, 0, 0, 0},
         {5, 5, 0, 0},
         {0, 0, 0, 0}},
        {{5, 5, 5, 0},
         {5, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{5, 5, 0, 0},
         {0, 5, 0, 0},
         {0, 5, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 5, 0},
         {5, 5, 5, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}

};

int j_block[4][4][4] =
    {
        {{0, 6, 0, 0},
         {0, 6, 0, 0},
         {6, 6, 0, 0},
         {0, 0, 0, 0}},
        {{6, 0, 0, 0},
         {6, 6, 6, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{6, 6, 0, 0},
         {6, 0, 0, 0},
         {6, 0, 0, 0},
         {0, 0, 0, 0}},
        {{6, 6, 6, 0},
         {0, 0, 6, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}

};

int o_block[4][4][4] =
    {
        {{7, 7, 0, 0},
         {7, 7, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{7, 7, 0, 0},
         {7, 7, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{7, 7, 0, 0},
         {7, 7, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{7, 7, 0, 0},
         {7, 7, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}

};

#endif // UPDATE_H