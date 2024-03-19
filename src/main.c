#include <stdio.h>
int display_menu();
void display_tetris();

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