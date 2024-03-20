#include <stdlib.h>
#include <stdio.h>

void save_result(int point)
{
    FILE *fp = NULL;
    fp = fopen("result", "ab");
    fwrite(&point, sizeof(int), 1, fp);
    fclose(fp);
}

void print_result(void)
{
    int point;
    FILE *fp = NULL;
    fp = fopen("result", "rb");
    if (fp == NULL)
        return 0;
    while (1)
    {
        fread(&point, sizeof(int), 1, fp);
        if (feof(fp))
            break;
        printf("point: %d\n", point);
    }
    fclose(fp);
    return 0;
}