#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int getch(void); /*문자를 바로 입력 받을 수 있는 함수*/

/* 게임 종료때 마다
 * 이름과 득점점수와
 * 날짜, 시간이저장되는 구조체
 * */
static struct result
{
    char name[30];
    long point;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int rank;
} temp_result;

/*메뉴에서 기록검색시 호출되어 기록을 검색하는 함수*/
int save_result(long point, int best_point)
{
    FILE *fp = NULL;
    time_t ptime;
    struct tm *t;
    // 기록 파일로 저장
    printf("\n\n Final score : %ld ", point);
    printf("\n\n Please enter your name : ");
    scanf("%s%*c", temp_result.name);
    temp_result.point = point;

    if (temp_result.point >= best_point)
        best_point = temp_result.point;

    ptime = time(NULL);    // 현재 시각을 초 단위로 얻기
    t = localtime(&ptime); // 초 단위의 시간을 분리하여 구조체에 넣기

    temp_result.year = t->tm_year + 1900;
    temp_result.month = t->tm_mon + 1;
    temp_result.day = t->tm_mday;
    temp_result.hour = t->tm_hour;
    temp_result.min = t->tm_min;

    fp = fopen("result", "ab");
    fseek(fp, 1, SEEK_END);
    fwrite(&temp_result, sizeof(struct result), 1, fp);
    fclose(fp);
    return 0;
}

int search_result(void)
{
    FILE *fp = NULL;
    char name[30];
    char ch;
    int find = 0;

    fp = fopen("result", "rb");

    if (fp == NULL)
        return 0;

    system("clear");

    printf("\n\n\t\tEnter the name your to search.  : ");
    scanf("%s%*c", name);

    printf("\n\t\t\t\tText Tetris");
    printf("\n\t\t\t\t Game Stats\n\n");
    printf("\n\t\tName\t\tScore\t   Date\t\t Time");

    while (1)
    {
        fread(&temp_result, sizeof(struct result), 1, fp);
        if (!feof(fp))
        {
            if (!strcmp(temp_result.name, name))
            {
                find = 1;
                printf("\n\t========================================================");
                printf("\n\t\t%s\n\t\t\t\t%ld\t%d.%d.%d.  |  %d:%d\n", temp_result.name, temp_result.point, temp_result.year, temp_result.month, temp_result.day, temp_result.hour, temp_result.min);
            }
        }
        else
        {
            break;
        }
    }

    if (find == 0)
        printf("\n\n\n\t\tThis name is not found.");

    printf("\n\n\n\t\tBack to the game menu : M");
    while (1)
    {
        ch = getch();
        if (ch == 77 || ch == 109)
            break;
    }

    return 0;
}

/* 메뉴에서 기록출력시 호출되어 기록을 출력하는 함수*/
int print_result(void)
{
    FILE *fp = NULL;
    char ch = 1;

    fp = fopen("result", "rb");

    if (fp == NULL)
        return 0;

    system("clear");

    printf("\n\t\t\t\tText Tetris");
    printf("\n\t\t\t\t Game Stats\n\n");
    printf("\n\t\tName\t\tScore\t   Date\t\t Time");

    while (1)
    {
        fread(&temp_result, sizeof(struct result), 1, fp);
        if (!feof(fp))
        {
            printf("\n\t========================================================");
            printf("\n\t\t%s\n\t\t\t\t%ld\t %d.%d.%d.  |  %d:%d\n", temp_result.name, temp_result.point, temp_result.year, temp_result.month, temp_result.day, temp_result.hour, temp_result.min);
        }
        else
        {
            break;
        }
    }

    fclose(fp);

    printf("\n\n\tBack to the game menu : M");
    while (1)
    {
        ch = getch();
        if (ch == 77 || ch == 109)
            break;
    }
    return 0;
}