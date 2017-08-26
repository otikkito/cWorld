#include <stdio.h>

/*
"Write a program that reads in a floating-point number and prints it first in decimal-point
notation and then in exponential notation. Have the output se the following formats
(the number of digits shown in the exponent may be different for your system):"
a. The input is 21.3 or 2.1e+001.
b. The input is +21.290 or 2.12E+001
*/

int main(){

	float number;
	
	printf("Please enter a floating point number: ");
	scanf("%f",&number);
	printf("The input is %f\n",number);
	printf("The input is %e\n",number);
	

	
}
