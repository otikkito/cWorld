#include <stdio.h>
#include <string.h>

int main(){
	
	char fname[20];
	char lname[20];
	
	printf("Please enter the users first name: ");
	scanf("%s",fname);
	printf("Please enter the users last name: ");
	scanf("%s",lname);
	printf("%-20s %-20s\n",fname,lname);
	//Need to fix the output on this. There is no way that I know if given the functions that we are permitted to use
	
	printf("%20zd %20zd\n",strlen(fname),strlen(lname));

	return 0;
	
	
}