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

// 외부 전역 변수 main.c 에서 선언
extern int x;
extern int y;
extern int point;
extern int game;

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

#endif // UPDATE_H