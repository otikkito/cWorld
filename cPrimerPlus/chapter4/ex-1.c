#include <stdio.h>

int main(){
	char fname[50];
	char lname[50];
	
	printf("Please enter your first name: ");
	scanf("%s",fname);
	printf("Please enter your last name: ");
	scanf("%s",lname);
	printf("The name that you entered was %s, %s\n",lname,fname);
	
	return 0;
	
}