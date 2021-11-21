/****************************************************************
*FILE NAME: crefresh.c
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
#include <string.h>
#include <assert.h>
#include "crefresh.h"


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


/*This program is try to use all the functionality of c basically I will go 
 * through all the keywords in c:
 * auto break case char const continue default do double else enum extern float 
 * for goto if int long register return short signed sizeof static struct switch
 * typedef union unsigned void volatile while 
 *function prototypes are in the header file http://www.cs.utah.edu/~germain/PPS/Topics/C_Language/c_functions.html
*/

int main(){
    
	/*variable declaration*/	
	int i;
	float f;
	double d;
	char c;
	char string[] = "Hello World\n";
	int rv;
	struct datastruct ds1;
	struct datastruct ds2;

	/*initialization*/	
	i=2+3;
	f=3.14159;
	d=3.14159;
	c='t';
	ds1.age=33;
	strcpy(ds1.name,"John Doe");
	ds1.c = 'z';
	ds2.age = 43;
	strcpy(ds2.name,"Chin Zhou");
	ds2.c = 'g';
	printf("The value of i is %d\n",i);
	printf("The value of f is %f\n",f);
	printf("The value of d is %f\n",d);
	printf("The value of c is %c\n",c);
	printf("The value of string is %s",string);
	printf("structure age: %d\n",ds1.age);
	printf("structure name: %s\n",ds1.name);
	printf("structure c: %c\n",ds1.c);
	
	rv = myfunction(ds1,ds2);
	int j;  //just have to declare variables before you use them
	for(j=0; j<10; j=j+2){
		printf("the index is: %d\n",j);
	}

	int k;
	k=0;
	while(k <20){
		printf("current value of k is: %d\n",k);
		k+=5;	
	}

	simpleFunction(&ds1,&ds2);
	printf("Location of ds1: %p\n",&ds1);
	printf("Location of ds2: %p\n",&ds2);
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME:myfunction
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
* RETURNS: returns 0
*
*
*
*********************************************************/


/*Pass by value*/
int myfunction(struct datastruct a, struct datastruct b){
	int ret;
		
	ret = strcmp(a.name,b.name);
	if(ret == 0){
		printf("The name is the same\n");
	}
	else if( ret < 0){
		printf("aaaa\n");
	}
	else if (ret > 0){
		printf("bbbb\n");	
	}

	return 0; //for now
}

/********************************************************
*
*
* FUNCTION NAME: simplefunction
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


/*function that will pass by reference*/
int simpleFunction(struct datastruct *a, struct datastruct *b){
	
	assert(&a != NULL);
	assert(&b != NULL);
	
	printf("Function:The location of a is: %p\n",a);
	printf("Function:The location of b is: %p\n",b); 
	return 0;
}
