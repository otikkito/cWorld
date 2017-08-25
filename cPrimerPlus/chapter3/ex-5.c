#include <stdio.h>

#define secondsyear 3.156e7
int main(){
	int age;
	
	printf("Please enter your age in years: ");
	scanf("%d",&age);
	printf("The number of seconds that you have been alive is %f",(secondsyear * age));
	
	return 0;
	
}