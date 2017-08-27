#include <stdio.h>

#define DAYSINWEEK 7

int main(){
	
	int daysinput;
	
	printf("Please enter the number of days: ");
	scanf("%d",&daysinput);
	
	printf("%d days are %d weeks, %d days\n", daysinput, (daysinput / DAYSINWEEK), (daysinput % DAYSINWEEK));
	
	return 0;
}	