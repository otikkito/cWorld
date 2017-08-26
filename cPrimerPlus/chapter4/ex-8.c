#include <stdio.h>

int main(){
	
	float miles;
	float gallons;
	float mpg;
	float liters;
	float kilometers;
	
	printf("Please enter the number of miles traved and the amount of gas consumed: ");
	scanf("%f %f",&miles,&gallons);
	mpg=miles/gallons;
	printf("The mpg is %.1f\n",mpg);
	liters=gallons*3.785;
	kilometers=miles*1.609;
	printf("The lpkm is %.1f",liters/kilometers);
	
	return 0;
}