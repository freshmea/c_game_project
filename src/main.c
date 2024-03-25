/**
 * @file main.c
 * @brief printf함수, signal함수, 타이머, static struct를 활용하기 위한 헤더파일을
 * 포함시켰습니다.
 * game,point, 필드의 크기, 처음 시작했을때 꼬리의길이, 꼬리의 변화를 주는 변수,
 * 게임 시작과 끝을 정의하고 미끼의 위치,snakedirection(sdir), update변수,
 * disdplay_menu변수, display_snake변수를 가져와서 사용했습니다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>

#define GAME_START 0
#define GAME_END 1
#define width 40
#define height 40

int game;
int point = 0;
int x = width / 2;
int y = height / 2;
int entireTail;

extern sdir;
extern void space();
extern int snakeX[100];
extern int snakeY[100];

int update(int signum);
int display_menu();
void display_snake();
/**
 * @brief game_start 함수를 정의하였습니다. itimerval 구조체는
 * POSIX 시스템에서 타이머 값을 설정하고 제어하는 데 사용됩니다.
 * 이 구조체는 시간 간격을 나타내는 두 개의 필드(it.value it.interval)을 포함하며
 * 이 구조체를 정적변수(static struct)화 시켜서 정의했습니다.
 * 또한 signal함수를 사용하여 가상타이머가 끝나면(SIGVTALRM) update함수를 불러오도록
 * 설정하였습니다.
 * 또한 setitmer 함수를 사용하여 타이머를 설정하였고 타이머의 종류(ITIMER_VIRTUAL(가상
 * 타이머)),timer 구조체의 주소(&timer), 이전 타이머의 설정(보통 NULL로 표현한다.)
 * 으로 구성했습니다.
 * 그래서 게임이 끝났을경우 업데이트가 더이상 진행되지 않도록 신호를 보내고 게임을 다시
 * 시작하기 위한 함수(reset)를 불러와서 게임이 끝났다는것(return = 1 <- Game END)을
 * 알릴수 있도록 하였습니다.
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

    display_snake();
    int update();

    while (1)
    {
        if (game == GAME_END)
        {
            signal(SIGVTALRM, SIG_IGN);
            // save_result(point);
            reset();
            return 1;
        }
    }
    game = GAME_END;
}
/**
 * 메인함수의 구성은 메뉴의 변수를 정의하고 menu함수를 불러와서 표시하도록 설정
 * 하였고 메뉴변수의 변화에 따라 switch case문을 사용하여 게임의 시작하거나 기록
 * 을 표시하거나 게임을 빠져나갈수 있도록 설정했습니다.
 */
int main(void)
{
    int menu = 1;
    menu = display_menu();

    switch (menu)
    {
    case 1:
        game = GAME_START;
        display_snake();
        reset();
        menu = game_start();
        break;
    case 2:
        printf("Record\n");
        break;
    case 3:
        printf("Quit\n");
        break;
        return 0;
    }
}
/**
 * reset함수를 정의하여 플레이어가 조종할수 있는 뱀의 시작위치를 표시하였습니다.
 */
void reset()
{
    point = 0;
    x = width / 2;
    y = height / 2;
    snakeX[0] = x;
    snakeY[0] = y;
    space();
}