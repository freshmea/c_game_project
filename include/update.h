#ifndef UPDATE_H
#define UPDATE_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define GAME_START 0
#define GAME_END 1

/* 방향키, 회전키 설정*/
enum Direction
{
    LEFT,
    RIGHT,
    DOWN,
    ROTATE
};
/* 테트로 미노 블록넘버 설정*/
enum BlockType
{
    I_BLOCK,
    T_BLOCK,
    S_BLOCK,
    Z_BLOCK,
    L_BLOCK,
    J_BLOCK,
    O_BLOCK
};
/*
 * 테트로 미노 블록들(I, T, S, Z, L, J, O) 은
 * 4*4 배열의 2차원 배열로
 * 하나의 모양을 표현 가능.
 *
 * 각 테트로미노 블록은
 *회전할때마다 4개의 상태를 표현하기 위해
 *4*4*4의 3차원 배열이됨
 */

char i_block[4][4][4] =
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
         {1, 0, 0, 0}}};

char t_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 1, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 0, 0},
         {1, 1, 1, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}}};

char s_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 1, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char z_block[4][4][4] =
    {
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 1, 0},
         {0, 1, 1, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 0, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char l_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 0, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 1, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 1, 0},
         {1, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char j_block[4][4][4] =
    {
        {{0, 1, 0, 0},
         {0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 0, 0, 0},
         {1, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 0, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 1, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char o_block[4][4][4] =
    {
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

extern char tetris_table[21][10]; /* 테트리스 판의 상태를 저장하는 배열*/
int block_number = 0;             /*현재 블록 넘버 변수*/
int next_block_number = 0;        /*다음 블록 넘버 변수 */
int block_state = 0;              /*블록 상태, 회전함에 따라 변한다*/
extern int x, y;                  /*블록이 현재 테트리스판 어디에 위치해 있는지 알려주는 변수*/
extern int game;                  /*게임 상태 변수, 게임이 시작되거나 종료됨에 따라 변한다*/
extern int best_point;            /* 게임 최고 점수를 알려주는 변수*/
extern long point;                /* 현재 게임중 득점을 알려주는 변수 */

int display_tetris_table(int *); /* 현재의 테트리스판을 보여준다. 블록이 놓이고 쌓인 현재 상태를 보여줌*/
int move_block(int);             /*이동, 회전키가 입력되면, 충돌검사후 이동시킨다*/
int drop(void);                  /* 충돌되기 전까지 블록을 다운시킨다.*/
int collision_test(int);         /* 블록이 이동, 회전하기 전에 충돌되는 블록이나 벽이 없는지 확인하는 함수*/
int check_one_line(void);        /* 한줄이 완성되었는지 확인하는 함수. 완성되면 한줄을 지우고, 점수에 1000점을 더한다*/
int getch(void);                 /*문자를 바로 입력 받을 수 있는 함수*/
#endif                           // UPDATE_H