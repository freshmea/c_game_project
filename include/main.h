
/**
 * @file main.h
 * @brief 테트리스 게임을 실행하는 메인 함수
 * @author 최수길, 김진호, 강민우, 정현우, 김진성
 * @date 2024-3-20
 * @details 이 게임은 signal을 사용해서 1/60 초 마다 화면을 갱신 하는 것을 이용한
 * @details 프로그램입니다.
 */
#ifndef MAIN_H
#define MAIN_H

#include "db.h"
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define GAME_START 0
#define GAME_END 1

void display_menu(int *menu);
int init_tetris_table(void);
/**
 * @brief 이 함수는 signal을 설정하는 함수입니다.
 * @param signum signal 에 연결된 함수에 전달되는 인자
 * @param timer signal을 설정하는 구조체 여기에 갱신 시간을 정한다.
 * @details 이 함수에서는 x, y, point 값을 초기화 시킨다.
 */
int update(int signum);
int game_start(void);
int game;
int x = 3;
int y = 0;
int point = 0;
int tetris_table[21][10];

#endif // MAIN_H