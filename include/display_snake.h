/**
 * @file display_snake.h
 * @brief printf,signal,clear함수와 count변수와 시간을 표시하기
 * 위한 헤더파일을 표시했습니다.
 * @brief 플레이어의 뱀의 기본크기를 정의하였고 먹이의 크기 필드의크기
 * 포인트 꼬리의전체크기변수와 꼬리의 변화배열을 가져와 표시했습니다.
 */


#ifndef DISPLAY_SNAKE_H
#define DISPLAY_SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 40

extern int count;
extern int x;
extern int y;
extern int baitX;
extern int baitY;
extern int entireTail;
extern int point;
extern int snakeX[100];
extern int snakeY[100];
int snakeTable[HEIGHT][WIDTH];

/**
 * @brief display_snake(필드구성함수)를 정의했습니다
게임을 시작했을때 기존의 화면을 지우고 새로운 화면을 만들기 위한 system(clear)함수를 사용하였고
게임 영역의 상단을 나타내는 '@' 문자들을 출력합니다.
또한 이중 루프를 사용하여 게임 영역의 각 셀을 반복하면서

왼쪽 벽('@' 문자)을 출력합니다.
현재 셀이 뱀의 머리인 경우 'O'를 출력합니다.
현재 셀이 먹이인 경우 'P'를 출력합니다.
그렇지 않은 경우:
뱀 꼬리가 존재하는지 확인하고, 꼬리가 있는 경우 'o'를 출력합니다.
꼬리가 없는 경우 빈 공간을 출력합니다.
오른쪽 벽('@' 문자)을 출력합니다.
현재 점수와 시간, 꼬리의 길이를 실시간으로 표시합니다.
*/
void display_snake();

#endif // DISPLAY_SNAKE_H