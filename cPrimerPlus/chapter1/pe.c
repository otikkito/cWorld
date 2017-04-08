/*The opbjective of this program is to prompt the user to enter a value as an integer 
in inches and the program will return a value as a double in centimeters. We will
use scanf to take in an integer value and dispaly a double value in centiimeters*/

#include <stdio.h>

int main(){

	int inches;
	double cm;

	printf("Please enter an integer value for inches to convert to centimeters\n");
	scanf("%d",&inches);//read the input of inches
	cm = inches*2.54; //convert inches to centimeters
	printf("The amount of centimeters is : %e\n", cm);
	return 0;

}

