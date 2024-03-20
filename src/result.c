#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static struct result
{
    char name[30];
    int point;
    int year;
    int month;
    int day;
    int hour;
    int min;
} temp_result;

void save_result(int point)
{
    FILE *fp = NULL;
    fp = fopen("result", "ab");
    temp_result.point = point;

    printf("이름을 입력하세요: ");
    scanf("%s", &temp_result.name);

    // 변수 선언
    time_t ptime;
    struct tm *t;

    ptime = time(NULL);    // 현재 시각을 초 단위로 얻기
    t = localtime(&ptime); // 초 단위의 시간을 분리하여 구조체에 넣기

    // temp_result.year = (*t).tm_year + 1900;
    temp_result.year = t->tm_year + 1900;
    temp_result.month = t->tm_mon + 1;
    temp_result.day = t->tm_mday;
    temp_result.hour = t->tm_hour;
    temp_result.min = t->tm_min;

    fwrite(&temp_result, sizeof(struct result), 1, fp);
    fclose(fp);
}

int print_result(void)
{
    FILE *fp = NULL;
    fp = fopen("result", "rb");
    if (fp == NULL)
        return 0;
    while (1)
    {
        fread(&temp_result, sizeof(struct result), 1, fp);
        if (feof(fp))
            break;
        printf("point: %d\n", temp_result.point);
        printf("name: %s\n", temp_result.name);
        printf("time: %d-%d-%d %d:%d\n", temp_result.year, temp_result.month, temp_result.day, temp_result.hour, temp_result.min);
    }
    fclose(fp);
    return 0;
}