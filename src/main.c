#include "game.h"

int display_menu()
{
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
    printf("\033[94m▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ ▧ \n"); // 테투리 색상

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
    printf("　　　　　　　　　　　　　   　3.   Search Record\n");
    printf("　　　　　　　　　　　　　   　4.   show all Record\n");
    printf("　　　　　　　　　　　　　　   5.   Credit\n");
    printf("　　　　　　　　　　　　　　   6.   End\n");

    scanf("%d", &menu);
    return menu;
}

int main()
{
    srand(time(NULL));
    int choice;

    while (1)
    {
        choice = display_menu();
        switch (choice)
        {
        case 1:
            play_game();
            break;
        case 2:
            display_images();
            break;
        case 3:
            read_db();
            break;
        case 4:
            show_all_db();
            break;
        case 5:
            display_credits();
            break;
        case 6:
            system("clear");
            printf("게임을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다.\n");
            sleep(1);
        }
        while (getch() == -1)
            ;
    }

    return 0;
}
