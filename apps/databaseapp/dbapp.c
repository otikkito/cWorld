/****************************************************************
*FILE NAME: dbapp.c
*
*
*
*PURPOSE: To develope a program that access a database and use proper self documentation.
* 
*
*FILE REFERENCES:
*
*NAME		I/O		Description
*----           ---             -----------
*
*EXTERNAL VARIABLE:
*SOURCE: <         >
*
*NAME	  TYPE    	I/O		Description
*----     ----          ---             -----------
*
*EXTERNAL REFERENCES:
*
*Name		Description
*----   	-----------
*
*ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*
*ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
*
*NOTES:
*
*REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*DEVELOPMENT HISTORY:
*
*Date		Author		Change ID	Release		Description of Change
*----   	------  	---------   -------     ---------------------
*
*ALGORITHM (PDL)
*/

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/my_config.h>
#include <mysql/my_global.h>

/* Notes

-C API: https://mariadb.com/kb/en/library/mariadb-connectorc-api-functions/

-To compile: gcc -g -Wall -pedantic dbapp.c -L/usr/lib64/mysql -lmysqlclient -lpthread -lz -lm -lssl -lcrypto -ldl -I/usr/include/mysql

-The mysql data structures can be found in : /usr/include/mysql , and "MYSQL" can befound in mysql.h

*/


/********************************************************
*
*
* FUNCTION NAME: main (the entry point of the program)
*
*
*
* ARGUMENTS:
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS:
*
*
*
*********************************************************/
int main(int argc, char** argv) {

	printf("Welcome to dbapp\n");

	/*This will print the client version*/
    	printf("MySql client version: %s\n", mysql_get_client_info());

	/*Prepares and initialized MYSQL structure*/
	/*The data structure definition is on line 249 of /usr/include/mysql/mysql.h */
	MYSQL *con = mysql_init(NULL); 

	if (con == NULL) {
        	fprintf(stderr, "mysql_init() failed\n");
        	exit(1);
    	}

	return EXIT_SUCCESS;
}
