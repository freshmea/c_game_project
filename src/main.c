/**
 * @file main.c
 * @brief 테트리스 게임을 실행하는 메인 함수
 * @author 최수길
 * @date 2024-3-20
 * @details 이 게임은 signal을 사용해서 1/60 초 마다 화면을 갱신 하는 것을 이용한
 * 프로그램입니다.
 */

#include "db.h"
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define GAME_START 0
#define GAME_END 1

int display_menu();
void display_tetris();
int game;
int update(int signum);
int x = 3;
int y = 0;
int point = 0;
extern int tetris_table[21][10];
void save_result(int);
int print_result(void);
int print_color();
char q;

/**
 * @brief 이 함수는 signal을 설정하는 함수입니다.
 * @param signum signal 에 연결된 함수에 전달되는 인자
 * @param timer signal을 설정하는 구조체 여기에 갱신 시간을 정한다.
 * @details 이 함수에서는 x, y, point 값을 초기화 시킨다.
 */
int game_start()
{
    // signal 설정
    static struct itimerval timer;
    signal(SIGVTALRM, update);
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 16667;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 16667;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while (1)
    {
        if (game == GAME_END)
        {
            signal(SIGVTALRM, SIG_IGN);
            // save_result(point);
            write_db(point);
            x = 3;
            y = 0;
            point = 0;
            return 1;
        }
    }
    game = GAME_END;
}

int main()
{
    int menu = 1;
    menu = display_menu();
    switch (menu)
    {
    case 1:
        game = GAME_START;
        init_tetris_table();
        menu = game_start();
        break;
    case 2:
        printf("Search history\n");
        init_db();
        read_db();
        close_db();
        break;
    case 3:
        printf("Record Output\n");
        // print_result();
        break;
    case 4:
        printf("Quit\n");
        break;
    }
    return 0;
}

int init_tetris_table()
{
    int i, j;
    // 모든 데이터에 0을 넣는다.
    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tetris_table[i][j] = 0;
        }
    }
    // 맨 아래칸에 1 추가 (바닥)
    for (j = 1; j < 9; j++)
    {
        tetris_table[20][j] = 1;
    }
    // 양 옆에 1 추가 (벽)
    for (i = 0; i < 21; i++)
    {
        tetris_table[i][0] = 1;
        tetris_table[i][9] = 1;
    }
}
