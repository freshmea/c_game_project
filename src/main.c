#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "utility.h"

int display_menu() {
    int menu;

    system("clear");
    
    printf("\n");
    printf("\033[94m▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ \n");
    printf("\033[94m▧                                                                                 ▧\n");
    printf("\033[94m▧ \033[0m ");
    printf("　　　■ ■ ■ ■ 　 ■ ■ ■ 　　■ ■ 　  ■ 　 ■ ■ ■ 　 　 ■ ■ ■ ■ 　 ■ ■ ■ ■　　     \033[94m▧\n");
    printf("\033[94m▧\033[0m ");
    printf("　　 　■ 　　　　　 ■ 　 　 ■  ■    ■ 　 ■ 　  ■ 　 　 　　■    ■　　  　       \033[94m▧ \n");
    printf("\033[94m▧ \033[0m ");
    printf(" 　　 ■ ■ ■ ■ 　　 ■ 　 　 ■   ■   ■ 　 ■  　 ■ 　 　 ■ ■ ■ 　 ■ ■ ■ ■       　\033[94m▧ \n");
    printf("\033[94m▧  \033[0m ");  
    printf(" 　  ■ 　　　　　 ■ 　 　 ■    ■  ■  　■  　 ■ 　 　 　　■    ■ 　  ■         \033[94m▧ \n");
    printf("\033[94m▧ \033[0m ");
    printf(" 　   ■ 　 　 　 ■ ■ ■ 　　■ 　  ■ ■　　■ ■ ■ 　 　 ■ ■ ■ ■ 　 ■ ■ ■ ■         \033[94m▧ \n");
    printf("\033[94m▧                                                                                 ▧ \n");
    printf("\033[94m▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ \n");// 테투리 색상

    printf("\033[0m");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("　　　　　　　　　　　　　 　 Find the Same Picture\n");
    printf("　　　　　　　　　　　　　 　-----------------------\n");
    printf("　　　　　　　　　　　　　 　 　　   M e n u\n");
    printf("　　　　　　　　　　　　 　  -----------------------\n");
    printf("　　　　　　　　　　　　　　   1.   Game Start\n");
    printf("　　　　　　　　　　　　　   　2.   Card Check\n");
    printf("　　　　　　　　　　　　　　   3.   Credit\n");
    printf("　　　　　　　　　　　　　　   4.   End\n");

    scanf("%d", &menu);
    return menu;
}

int main() {
    srand(time(NULL));
    int choice;

    while (1) {
        choice = display_menu();

        switch(choice) {
            case 1:
                play_game();
                break;
            case 2:
                display_images();
                break;
            case 3:
                display_credits();
                break;
            case 4:
                printf("\033[2J\033[H");
                printf("게임을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다.\n");
                sleep(1);
        }
    }

    return 0;
}
