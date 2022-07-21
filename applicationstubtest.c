/****************************************************************
*FILE NAME: applicationstubtest.c
*
*
*
*PURPOSE: Robust test framework for the applicationstub.c
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

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
//#include "modeling-system-module/modules/system-function.h"

//function declaration
//pid_t get_pid_by_process_name(const char*) //located in : modeling-system-module/modules/system-function.h

/*Application test goals
  -ensure that you test all other parts of the program that does not terminate the program until the end of the test.
  -write a unit test for all the functions.
  -write a a regression suite for the application stub template.
  -ensure that all the documentation are in place.
  -ensure that the file format/prolog are up to date.
  -ensure that you self document all the code.
*/

int main(){
    
    printf("Welcome to the application-stub Test harness\n"); 
    printf("The process id of the test harness is %u\n",getpid());
    printf("-------------------------------------------------\n");
    
    
   // kill(get_pid_by_process_name("applicationstub"),SIGINT);
   
    
    printf("Thanks for using the application-stub Test harness.\nWe are now closing down.\n");
    printf("-------------------------------------------------\n");
         
    return EXIT_SUCCESS;
}
