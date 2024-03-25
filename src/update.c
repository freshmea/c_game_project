#include "update.h"

void space()
{
    srand(time(NULL));

    baitX = rand() % (HEIGHT - 2) + 1;
    baitY = rand() % (WIDTH - 2) + 1;

    for (int i = 0; i < entireTail; i++)
    {
        if (baitX == snakeX[i] && baitY == snakeY[i])
        {
            baitX = rand() % (HEIGHT - 2) + 1;
            baitY = rand() % (WIDTH - 2) + 1;
        }
    }
    snakeTable[baitY][baitX] = 2;
}

int move_snake(int sdir)
{
    switch (sdir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;
    }

    // snakeTable 갱신
    int i = 0;
    for (i = 0; i < entireTail + 1; i++)
    {
        // 기존 뱀 데이터 삭제
        snakeTable[snakeY[i]][snakeX[i]] = 0;
    }

    for (i = 0; i < entireTail; i++)
    {
        // 뱀 데어터 갱신
        snakeX[entireTail - i] = snakeX[entireTail - i - 1];
        snakeY[entireTail - i] = snakeY[entireTail - i - 1];
    }
    snakeX[0] = x;
    snakeY[0] = y;
    for (i = 0; i < entireTail + 1; i++)
    {
        // 신규 데이터 등록
        snakeTable[snakeY[i]][snakeX[i]] = 1;
    }
    return 0;
}

void collison()
{
    if (x == baitX && y == baitY)
    {
        ++point;
        ++entireTail;
        space();
    }
}

void update(int signum)
{
    int ch;
    int sdir;
    ch = getch();
    switch (ch)
    {
    case 'i':
        sdir = UP;
        break;
    case 'j':
        sdir = LEFT;
        break;
    case 'k':
        sdir = DOWN;
        break;
    case 'l':
        sdir = RIGHT;
        break;
    case 's':
        game = GAME_END;
        break;
    }
    move_snake(sdir);

    ++count;
    display_snake();
    collison();
    // gameover if snake touch wall
    if (x == 0)
    {
        game = GAME_END;
    }
    if (y == 0)
    {
        game = GAME_END;
    }
    if (x == WIDTH - 1)
    {
        game = GAME_END;
    }
    if (y == HEIGHT - 1)
    {
        game = GAME_END;
    }
}