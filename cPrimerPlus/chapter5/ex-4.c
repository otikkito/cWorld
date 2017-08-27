#include <stdio.h>

#define CENTTOINCHES 2.54
int main(){
	
	float heightcm;
	int hf;
	float hi;
	
	printf("Please enter the height in centimeters: ");
	scanf("%f",&heightcm);
	hf =  (heightcm / CENTTOINCHES) / 12;
	hi =  (heightcm -(5*12*2.54))/2.54; 
	printf("%3.1f cm = %d feet, %3.1f inches\n",(float) heightcm, hf, hi);
	
	while(heightcm > 0){
		printf("Please enter the height in centimeters: (<=0 to quit)");
	    scanf("%f",&heightcm);
		hf =  (heightcm / CENTTOINCHES) / 12;
	    hi =  (heightcm -(hf*12*2.54))/2.54; 
	    printf("%3.1f cm = %d feet, %3.1f inches\n",(float) heightcm, hf, hi);
	}
	
	return 0;
	
}