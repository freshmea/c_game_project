/**
 * @file db.c
 * @brief MySQL DB Functions
 * @author xxxx
 * @date 2024-03-21
 * @detail MySQL DB와 연결하고, 데이터를 저장, 가져올 수 있습니다.
 */
#include "db.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#define ERR 1
#define OK 0

static MYSQL *conn = NULL;
static const char *host = "localhost";
static const char *user = "root";
static const char *passwd = "0000";
static const char *db = "hm2j";
static const int port = 3306;

static RESULT tmp;

/**
 * @brief MySQL Result를 출력합니다
 * @param conn MySQL DB
 */
int print_result(MYSQL *conn) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  res = mysql_store_result(conn);
  if (!res) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return ERR;
  }
  while ((row = mysql_fetch_row(res)) != NULL) {
    printf("%s\n", row[0]);
  }

  return OK;
}

/**
 * @brief MySQL DB에서 log 데이터를 가져올 수 있습니다
 * @param conn MySQL DB
 * @return RESULT
 */
RESULT *get_one_row(MYSQL *conn) {
  MYSQL_RES *res;
  MYSQL_ROW row;
  res = mysql_store_result(conn);
  if (!res) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }

  while ((row = mysql_fetch_row(res)) != NULL) {
    // printf("%s, %s, %s, %s, %s, %s, %s, %s\n", row[0], row[1], row[2],
    // row[3],
    //        row[4], row[5], row[6], row[7]);
    // string copy
    strcpy(tmp.name, row[1]);
    // convert string to int
    tmp.point = atoi(row[2]);
    tmp.year = atoi(row[3]);
    tmp.month = atoi(row[4]);
    tmp.day = atoi(row[5]);
    tmp.hour = atoi(row[6]);
    tmp.min = atoi(row[7]);
  }

  return &tmp;
}

/**
 * @brief MySQL DB를 테스트합니다
 * @param conn MySQL DB
 */
int test_db(MYSQL *conn) {
  printf("################\n");
  printf("[test_db] SHOW databases\n");

  // show all databases
  if (mysql_query(conn, "SHOW DATABASES;")) {
    printf("SHOW Query failed\n");
    return ERR;
  }

  if (print_result(conn)) {
    printf("Print Result failed\n");
    return ERR;
  };

  printf("################\n");
  printf("[show_table] SHOW TABLES\n");
  if (mysql_query(conn, "SHOW TABLES;")) {
    printf("SHOW TABLES Query failed\n");
    return ERR;
  }

  return print_result(conn);
}

/**
 * @brief MySQL DB를 사용합니다
 * @param conn MySQL DB
 */
int use_db(MYSQL *conn) {
  printf("################\n");
  printf("[use_db] USE hm2j\n");
  // use database
  if (mysql_query(conn, "USE hm2j")) {
    printf("USE Query failed\n");
    return ERR;
  }

  return OK;
}

/**
 * @brief MySQL Table을 삭제합니다
 * @param conn MySQL DB
 */
int drop_table(MYSQL *conn) {
  printf("################\n");
  printf("[drop_table] DROP TABLE log\n");
  // drop table
  if (mysql_query(conn, "DROP TABLE IF EXISTS log;")) {
    printf("DROP TABLE Query failed\n");
    return ERR;
  }

  return print_result(conn);
}

/**
 * @brief MySQL DB를 생성합니다
 * @param conn MySQL DB
 */
int create_table(MYSQL *conn) {
  // create table
  if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS log ("
                        "id INT AUTO_INCREMENT PRIMARY KEY,"
                        "name VARCHAR(30),"
                        "point INT,"
                        "year INT,"
                        "month INT,"
                        "day INT,"
                        "hour INT,"
                        "min INT);")) {
    printf("CREATE TABLE Query failed\n");
    return ERR;
  }

  return print_result(conn);
}

/**
 * @brief MySQL DB를 초기화합니다
 */
void init_db() {
  // establish connection with mysql
  conn = mysql_init(NULL);
  // if connection failed
  if (!mysql_real_connect(conn, host, user, passwd, db, port, NULL, 0)) {
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  // test_db(conn);
  create_table(conn);
}

/**
 * @brief MySQL DB를 종료합니다
 */
void close_db() {
  if (conn != NULL) {
    mysql_close(conn);
  }
}

/**
 * @brief MySQL DB에서 데이터를 가져올 수 있습니다
 * @param name  이름을 통해 사용자 검색
 * @return RESULT 구조체 주소 or NULL을 돌려줍니다
 */
void read_db() {
  char query[256];
  printf("이름을 입력하세요: ");
  scanf("%s", tmp.name);
  snprintf(query, sizeof(query), "SELECT * FROM log WHERE name = '%s'", tmp.name);
  if (mysql_query(conn, query)) {
    printf("SELECT Query failed\n");
  }

  RESULT *res = get_one_row(conn);
  if (res == NULL) {
    system("clear");
    printf("********************************\n");
    printf("No History");
    printf("********************************\n");
  } else {
      system("clear");
      printf("********************************\n");
      printf("%s\n", res->name);
      printf("%d\n", res->point);
      printf("time: %d-%d-%d %d:%d\n", res->year, res->month, res->day, res->hour, res->min);
      printf("********************************\n");
  }
}

/**
 * @brief MySQL DB에 데이터를 저장할 수 있습니다
 * @param point 점수, 아이디
 */
void write_db(int point) {
  printf("이름을 입력하세요: ");
  scanf("%s", tmp.name);

  new(point);
  tmp.point = point;

  time_t now_sec = time(NULL);
  struct tm *now = localtime(&now_sec);

  tmp.year = now->tm_year + 1900;
  tmp.month = now->tm_mon + 1;
  tmp.day = now->tm_mday;
  tmp.hour = now->tm_hour;
  tmp.min = now->tm_min;

  if (conn == NULL) {
    init_db();
  }

  char query[512];
  // safe version of printf
  // store query
  snprintf(query, sizeof(query),
           "INSERT INTO log (name, point, year, month, day, hour, min) VALUES "
           "('%s', %d, %d, %d, %d, %d, %d)",
           tmp.name, tmp.point, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min);
  if (mysql_query(conn, query)) {
    printf("INSERT Query failed: %s\n", mysql_error(conn));
  }
}
