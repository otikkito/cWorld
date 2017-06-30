#include <stdio.h>

/*
 Do a little console io and printing
 */



int main(){
	
	int a,b,c,sum;
	char fname[20];
	char lname[20];

	printf("Please enter in 3 integers to be added\n");
	scanf("%d%d%d",&a,&b,&c);
	printf("Please enter you name: First name Last name\n");
	scanf("%s%s",fname,lname);
	sum = a + b + c;
	printf("Hello %s %s. The sum of these integers are: %d \n",fname,lname,sum);

	return 0;

}	
