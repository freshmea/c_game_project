#include <stdio.h>
#include <stdlib.h>

extern char i_block[4][4][4];
extern char t_block[4][4][4];
extern char s_block[4][4][4];
extern char z_block[4][4][4];
extern char l_block[4][4][4];
extern char j_block[4][4][4];
extern char o_block[4][4][4];

extern char tetris_table[21][10];
extern int next_block_number;
extern int block_number;
extern int block_state;
extern int x, y;
extern int game;
extern int best_point;
extern long point;

enum Direction
{
    LEFT,
    RIGHT,
    DOWN,
    ROTATE
};

enum BlockType
{
    I_BLOCK,
    T_BLOCK,
    S_BLOCK,
    Z_BLOCK,
    L_BLOCK,
    J_BLOCK,
    O_BLOCK
};

/* 현재의 테트리스판을 보여준다. 블록이 놓이고 쌓인 현재 상태를 보여줌*/
int display_tetris_table(int countrange)
{
    int i, j;
    char(*block_pointer)[4][4][4] = NULL;

    switch (next_block_number)
    {
    case I_BLOCK:
        block_pointer = &i_block;
        break;
    case T_BLOCK:
        block_pointer = &t_block;
        break;
    case S_BLOCK:
        block_pointer = &s_block;
        break;
    case Z_BLOCK:
        block_pointer = &z_block;
        break;
    case L_BLOCK:
        block_pointer = &l_block;
        break;
    case J_BLOCK:
        block_pointer = &j_block;
        break;
    case O_BLOCK:
        block_pointer = &o_block;
        break;
    }

    system("clear");

    printf("\n Score: %ld | Speed: %d | highest score: %d", point, countrange, best_point);
    printf("\n\n Next Block\n");

    for (i = 0; i < 4; i++)
    {
        printf("\n ");
        for (j = 0; j < 4; j++)
        {
            if ((*block_pointer)[0][i][j] == 1)
                printf("#");
            else if ((*block_pointer)[0][i][j] == 0)
                printf(" ");
        }
    }

    for (i = 2; i < 21; i++)
    {
        printf("\t");
        for (j = 0; j < 10; j++)
        {
            if (j == 0 || j == 9 || (i == 20 && (j > 1 || j < 9)))
            {
                printf("@");
            }
            else if (tetris_table[i][j] == 1)
                printf("#");
            else if (tetris_table[i][j] == 0)
                printf(" ");
        }
        printf("\n");
    }
    printf("\n GAME STOP : P");
    return 0;
}
