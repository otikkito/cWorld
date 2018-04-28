#include "testharness.h"


/* http://en.wikipedia.org/wiki/C_standard_library */

int main(){
	

	printGreating();
	testAssert(3); //must be less than 5 to to halt program
	//testAssert(6); //negative test should halt program
	testMath();
	
}


void printGreating(){

	printf("Welcome to the C Standard Library test Harness\n");
	printf("We will be testing all the standard library functions\n");
	printf("in some semiformal way that I have not learned of yet.\n\n\n");
}

//Keywords:range, domain,code coverage, positive and negative test,...
void testAssert(int x){
	printf("Testing assert.h ...");
	assert( x < 5);
	printf("Done\n");
}

void testMath(){
	//Will be testing the math functions most return type double
	int a,b;
	double c;
	long int d;
	float f;
	div_t ans;

	a= 7;
	b= -78;
	d= 2000988;	
	f=-45.4783772938;
	printf("Abs value of b is: %d\n",abs(b));
	printf("Long ABS of d is: %ld\n",labs(d));
	printf("Absolute value of lower limit %d\n",abs(INT_MIN-1));
	printf("Absolute value of negative float is %f\n",fabs(f));
	ans = div(18,5);
	printf("quotient: %d remainder: %d\n",ans.quot,ans.rem);
	

}
