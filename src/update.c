/**
 *@file update.c
* @brief rand와 srand,time함수,출력함수,signal함수를 사용하기 위한 헤더파일들을 출력했습니다.
* GAME START, GAME END을 정의하고 미끼의 생성,처음 생성된 미끼의
* 길이와 높이를 정의했습니다. 또한 게임 플레이 시간을 계산하는 count변수와 미끼의 위치 미끼를
  섭취했을때의 꼬리의 변화를 정의하고(bait,snakeX,Y) 필드의 크기와 게임 포인트 꼬리의 크기변수
  를 가져와서(extern) 활용하였습니다.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

#define GAME_START 0
#define GAME_END 1
#define width 40
#define height 40

int count;
extern int x;
extern int y;
extern int game;
extern int point;
extern entireTail;

int baitX;
int baitY;
int snakeX[100];
int snakeY[100];

void space()
{
    srand(time(NULL));

    baitX = rand() % height - 1;
    baitY = rand() % width - 1;

    if (baitX == 0 || baitX == height)
    {
        baitX = rand() % height - 1;
    }
    else if (baitY == 0 || baitY == width)
    {
        baitY = rand() % width - 1;
    }

    if (x == baitX && y == baitY)
    {
        baitX = rand() % height - 1;
        baitY = rand() % width - 1;
    }
}
/**
 * @example typedef함수를 사용하여 STOP LEFT RIGHT UP DOWN이란 단어의 데이터타입을
 * 정의하고 sdir(snake direction)구조체 집합 구성요소로 정의하였습니다.
 */
typedef enum
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
} sdir;
/**
 * @brief move_snake함수를 정의하였습니다. 위에 정한 구조체 sdir을 변수로 정하고
 * 새로 정의한 newx,newy변수를 활용하여 switch case문으로 플레이어가 조종하는 뱀의
 * 움직임을 정의하였습니다.
 */
int move_snake(int sdir)
{
    int newx, newy;

    newx = x;
    newy = y;

    switch (sdir)
    {
    case LEFT:
        newy--;
        break;
    case RIGHT:
        newy++;
        break;
    case DOWN:
        newx++;
        break;
    case UP:
        newx--;
        break;
    }

    x = newx;
    y = newy;

    return 0;
}
/**
 * @brief collision함수는 먹이를 플레이어가 조종하는 뱀이 먹었을때
 * 포인트를 얻고 꼬리의 길이를 업데이트하고 새로운 먹이를 랜덤한 위치에
 * 스폰할수 있도록 정의했습니다.
 */
// bait & snake
void collison()
{
    if (x == baitX && y == baitY)
    {
        ++point;
        ++entireTail;
        space();
    }
}

int update(int signum)
{
    int ch;
    ch = getch();
    switch (ch)
    {
    case 'i':
        move_snake(UP);
        break;
    case 'j':
        move_snake(LEFT);
        break;
    case 'k':
        move_snake(DOWN);
        break;
    case 'l':
        move_snake(RIGHT);
        break;
    case 's':
        game = GAME_END;
        break;
    }

    ++count;
    display_snake();
    collison();
    /*
         gameover if snake touch it's own body
    for (int i = 1; i < entireTail; ++i)
    {
        if(snakeX[0]==snakeX[i] && snakeY[0]==snakeY[i])
         game = GAME_END;
    }
    */

    // gameover if snake touch wall
    if (x == 0)
    {
        game = GAME_END;
    }
    if (y == 0)
    {
        game = GAME_END;
    }
    if (x == width - 1)
    {
        game = GAME_END;
    }
    if (y == height - 1)
    {
        game = GAME_END;
    }

    /**
     * @brief 뱀이 먹이를 섭취하였을경우에 생기는 꼬리의 변화를 임의의 변수
     * (temp)로 정의하고 배열을 활용하여 꼬리가 길어지는 상황을 조건문을 활
     * 용하여 정의했습니다.
     */
    // snake tail logic
    int tempX = snakeX[0];
    int tempY = snakeY[0];
    int tempX2, tempY2;
    snakeX[0] = x;
    snakeY[0] = y;
    for (int i = 1; i < entireTail; i++)
    {
        tempX2 = snakeX[i];
        tempY2 = snakeY[i];
        snakeX[i] = tempX;
        snakeY[i] = tempY;
        tempX = tempX2;
        tempY = tempY2;
    }
    return 0;
}