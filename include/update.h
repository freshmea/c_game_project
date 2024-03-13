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
extern char i_block[4][4][4];
extern char t_block[4][4][4];
extern char s_block[4][4][4];
extern char z_block[4][4][4];
extern char l_block[4][4][4];
extern char j_block[4][4][4];
extern char o_block[4][4][4];

extern char tetris_table[21][10]; /* 테트리스 판의 상태를 저장하는 배열*/
extern int block_number;          /*현재 블록 넘버 변수*/
extern int next_block_number;     /*다음 블록 넘버 변수 */
extern int block_state;           /*블록 상태, 회전함에 따라 변한다*/
extern int x, y;                  /*블록이 현재 테트리스판 어디에 위치해 있는지 알려주는 변수*/
extern int game;                  /*게임 상태 변수, 게임이 시작되거나 종료됨에 따라 변한다*/
extern int best_point;            /* 게임 최고 점수를 알려주는 변수*/
extern long point;                /* 현재 게임중 득점을 알려주는 변수 */

#endif // UPDATE_H