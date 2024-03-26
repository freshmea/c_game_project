#include "main.h"

int main(void)
{
    int menu = 1;
    menu = display_menu();

    switch (menu)
    {
    case 1:
        game = GAME_START;
        reset();
        display_snake();
        menu = game_start();
        break;
    case 2:
        printf("Record\n");
        read_db();
        break;
    case 3:
        printf("Record\n");
        show_all_db();
        break;
    case 4:
        printf("Quit\n");
        break;
        return 0;
    }
}

int game_start()
{
    // signal 설정
    static struct itimerval timer;
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
            signal(SIGVTALRM, SIG_IGN);
            write_db(point);
            reset();
            return 1;
        }
    }
    game = GAME_END;
}

void reset(void)
{
    point = 0;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    snakeX[0] = x;
    snakeY[0] = y;
    entireTail = 0;
    space();
}