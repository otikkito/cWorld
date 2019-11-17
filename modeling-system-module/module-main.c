/****************************************************************
*FILE NAME: module-main.c
*
*
*
*PURPOSE: test frameworlk for system-function.c
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
*ABNORMAL ERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
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
*7/18/2017  Kito Joseph     01                  Date created
*9/8//2018  Kito JOseph     02                  Created the file format and prolog pursant to the nasa-c-coding style.
*
*ALGORITHM (PDL)
*
*compile option: gcc -g -Wall -pedantic module-main.c modules/system-function.c
*/

/* 
 * File:   module-main.c
 * Author: otikkito
 *
 * Created on July 18, 2017, 12:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modules/system-function.h"

/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS: argc, argv
*
*
*
* ARGUMENT     TYPE    I/O DESCRIPTION
* --------     ----    --- -----------
*argc          int     I   number of command line arguments
*argv          char ** I   char array vector for the command line arguments
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/
int main(int argc, char** argv) {

	
	
	printf("Welcome to module-main.c we will be testing some of the functions here.\n");
	printf("----------------------------------------------------------------------\n");
	printf("The module name is: %s\n",getProcessNameByPid(getpid()));
	printf("Does the file exist. 1 if it does: %d\n",fileExist("/home/Kito Joseph/sandbox/cWorld/text-data-files"));
	printf("Does the file exist. 1 if it does: %d\n",fileExist("c:\test.h"));
	
	
	
	
    return (EXIT_SUCCESS);
}

