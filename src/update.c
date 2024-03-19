#include <stdio.h>
int test = 0;
int update(int signum)
{
    display_tetris();
    test++;
    printf("%d\n", test);
}