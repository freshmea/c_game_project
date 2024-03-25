#include <stdio.h>
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
    int block_color; // 인트 블럭 색상 선언

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

    // 터미널 화면을 지우고 다음 블록 출력
    system("clear");
    printf("Next Block\n");

    //블록 출력 시작
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            // 블록이 있는 경우 해당 색상으로 출력합니다.
            if ((*block_pointer)[0][i][j] == 1)
            {
                printf(RED_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 2){
                printf(GREEN_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 3){
                printf(YELLOW_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 4){
                printf(BLUE_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 5){
                printf(MAGENTA_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 6){
                printf(CYAN_COLOR "■ " RESET_COLOR);
            }else if ((*block_pointer)[0][i][j] == 7){
                printf(WHITE_COLOR "■ " RESET_COLOR);
            }else {
                printf("□ ");
            }
        }
        printf("\n");
    }
    // 블록이 없는 경우 공백을 출력합니다.
    printf("\n\n"); //두줄 공백 출력하는 것
    printf("Tetris Table\n");
    printf("\t┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯┯\n\t┏  ┯  ┯  ┯  ┯  ┯  ┓\n\t┃  │  │  ∧  ∧  │  ┃    살려줘!!\n\t┃  │  │ ( ≧ Д ≦ ) ┃   \n\t┃  │  │  ф  ф  │  ┃\n\t┗  ┷  ┷  ┷  ┷  ┷  ┛\n\t┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷┷\n");
    for (i = 2; i < 21; i++)
    {
        printf("\t");
        for (j = 0; j < 10; j++)
        {
            if (j == 0 || j == 9)
            {
                printf("〓 ");
            }
            else if (i == 20 && (j > 0 && j < 9))
            {
                printf("〓");
            }
            else if (tetris_table[i][j] == 1){      //블럭포인터로 표현했었었는데, 테트리스테이블로 다시 함.
                printf(RED_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 2){
                printf(GREEN_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 3){
                printf(YELLOW_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 4){
                printf(BLUE_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 5){
                printf(MAGENTA_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 6){
                printf(CYAN_COLOR "■ " RESET_COLOR);
            }else if (tetris_table[i][j] == 7){
                printf(WHITE_COLOR "■ " RESET_COLOR);
            }else { // 블록이 없는 경우 공백
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\t 신해철 - 그대에게\n\t0:35 ━❍──────── -3:48\n\t↻     ⊲  Ⅱ  ⊳     ↺\n");
}
// int color()
// {
//     // ANSI 컬러를 사용한 예제
//     printf(RED_COLOR "빨간색 테스트\n" RESET_COLOR);
//     printf(GREEN_COLOR "초록색 테스트\n" RESET_COLOR);
//     printf(YELLOW_COLOR "노란색 테스트\n" RESET_COLOR);
//     printf(BLUE_COLOR "파란색 테스트\n" RESET_COLOR);
//     printf(MAGENTA_COLOR "자주색 테스트\n" RESET_COLOR);
//     printf(CYAN_COLOR "청록색 테스트\n" RESET_COLOR);
//     printf(WHITE_COLOR "흰색 테스트\n" RESET_COLOR);

//     return 0;
// }(*block_pointer)