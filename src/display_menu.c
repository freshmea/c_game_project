#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* 메뉴를 보여줌 */
int display_menu(void)
{
	int menu = 0;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	while (1)
	{
		pthread_mutex_lock(&mutex);
		system("clear");
		printf("\n\n\t\t\t\tText Tetris");
		printf("\n\t\t\t============================");
		printf("\n\t\t\t\tGAME MENU\t\n");
		printf("\n\t\t\t============================");
		printf("\n\t\t\t   1) Game Start");
		printf("\n\t\t\t   2) Search history");
		printf("\n\t\t\t   3) Record Output");
		printf("\n\t\t\t   4) QUIT");
		printf("\n\t\t\t============================");
		printf("\n\t\t\t\t\t SELECT : ");
		scanf("%d", &menu);
		pthread_mutex_unlock(&mutex);
		if (menu < 1 || menu > 4)
		{
			continue;
		}
		else
		{
			return menu;
		}
	}
	return 0;
}