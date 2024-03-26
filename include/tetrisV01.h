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
#include "result.h"
#include "update.h"


/* 게임 시작, 종료 설정*/
#define GAME_START 0
#define GAME_END 1


// 내부 선언 함수
int init_tetris_table(void); /*테트리스판을 초기화 한다. 벽과 공간을 나눔*/
int game_start(void);        /* 게임 시작시 호출되는 함수.   game변수를 참조하여 게임을 종료하거나 시작함 . 게임 시작시 refresh()함수가 콜백함수로 설정되고 타이머를 등록함. */

// --외부 선언 함수
// display_menu.c
int display_menu(void); /* 메뉴를 보여줌 */
// update.c
int update(int); /* 타이머에 콜백함수로 등록되어 계속 새로고침 하면서 호출되는 함수. 키입력 확인,  화면새로고침, 한줄완성검사등의 계속 상태가 변함을 확인해야 되는 함수를 호출한다 */
// getch.c
int getch(void); /*문자를 바로 입력 받을 수 있는 함수*/

#endif // TETRISV01_H
