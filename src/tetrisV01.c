#include "tetrisV01.h"

int main(void)
{
	int menu = 1;

	while (menu)
	{
		menu = display_menu();

		switch (menu)
		{
		case 1:
			game = GAME_START;
			menu = game_start();
			break;
		case 2:
			search_result();
			break;
		case 3:
			print_result();
			break;
		case 4:
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}

/** 게임 시작시 호출되는 함수.
 * game변수를 참조하여 게임을 종료하거나 시작함.
 * 게임 시작시 update()함수가 signal을 이용해서 콜백함수로 설정되고 타이머를 등록함.
 */
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
		timer.it_value.tv_usec = 16667;
		timer.it_interval.tv_sec = 0;
		timer.it_interval.tv_usec = 16667;
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

/**
 * 테스리스 판을 초기화 한다.
 */
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