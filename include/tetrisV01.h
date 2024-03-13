#ifndef TETRISV01_H
#define TETRISV01_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <time.h>

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

/* 게임 시작, 종료 설정*/
#define GAME_START 0
#define GAME_END 1

/* 테트리스 판을 2차원 배열로 표현
 * 양옆 2줄과 맨 아래 한줄은 벽
 * 따라서  20*8 이
 * 실제 테트로미노 블록들이
 * 움직이고 놓이는 공간이됨*/
char tetris_table[21][10];

int x = 3, y = 0;    /*블록이 현재 테트리스판 어디에 위치해 있는지 알려주는 변수*/
int game = GAME_END; /*게임 상태 변수, 게임이 시작되거나 종료됨에 따라 변한다*/
int best_point = 0;  /* 게임 최고 점수를 알려주는 변수*/
long point = 0;      /* 현재 게임중 득점을 알려주는 변수 */

int display_menu(void);      /* 메뉴를 보여줌 */
int init_tetris_table(void); /*테트리스판을 초기화 한다. 벽과 공간을 나눔*/

int game_start(void);       /* 게임 시작시 호출되는 함수.   game변수를 참조하여 게임을 종료하거나 시작함 . 게임 시작시 refresh()함수가 콜백함수로 설정되고 타이머를 등록함. */
int update(int);            /* 타이머에 콜백함수로 등록되어 계속 새로고침 하면서 호출되는 함수. 키입력 확인,  화면새로고침, 한줄완성검사등의 계속 상태가 변함을 확인해야 되는 함수를 호출한다 */
int print_result(void);     /* 메뉴에서 기록출력시 호출되어 기록을 출력하는 함수*/
int search_result(void);    /*메뉴에서 기록검색시 호출되어 기러고을 검색하는 함수*/
int save_result(long, int); /*게임종료시 호출되어 기록을 저장하는 함수*/
int getch(void);            /*문자를 바로 입력 받을 수 있는 함수*/

#endif // TETRISV01_H
