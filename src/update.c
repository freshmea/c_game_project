#include <stdio.h>
extern int x;
extern int y;
int block_state = 0;

// #define DOWN 0
// #define LEFT 1
// #define RIGHT 2
// #define ROTATE 3
typedef enum
{
    DOWN,
    LEFT,
    RIGHT,
    ROTATE
} COMMAND;

int test = 0;
int update(int signum)
{
    display_tetris();
    test++;
    printf("%d\n", test);
}

int move_block(int command)
{
    int i, j;
    int newx, newy;
    int oldx, oldy;
    int old_block_state;

    newx = x;
    newy = y;
    old_block_state = block_state;

    if (collision_test(command) == 0)
    {
        switch (command)
        {
        case DOWN:
            newy++;
            break;
        case LEFT:
            newx--;
            break;
        case RIGHT:
            newx++;
            break;
        case ROTATE:
            block_state++;
            if (block_state > 3)
            {
                block_state = 0;
            }
            break;
        }
    }

    // tetris_table 의 old_block 제거
    for (i = 0, oldy = y; i < 4; i++, oldy++)
    {
        for (j = 0, oldx = x; j < 4; j++, oldx++)
        {
            if (block[old_block_state][i][j] == 1)
            {
                tetris_table[oldy][oldx] = 0;
            }
        }
    }
}