#include <stdio.h>

#define MINSINHOUR 60

int main(){
	
	int mins;
	
	
	printf("Please enter time in minutes: ");
	scanf("%d",&mins);
	printf("The number of the number of hours: %d the number of mins: %d\n",(mins/MINSINHOUR),(mins % MINSINHOUR));
	while(mins > 0){
		printf("Please enter time in minutes: ");
		scanf("%d",&mins);
		printf("The number of the number of hours: %d the number of mins: %d\n",(mins/MINSINHOUR),(mins % MINSINHOUR));
		
	}

}	
	