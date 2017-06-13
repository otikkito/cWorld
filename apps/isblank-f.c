#include <stdio.h>
#include <ctype.h>


int main(){

	int i;

	i = isblank(' ');
	printf("The return value of isblank is: %d \n",i);
        i = isblank('A');
        printf("The return value of isblank is: %d \n",i);
	return 0;
}

