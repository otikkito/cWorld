#include <stdio.h>

int main(){
	float number;
	
	printf("Enter a floating point value: ");
	scanf("%e",&number);
	printf("fixed-point notation: %f\n",number);
	printf("exponential notation: %e\n",number);
	printf("p notation: %a\n",number);
}