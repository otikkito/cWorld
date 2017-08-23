#include <stdio.h>

int main(){
	
	int age;
	int days;
	printf("Please enter you age in years\n");
	scanf("%d",&age);
	days = 365*age;
	printf("The number of days that is given you years is %d\n",days);
	
	return 0;
	
}