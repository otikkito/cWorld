#include <stdio.h>
#include <limits.h>

int main(){

	int i = 2147483647;
	float f=0.0;
	printf("The size of int is : %d \n",(int)sizeof(int));
	printf("i=%d\n",i);
	i++;
	printf("i=%d\n",i);
	i++;
	printf("i=%d\n",i);
	//overflow occurs and it goes from negative to positive.
	printf("The size of float is : %d \n", (int)sizeof(float));
	f=3.2e38;
	f= f * 7.8e9;
	printf("The value of f is : %e\n",f);
	//overflow occurs and gives inf value
	f = 0.1234E-10 /100;
	printf("The value of f is : %e\n",f);
	//I can't seem to get underflow to occur

	
}