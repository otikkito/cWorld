#include <stdio.h>

void Temperatures(double);

int main(){
	
	double tf;
	int rc;
		
	
	printf("Please enter the temperature in Fahrenheit: ");
	rc = scanf("%lf",&tf);
	Temperatures(tf);
	
	while(rc == 1){
		printf("Enter a temperature in Fahrenheit: ");
		rc = scanf("%lf",&tf);
		Temperatures(tf);
    }
}


void Temperatures(double tf){
	
	double tc;
	double tk;
	const float a = 5.0;
	const float b = 9.0;
	const float c = 32.0;
	
	tc= a/b*(tf-c);
	tk = tc +273.16;
	printf("Fahrenheit: %.2lf | Celcsius: %.2lf | Kelvin: %.2lf\n", tf,tc,tk);
	
	
	
}