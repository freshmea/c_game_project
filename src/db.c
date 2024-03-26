#include "db.h"

int print_result(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    res = mysql_store_result(conn);
    if (!res)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return ERR;
    }
    system("clear");
    while ((row = mysql_fetch_row(res)) != NULL)
    {
        printf("********************************\n");
        printf("Name: %s\n", row[1]);
        printf("Point: %s\n", row[2]);
        printf("time: %s-%s-%s %s:%s\n", row[3], row[4], row[5], row[6], row[7]);
        printf("********************************\n\n");
    }

    return OK;
}

RESULT *get_one_row(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    res = mysql_store_result(conn);
    if (!res)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        return NULL;
    }

    while ((row = mysql_fetch_row(res)) != NULL)
    {
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

int test_db(MYSQL *conn)
{
    printf("################\n");
    printf("[test_db] SHOW databases\n");

    // show all databases
    if (mysql_query(conn, "SHOW DATABASES;"))
    {
        printf("SHOW Query failed\n");
        return ERR;
    }

    if (print_result(conn))
    {
        printf("Print Result failed\n");
        return ERR;
    };

    printf("################\n");
    printf("[show_table] SHOW TABLES\n");
    if (mysql_query(conn, "SHOW TABLES;"))
    {
        printf("SHOW TABLES Query failed\n");
        return ERR;
    }

    return print_result(conn);
}

int use_db(MYSQL *conn)
{
    printf("################\n");
    printf("[use_db] USE hm2j\n");
    // use database
    if (mysql_query(conn, "USE hm2j"))
    {
        printf("USE Query failed\n");
        return ERR;
    }

    return OK;
}

int drop_table(MYSQL *conn)
{
    printf("################\n");
    printf("[drop_table] DROP TABLE log\n");
    // drop table
    if (mysql_query(conn, "DROP TABLE IF EXISTS log;"))
    {
        printf("DROP TABLE Query failed\n");
        return ERR;
    }

    return print_result(conn);
}

int create_table(MYSQL *conn)
{
    // create table
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS log ("
                          "id INT AUTO_INCREMENT PRIMARY KEY,"
                          "name VARCHAR(30),"
                          "point INT,"
                          "year INT,"
                          "month INT,"
                          "day INT,"
                          "hour INT,"
                          "min INT);"))
    {
        printf("CREATE TABLE Query failed\n");
        return ERR;
    }

    return OK;
}

void init_db()
{
    // establish connection with mysql
    conn = mysql_init(NULL);
    // if connection failed
    if (!mysql_real_connect(conn, host, user, passwd, db, port, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    // test_db(conn);
    create_table(conn);
}

void close_db()
{
    if (conn != NULL)
    {
        mysql_close(conn);
    }
}

void show_all_db()
{
    init_db();
    if (mysql_query(conn, "SELECT * FROM log ORDER BY point DESC LIMIT 10;"))
    {
        printf("SELECT Query failed\n");
    }

    print_result(conn);
    close_db();
}

void read_db()
{
    init_db();
    char query[256];
    printf("이름을 입력하세요: ");
    scanf("%s", tmp.name);
    snprintf(query, sizeof(query), "SELECT * FROM log WHERE name = '%s'", tmp.name);
    if (mysql_query(conn, query))
    {
        printf("SELECT Query failed\n");
    }

    print_result(conn);

    // RESULT *res = get_one_row(conn);
    // if (res == NULL)
    // {
    //     system("clear");
    //     printf("********************************\n");
    //     printf("No History");
    //     printf("********************************\n");
    // }
    // else
    // {
    //     system("clear");
    //     printf("********************************\n");
    //     printf("%s\n", res->name);
    //     printf("%d\n", res->point);
    //     printf("time: %d-%d-%d %d:%d\n", res->year, res->month, res->day, res->hour, res->min);
    //     printf("********************************\n");
    // }
    close_db();
}

void write_db(int point)
{
    printf("이름을 입력하세요: ");
    scanf("%s", tmp.name);

    tmp.point = point;

    time_t now_sec = time(NULL);
    struct tm *now = localtime(&now_sec);

    tmp.year = now->tm_year + 1900;
    tmp.month = now->tm_mon + 1;
    tmp.day = now->tm_mday;
    tmp.hour = now->tm_hour;
    tmp.min = now->tm_min;

    if (conn == NULL)
    {
        init_db();
    }

    char query[512];
    // safe version of printf
    // store query
    snprintf(query, sizeof(query),
             "INSERT INTO log (name, point, year, month, day, hour, min) VALUES "
             "('%s', %d, %d, %d, %d, %d, %d)",
             tmp.name, tmp.point, tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min);
    if (mysql_query(conn, query))
    {
        printf("INSERT Query failed: %s\n", mysql_error(conn));
    }
    else
    {
        printf("INSERT Query success\n");
        printf("********************************\n");
        printf("%s\n", tmp.name);
        printf("%d\n", tmp.point);
        printf("time: %d-%d-%d %d:%d\n", tmp.year, tmp.month, tmp.day, tmp.hour, tmp.min);
        printf("********************************\n");
    }
}