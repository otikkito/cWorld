/****************************************************************
*FILE NAME: app-time.c
*
*
*
*PURPOSE: To find a best way to do time calcuulations.
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

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

//global
struct timespec start_time;
struct timespec elapsed_time;
long int total_mins;
long int total_seconds;
long int total_nanoseconds;

/********************************************************
*
*
* FUNCTION NAME:  main
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
* none
*
*
* RETURNS:
*
*
*
*********************************************************/

int main(){
	
	int i;
	long int j;
	long int k;
	
	i = clock_gettime( CLOCK_MONOTONIC,&start_time);
    if(i == -1){
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }
	
	sleep(65);
	usleep(900);
	
	i = clock_gettime(CLOCK_MONOTONIC,&elapsed_time);
	
	//printf("The total elapsed time in  seconds: %ld\n",((elapsed_time.tv_sec)-(start_time.tv_sec)));
	total_seconds = ((elapsed_time.tv_sec)-(start_time.tv_sec));
	total_nanoseconds = ((elapsed_time.tv_nsec) - (start_time.tv_nsec)); 
	printf("The total seconds is %ld and the total nanoseconds %ld\n",total_seconds, total_nanoseconds);
	j= total_seconds/60;  //mins
	k= total_seconds % 60; //remainder seconds that are not minutes
	printf("The number of mins. is: %ld , the total number of seconds is %ld , nanoseconds is : %ld\n",j,k,total_nanoseconds);
	//overflow occurs in nanoseconds
	return EXIT_SUCCESS;
	
}