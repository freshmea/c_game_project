#include "utility.h"

struct termios orig_termios;

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// 크레딧 출력 로직
void display_credits()
{
    system("clear");

    printf("\n");
    printf("　　　　　　　　        Sola HONG　Data Manager\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　　　 　Subtitle/Translate\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　　 　　Line Producer\n");
    sleep(1);
    printf("\n");
    printf("　　　　　　　　　　 Haedeun SONG　Production Assistant\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　　 　　Art Design\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　　 　　Tech Engineer\n");
    sleep(1);
    printf("\n");
    printf("　　　　　　　　　　　 Jinwoo LEE　Producer & Director\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　 　　　Motion Graphic Design\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　 　　　Superviser\n");
    sleep(1);
    printf("\n");
    printf("　　　　　　　　　 Hyunjoong YOON　Director\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　 　　　Art Design\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　 　　　Coordinating\n");
    printf("\n");
    sleep(1);
    printf("　　　　　　　　　　　　　　　　　　Present By Team IoT3, Thank you!\n");
    sleep(1);
    printf("\n");
    printf("               🛸　　　 　🌎　°　　🌓　•　　.°•　　　🚀 ✯\n");
    printf("　            　★　*　　　　　°　　　　🛰 　°·　　   🪐\n");
    printf("                           .　　☄ 　•　° ★　 •\n");
    printf("                             ▁▂▃▄▅▆▇▇▆▅▄▃▁▂\n");
    printf("아무키나 누르세요...\n");
    while (getch() == -1)
        ;
}

// 이미지 출력 로직
void display_images()
{
    system("clear");

    for (int img = 0; img < MAX_IMAGES / 8; ++img)
    { // 각 이미지에 대해 반복
        for (int row = 0; row < IMG_HEIGHT; ++row)
        { // 각 이미지의 모든 행에 대해 반복
            for (int i = 0; i < 4; i++)
            {
                // 이미지의 현재 행을 출력
                printf("%s  |  ", images[img + i][row]);
            }
            printf("\n"); // 이미지 간 구분을 위해 빈 줄 추가
        }
        printf("\n"); // 이미지 간 구분을 위해 빈 줄 추가
    }
    printf("메뉴로 이동합니다..아무키나 누르세요.\n");
    while (getch() == -1)
        ;
}
