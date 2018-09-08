/****************************************************************
*FILE NAME: testharness.c 
*
*
*
*PURPOSE: To provide a robost c library test harness.
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
*Date		Author		Change ID	    Release		    Description of Change
*----   	------  	---------       -------         ---------------------
*9/8/208    Kito Joseph    01                           creating file format and function prolog
*ALGORITHM (PDL)
*/


#include "testharness.h"


/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS:none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*none
*
*
* RETURNS: EXIT_FAILURE or EXIT_SUCCESS
*
*
*notes: http://en.wikipedia.org/wiki/C_standard_library
*********************************************************/

int main(){
	

	printGreating();
	testAssert(3); //must be less than 5 to to halt program
	//testAssert(6); //negative test should halt program
	testMath();
	
	return EXIT_SUCCESS;
	
}

/********************************************************
*
*
* FUNCTION NAME:printGreating
*
*
*
* ARGUMENTS:  none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*none
*
*
* RETURNS: none
*
*
*
*********************************************************/

void printGreating(){

	printf("Welcome to the C Standard Library test Harness\n");
	printf("We will be testing all the standard library functions\n");
	printf("in some semiformal way that I have not learned of yet.\n\n\n");
}

//
/********************************************************
*
*
* FUNCTION NAME: testAssert
*
*
*
* ARGUMENTS: int
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
* x            int  I    
*
*
* RETURNS:
*
*
*
*********************************************************/
void testAssert(int x){
	printf("Testing assert.h ...");
	assert( x < 5);
	printf("Done\n");
}

/********************************************************
*
*
* FUNCTION NAME: testMath
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*none
*
*
* RETURNS:  void
*
*
*
*********************************************************/
void testMath(){
	//Will be testing the math functions most return type double
	int a,b;
	double c;
	long int d;
	float f;
	div_t ans;

	a= 7;
	b= -78;
	c=3.4;
	d= 2000988;	
	f=-45.4783772938;
	printf("Abs value of b is: %d\n",abs(b));
	printf("Long ABS of d is: %ld\n",labs(d));
	printf("Absolute value of lower limit %d\n",abs(INT_MIN-1));
	/* testharness.c:159:9: warning: unused variable ‘c’ [-Wunused-variable]
      double c;
         ^
    testharness.c:158:6: warning: variable ‘a’ set but not used [-Wunused-but-set-variable]
    int a,b;
    */
	printf("Absolute value of negative float is %f\n",fabs(f));
	ans = div(18,5);
	printf("quotient: %d remainder: %d\n",ans.quot,ans.rem);
	printf("The value of c: %f\n",c);
	printf("The value of a: %d\n",a);

}
