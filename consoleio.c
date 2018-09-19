/****************************************************************
*FILE NAME: consoleio.c
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
#include <stdio.h>

/*
 Do a little console io and printing
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
int main(){
	
	int a,b,c,sum;
	char fname[20];
	char lname[20];

	printf("Please enter in 3 integers to be added\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("Please enter you name: First name Last name\n");
	scanf("%s%s",fname,lname);
	sum = a + b + c;
	printf("Hello %s %s. The sum of these integers are: %d \n",fname,lname,sum);

	return 0;

}	
