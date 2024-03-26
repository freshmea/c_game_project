#include "display_snake.h"

void display_snake()
{
    system("clear");
    // ceiling print
    printf("********************************\n");
    printf("Snake Game || POINT: %d\n", point);
    printf("********************************\n");
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (snakeTable[i][j] == 1)
                printf("🐍");
            else if (i == 0 || i == HEIGHT - 1)
            {
                printf("■ ");
            }
            else if (j == 0 || j == WIDTH - 1)
            {
                printf("■ ");
            }
            else if (snakeTable[i][j] == 2)
            {
                printf("🍎");
            }
            else
                printf("□ ");
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Your Point : %d\n", point);
    printf("\n\n");
    printf("Timer : %d\n", ++count);
    printf("\n\n");
    printf("tail : %d\n", entireTail);
}