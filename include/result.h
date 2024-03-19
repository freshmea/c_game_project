#ifndef RESULT_H
#define RESULT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


/** 게임 종료때 마다
 * 이름과 득점점수와
 * 날짜, 시간이저장되는 구조체
 */
static struct result
{
    char name[30];
    long point;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int rank;
} temp_result;

// 내부 함수 선언
int print_result(void);     /* 메뉴에서 기록출력시 호출되어 기록을 출력하는 함수*/
int search_result(void);    /*메뉴에서 기록검색시 호출되어 기러고을 검색하는 함수*/
int save_result(long, int); /*게임종료시 호출되어 기록을 저장하는 함수*/

// 외부 함수 선언
// getch.c
int getch(void); /*문자를 바로 입력 받을 수 있는 함수*/
#endif // RESULT_H