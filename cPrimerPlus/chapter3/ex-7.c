#include <stdio.h>

#define INCHESTOCENT 2.54

int main(){
	int height;
	
	printf("Please enter you height in inches: ");
	scanf("%d",&height);
	printf("The amount of centimeters your height is: %f\n",height*INCHESTOCENT);
}