#include <stdio.h>
#include <stdlib.h>
int block[4][4] = {
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}};

void display_tetris()
{
    system("clear");
    printf("Next Block\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (block == 0)
            {
                printf("o ");
            }
            else
            {
                printf("* ");
            }
        }
    }
}
printf("Tetris\n");
}

int display_menu()
{
    int menu;

    system("clear");

    printf("Tetris csk\n");
    printf("-------------------\n");
    printf("\t\tGAME MENU\n");
    printf("-------------------\n");
    printf("1. Game Start\n");
    printf("2. Search history\n");
    printf("3. Record Output\n");
    printf("4. Quit\n");

    scanf("%d", &menu);
    return menu;
}

int main()
{
    int menu = 1;
    menu = display_menu();
    switch (menu)
    {
    case 1:
        printf("Game Start\n");
        display_tetris();
        break;
    case 2:
        printf("Search history\n");
        break;
    case 3:
        printf("Record Output\n");
        break;
    case 4:
        printf("Quit\n");
        break;
    }
    return 0;
}