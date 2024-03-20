#include "display_tetris.h"
extern int i_block[4][4][4];
extern int t_block[4][4][4];
extern int s_block[4][4][4];
extern int z_block[4][4][4];
extern int l_block[4][4][4];
extern int j_block[4][4][4];
extern int o_block[4][4][4];
extern int next_block_number;

void display_tetris()
{
    int i, j;
    int(*block_pointer)[4][4][4] = NULL;

    switch (next_block_number)
    {
    case 0:
        block_pointer = &i_block;
        break;
    case 1:
        block_pointer = &t_block;
        break;
    case 2:
        block_pointer = &s_block;
        break;
    case 3:
        block_pointer = &z_block;
        break;
    case 4:
        block_pointer = &l_block;
        break;
    case 5:
        block_pointer = &j_block;
        break;
    case 6:
        block_pointer = &o_block;
        break;
    }
    system("clear");
    printf("Next Block\n");
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            if ((*block_pointer)[0][i][j] == 1)
                printf("* ");
            else if ((*block_pointer)[0][i][j] == 0)
                printf("o ");
        }
    }
    printf("\n\n");
    printf("Tetris Table\n");
    for (i = 2; i < 21; i++)
    {
        printf("\t");
        for (j = 0; j < 10; j++)
        {
            if (j == 0 || j == 9)
            {
                printf("│ ");
            }
            else if (i == 20 && (j > 1 || j < 9))
            {
                printf("──");
            }
            else if (tetris_table[i][j] == 1)
                printf("* ");
            else if (tetris_table[i][j] == 0)
                printf("0 ");
        }
        printf("\n");
    }
}
