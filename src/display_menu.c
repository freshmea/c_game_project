/**
 * @file:display_menu.c
 * @brief printf, scanf, system함수를 사용하기 위해 불러온
 * 헤더파일들입니다.
 */

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief display_menu함수는 menu변수를 정의하고 화면을 초기하고
 * 게임메뉴들을 표시해주는 함수입니다.
 */
int display_menu()
{
    int menu;

    system("clear");

    printf("\n\n\n");

    printf("  SSSS  N   N   AAA   K   k  EEEEE    GGG    AAA   M   M  EEEEE\n");
    printf(" S      NN  N  A   A  K  K   E       G      A   A  MM MM  E    \n");
    printf("  SSS   N N N  AAAAA  KK     EEEE    GGGG   AAAAA  M M M  EEEE \n");
    printf("     S  N  NN  A   A  K  K   E      G    G  A   A  M   M  E    \n");
    printf(" SSSS   N   N  A   A  K   K  EEEEE   GGGG   A   A  M   M  EEEEE\n");

    printf("\tWelcome to Snake Game!\n");

    printf("------------------------------------------------------\n");
    printf("\tAre You Ready To Play The Snake Game?\n");
    printf("------------------------------------------------------\n");
    printf("\t\tGAME MENU\n");
    printf("------------------------------------------------------\n");
    printf("\t\t1. Game Start\n");
    printf("\t\t2. find Record\n");
    printf("\t\t3. show all Record\n");
    printf("\t\t4. Quit\n");
    printf("------------------------------------------------------\n");

    printf("Press any key to start...\n");

    scanf("%d", &menu);
    return menu;
}