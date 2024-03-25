/**
 * @file update.h
 * @brief rand와 srand,time함수,출력함수,signal함수를 사용하기 위한 헤더파일들을 출력했습니다.
 * GAME START, GAME END을 정의하고 미끼의 생성,처음 생성된 미끼의
 * 길이와 높이를 정의했습니다. 또한 게임 플레이 시간을 계산하는 count변수와 미끼의 위치 미끼를
  섭취했을때의 꼬리의 변화를 정의하고(bait,snakeX,Y) 필드의 크기와 게임 포인트 꼬리의 크기변수
  를 가져와서(extern) 활용하였습니다.
*/

#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

#define GAME_START 0
#define GAME_END 1
#define WIDTH 40
#define HEIGHT 40

extern int x;
extern int y;
extern int game;
extern int point;
extern int entireTail;
extern int snakeTable[HEIGHT][WIDTH];

/**
 * @example typedef함수를 사용하여 STOP LEFT RIGHT UP DOWN이란 단어의 데이터타입을
 * 정의하고 sdir(snake direction)구조체 집합 구성요소로 정의하였습니다.
 */
typedef enum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} SDIR;

int count;
int baitX;
int baitY;
int snakeX[100];
int snakeY[100];

/**
 * @brief 먹이를 생성하는 함수
 */
void space();

/**
 * @brief move_snake함수를 정의하였습니다. 위에 정한 구조체 sdir을 변수로 정하고
 * 새로 정의한 newx,newy변수를 활용하여 switch case문으로 플레이어가 조종하는 뱀의
 * 움직임을 정의하였습니다.
 */
int move_snake(int sdir);

/**
 * @brief collision함수는 먹이를 플레이어가 조종하는 뱀이 먹었을때
 * 포인트를 얻고 꼬리의 길이를 업데이트하고 새로운 먹이를 랜덤한 위치에
 * 스폰할수 있도록 정의했습니다.
 */
void collision();

/**
 * @brief 게임로직을 정의한 함수입니다.
 */
void update(int);

int getch(void);
void display_snake();
#endif // UPDATE_H