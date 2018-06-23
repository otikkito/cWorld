/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dataaccess.c
 * Author: otikkito
 *
 * Created on July 20, 2017, 6:49 PM
 */ 

/*http://zetcode.com/db/mysqlc/*/

/*To compile: 
 * gcc -g -Wall -pedantic dataaccess.c -L/usr/lib64/mysql -lmysqlclient -lpthread -lz -lm -lssl -lcrypto -ldl  -I/usr/include/mysql
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql/my_global.h>
#include <mysql/mysql.h>
#include <mysql/my_config.h>

/*In file included from dataaccess.c:19:0:                                                                          
/usr/include/mysql/my_global.h:79:23: fatal error: my_config.h: No such file or directory                         
 #include <my_config.h>
 * 
 * gcc -g -Wall -pedantic dataaccess.c -I/usr/include/mysql

 */
/*https://mariadb.com/kb/en/mariadb/mariadb-connectorc-api-functions/*/
void finish_with_error(MYSQL *con) {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

/* TODO 
 * 1)Generalize database commnads for simple intereaction and create a tutorial on uses of database population and find out system statistics of the database within the operating system.
 * 
 */
int main(int argc, char** argv) {

    /*This will print the client version*/
    printf("MySql client version: %s\n", mysql_get_client_info());
    
    /*Prepares and initialized MYSQL structure*/
    MYSQL *con = mysql_init(NULL); 

    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    /*Establish a connection to a database server*/
    if (mysql_real_connect(con, "localhost", "root", "redhat",
            "census_database", 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }
    
    /*Performs a query on the database*/
    if (mysql_query(con, "SELECT * FROM census")) {
        finish_with_error(con);
    }
    
    /*Returns a buffered resultset from the last executed query.*/
    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL) {
        finish_with_error(con);
    }
    /*Returns the number of fields in the result set*/
    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    int i;
    
    while ((row = mysql_fetch_row(result))) {
        for (i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);

    return (EXIT_SUCCESS);
}

