#include "update.h"

// 내부 전역 변수
int block_number = 0;      /*현재 블록 넘버 변수*/
int next_block_number = 0; /*다음 블록 넘버 변수 */
int block_state = 0;       /*블록 상태, 회전함에 따라 변한다*/

/*
 * 테트로 미노 블록들(I, T, S, Z, L, J, O) 은
 * 4*4 배열의 2차원 배열로
 * 하나의 모양을 표현 가능.
 *
 * 각 테트로미노 블록은
 *회전할때마다 4개의 상태를 표현하기 위해
 *4*4*4의 3차원 배열이됨
 */
char i_block[4][4][4] =
    {
        {{1, 1, 1, 1},
         {0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 0, 1},
         {0, 0, 0, 1},
         {0, 0, 0, 1},
         {0, 0, 0, 1}},
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {1, 1, 1, 1},
         {0, 0, 0, 0}},
        {{1, 0, 0, 0},
         {1, 0, 0, 0},
         {1, 0, 0, 0},
         {1, 0, 0, 0}}};

char t_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 1, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 0, 0},
         {1, 1, 1, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}}};

char s_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 1, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char z_block[4][4][4] =
    {
        {{0, 1, 0, 0},
         {1, 1, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 1, 0},
         {0, 1, 1, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 0, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char l_block[4][4][4] =
    {
        {{1, 0, 0, 0},
         {1, 0, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 1, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 1, 0, 0},
         {0, 0, 0, 0}},
        {{0, 0, 1, 0},
         {1, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char j_block[4][4][4] =
    {
        {{0, 1, 0, 0},
         {0, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0}},
        {{1, 0, 0, 0},
         {1, 1, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 0, 0, 0},
         {1, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 1, 0},
         {0, 0, 1, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

char o_block[4][4][4] =
    {
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}},
        {{1, 1, 0, 0},
         {1, 1, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 0}}};

/** 타이머에 콜백함수로 등록되어 계속 새로고침 하면서 호출되는 함수.
 * 키입력 확인, 화면새로고침, 한줄완성검사등의 계속 상태가 변함을 확인해야 되는 함수를 호출한다
 */
int update(int signum)
{
    static int downcount = 0;
    static int setcount = 0;
    static long speedcount = 0;
    static int countrange = 5;
    static int firststart = 0;

    char ch;

    srand((unsigned)time(NULL));

    if (firststart == 0)
    {
        block_number = rand() % 7;
        if (firststart == 0)
            firststart++;
    }

    display_tetris_table(&countrange);
    check_one_line();

    if (downcount == countrange - 1)
    {
        point += 1;
        move_block(DOWN);
    }

    if (speedcount == 499)
    {
        if (countrange != 1)
            countrange--;
    }

    downcount++;
    downcount %= countrange;
    speedcount++;
    speedcount %= 500;

    if (x == 3 && y == 0)
    {
        if (collision_test(LEFT) || collision_test(RIGHT) || collision_test(DOWN) || collision_test(ROTATE))
        {
            printf("\n Game End! \n");
            downcount = 0;
            setcount = 0;
            speedcount = 0;
            countrange = 5;
            firststart = 0;
            game = GAME_END;
        }
    }

    if (collision_test(DOWN))
    {
        if (setcount == 9)
        {
            block_number = next_block_number;
            next_block_number = rand() % 7;
            block_state = 0;
            x = 3;
            y = 0;
        }
        setcount++;
        setcount %= 10;
    }

    ch = getch();

    switch (ch)
    {
    case 74:
    case 106:
        move_block(LEFT);
        break;
    case 76:
    case 108:
        move_block(RIGHT);
        break;
    case 75:
    case 107:
        move_block(DOWN);
        break;
    case 73:
    case 105:
        move_block(ROTATE);
        break;
    case 65:
    case 97:
        drop();
        break;
    case 80:
    case 112:
        downcount = 0;
        setcount = 0;
        speedcount = 0;
        countrange = 5;
        firststart = 0;
        game = GAME_END;
        break;
    default:
        break;
    }
    return 0;
}

/*이동, 회전키가 입력되면, 충돌검사후 이동시킨다*/
int move_block(int command)
{
    int i, j;
    int newx, newy;
    int oldx, oldy;
    int old_block_state;
    char(*block_pointer)[4][4][4] = NULL;

    newx = x;
    newy = y;

    old_block_state = block_state;

    if (collision_test(command) == 0)
    {
        switch (command)
        {
        case LEFT:
            newx--;
            break;
        case RIGHT:
            newx++;
            break;
        case DOWN:
            newy++;
            break;
        case ROTATE:
            block_state++;
            block_state %= 4;
            break;
        }
    }
    else
    {
        return 1;
    }

    switch (block_number)
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

    for (i = 0, oldy = y; i < 4; i++, oldy++)
    {
        for (j = 0, oldx = x; j < 4; j++, oldx++)
        {
            if (oldx > 0 && oldx < 9 && oldy < 20 && oldy > 0)
                if ((*block_pointer)[old_block_state][i][j] == 1)
                    tetris_table[oldy][oldx] = 0;
        }
    }

    x = newx;
    y = newy;

    for (i = 0, newy = y; i < 4; i++, newy++)
    {
        for (j = 0, newx = x; j < 4; j++, newx++)
        {
            if (newx > 0 && newx < 9 && newy < 20 && newy > 0)
                if ((*block_pointer)[block_state][i][j] == 1)
                    tetris_table[newy][newx] = (*block_pointer)[block_state][i][j];
        }
    }

    return 0;
}

/* 블록이 이동, 회전하기 전에 충돌되는 블록이나 벽이 없는지 확인하는 함수*/
int collision_test(int command)
{
    int i, j;
    int tempx, tempy;
    int oldx, oldy;
    int temp_block_state;
    char(*block_pointer)[4][4][4];
    char temp_tetris_table[21][10];

    oldx = tempx = x;
    oldy = tempy = y;
    temp_block_state = block_state;

    switch (command)
    {
    case LEFT:
        tempx--;
        break;
    case RIGHT:
        tempx++;
        break;
    case DOWN:
        tempy++;
        break;
    case ROTATE:
        temp_block_state++;
        temp_block_state %= 4;
        break;
    }

    switch (block_number)
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

    for (i = 0; i < 21; i++)
    {
        for (j = 0; j < 10; j++)
        {
            temp_tetris_table[i][j] = tetris_table[i][j];
        }
    }

    for (i = 0, oldy = y; i < 4; i++, oldy++)
    {
        for (j = 0, oldx = x; j < 4; j++, oldx++)
        {
            if (oldx > 0 && oldx < 9 && oldy < 20 && oldy > 0)
            {
                if ((*block_pointer)[block_state][i][j] == 1)
                    temp_tetris_table[oldy][oldx] = 0;
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            if (temp_tetris_table[tempy + i][tempx + j] == 1 && (*block_pointer)[temp_block_state][i][j] == 1)
                return 1;
        }
    }

    return 0;
}

/* 충돌되기 전까지 블록을 다운시킨다.*/
int drop(void)
{
    while (!collision_test(DOWN))
        move_block(DOWN);

    return 0;
}

/* 한줄이 완성되었는지 확인하는 함수. 완성되면 한줄을 지우고, 점수에 1000점을 더한다*/
int check_one_line(void)
{
    int i, j;
    int ti, tj;
    int line_hole;

    for (i = 19; i > 0; i--)
    {
        line_hole = 0;
        for (j = 1; j < 9; j++)
        {
            if (tetris_table[i][j] == 0)
            {
                line_hole = 1;
            }
        }

        if (line_hole == 0)
        {
            point += 1000;
            for (ti = i; ti > 0; ti--)
            {
                for (tj = 0; tj < 9; tj++)
                {
                    tetris_table[ti][tj] = tetris_table[ti - 1][tj];
                }
            }
        }
    }

    return 0;
}
