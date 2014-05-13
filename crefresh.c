#include <stdio.h>
#include <string.h>
#include "crefresh.h"


//function prototype are in the header file

int main(){
	//variable declaration	
	int i;
	float f;
	double d;
	char c;
	char string[] = "Hello World\n";
	int rv;
	struct datastruct ds1;
	struct datastruct ds2;

	//initialization	
	i=2+3;
	f=3.14159;
	d=3.14159;
	c='t';
	ds1.age=33;
	strcpy(ds1.name,"John Doe");
	ds1.c = 'z';
	ds2.age = 43;
	strcpy(ds2.name,"Chin Zhou");
	ds2.c = 'g';
	printf("The value of i is %d\n",i);
	printf("The value of f is %f\n",f);
	printf("The value of d is %f\n",d);
	printf("The value of c is %c\n",c);
	printf("The value of string is %s",string);
	printf("structure age: %d\n",ds1.age);
	printf("structure name: %s\n",ds1.name);
	printf("structure c: %c\n",ds1.c);
	
	//run a function
	 rv = myfunction(ds1,ds2);
	return 0;
}

int myfunction(struct datastruct a, struct datastruct b){
	int ret;
	
	ret = strcmp(a.name,b.name);
	if(ret == 0){
		printf("The name is the same\n");
	}
	else if( ret < 0){
		printf("aaaa\n");
	}
	else if (ret > 0){
		printf("bbbb\n");	
	}

	return 0; //for now
}
