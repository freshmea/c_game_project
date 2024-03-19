#include <stdio.h>
#include <stdlib.h>
int block[4][4] = {
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0},
    {1, 0, 0, 0}};
int tetris_table[21][10];

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
        printf("\n");
    }
    printf("\n\n");
    printf("Tetris Table\n");
    for (int i = 2; i < 21; i++)
    {
        printf("\t");
        for (int j = 0; j < 10; j++)
        {
            if (j == 0 || j == 9)
            {
                printf("|");
            }
            else if (i == 20 && (j > 1 || j < 9))
            {
                printf("-");
            }
            else if (tetris_table[j][i] == 0)
            {
                printf("o");
            }
            else if (tetris_table[j][i] == 1)
            {
                printf("*");
            }
            printf("\n");
        }
    }
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