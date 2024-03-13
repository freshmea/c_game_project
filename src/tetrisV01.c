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
		signal(SIGALRM, (void (*)(int))update);
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