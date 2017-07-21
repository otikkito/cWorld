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
/*
 * 
 */
int main(int argc, char** argv) {
    
    printf("MySql client version: %s\n",mysql_get_client_info());
    

    return (EXIT_SUCCESS);
}

