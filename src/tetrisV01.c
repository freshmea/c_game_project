#include "tetrisV01.h"

int main(void)
{
	int menu = 1;

	while (menu)
	{
		menu = display_menu();

		if (menu == 1)
		{
			game = GAME_START;
			menu = game_start();
		}
		else if (menu == 2)
		{
			search_result();
		}
		else if (menu == 3)
		{
			print_result();
		}
		else if (menu == 4)
		{
			exit(0);
		}
	}

	return 0;
}

/* 게임 시작시 호출되는 함수.   game변수를 참조하여 게임을 종료하거나 시작함 . 게임 시작시 update()함수가 콜백함수로 설정되고 타이머를 등록함. */
int game_start(void)
{

	if (game == GAME_START)
	{
		init_tetris_table();

		// 타이머 설정
		static struct itimerval timer;
		//  type 에러가 나면 오른쪽 사용. signal(SIGALRM, (void (*)(int))update);
		signal(SIGVTALRM, (void (*)(int))update);
		timer.it_value.tv_sec = 0;
		timer.it_value.tv_usec = 1;
		timer.it_interval.tv_sec = 0;
		timer.it_interval.tv_usec = 1;
		setitimer(ITIMER_VIRTUAL, &timer, NULL);

		while (1)
		{
			if (game == GAME_END)
			{
				signal(SIGALRM, SIG_IGN);

				save_result(point, best_point);

				x = 3, y = 0;
				point = 0;

				return 1;
			}
		}
	}

	return 0;
}

/* 현재의 테트리스판을 보여준다. 블록이 놓이고 쌓인 현재 상태를 보여줌*/
int display_tetris_table(void)
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

	return 0;
}

/*테트리스판을 초기화 한다. 벽과 공간을 나눔*/
int init_tetris_table(void)
{
	int i = 0, j = 0;

	for (i = 0; i < 20; i++)
		for (j = 1; j < 9; j++)
			tetris_table[i][j] = 0;

	for (i = 0; i < 21; i++)
	{
		tetris_table[i][0] = 1;
		tetris_table[i][9] = 1;
	}

	for (j = 1; j < 9; j++)
		tetris_table[20][j] = 1;

	return 0;
}