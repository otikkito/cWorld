#include <stdio.h>
#include <math.h>

double cube(double);

int main(){
	
	double number;
	
	printf("Plese enter a double: ");
	scanf("%lf",&number);
	printf("The cubped of this number is %lf \n",cube(number));
	
	return 0;
	
}

double cube(double d){
	return pow(d,3);
}
	