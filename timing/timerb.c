/****************************************************************
*FILE NAME: timerb.c
*
*
*
*PURPOSE: 
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
*
*ALGORITHM (PDL)
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
*/

/********************************************************
*
*
* FUNCTION NAME: main
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
int main(void){

    time_t start, end;
    int i;

     start=time(NULL);
     for(i=0;i<7899999;i++){
          i++; 
	printf("i= %d\n",i);
     }
     end = time(NULL);
     printf("The loop used %f seconds.\n", difftime(end,start));

    return EXIT_SUCCESS;
}


