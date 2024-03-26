/**
 * @file db.h
 * @brief MySQL DB 기능을 제공하는 헤더 파일
 * @author 최수길, 김진호, 강민우, 정현우
 * @date 2024-03-21
 * @details MySQL DB와 연결하고, 데이터를 저장, 가져올 수 있습니다.
 */

#ifndef DB_H
#define DB_H

#include <mysql.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define ERR 1
#define OK 0

// MySQL DB 연결 정보
static MYSQL *conn = NULL;
static const int port = 3306;
static const char *db = "hm2j";
static const char *host = "localhost";
static const char *user = "root";
static const char *passwd = "0000";

// 게임 데이터 저장에 사용할 구조체 선언
typedef struct
{
    char name[30];
    int point;
    int year;
    int month;
    int day;
    int hour;
    int min;
} RESULT;

static RESULT tmp;

// 외부 함수 선언
int new(int a);

/**
 * @brief MySQL Result를 출력합니다
 * @param conn MySQL DB
 */
int print_result(MYSQL *conn);

/**
 * @brief MySQL DB에서 log 데이터를 가져올 수 있습니다
 * @param conn MySQL DB
 * @return RESULT
 */
RESULT *get_one_row(MYSQL *conn);

/**
 * @brief MySQL DB를 테스트합니다
 * @param conn MySQL DB
 */
int test_db(MYSQL *conn);

/**
 * @brief MySQL DB를 사용합니다
 * @param conn MySQL DB
 */
int use_db(MYSQL *conn);

/**
 * @brief MySQL Table을 삭제합니다
 * @param conn MySQL DB
 */
int drop_table(MYSQL *conn);

/**
 * @brief MySQL DB를 생성합니다
 * @param conn MySQL DB
 */
int create_table(MYSQL *conn);

/**
 * @brief MySQL DB를 초기화합니다
 */
void init_db();

/**
 * @brief MySQL DB를 종료합니다
 */
void close_db();

/**
 * @brief MySQL DB에서 데이터를 가져올 수 있습니다
 * @param name  이름을 통해 사용자 검색
 * @return RESULT 구조체 주소 or NULL을 돌려줍니다
 */
void read_db();

/**
 * @brief MySQL DB에 데이터를 저장할 수 있습니다
 * @param point 점수, 아이디
 */
void write_db(int point);

/**
 * @brief MySQL DB에서 모든 데이터를 가져올 수 있습니다
 */
void show_all_db();

#endif // DB_H