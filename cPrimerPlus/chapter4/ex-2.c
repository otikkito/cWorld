#include <stdio.h>


int main(){
	
	char fname[50];
	
	printf("Please enter your first name: ");
	scanf("%s",fname);
	printf("\"%s\"\n",fname);
	printf("\"%20s\"\n",fname);
	printf("\"%-20s\"\n",fname);
	printf("\"%-s   \"\n",fname);
	return 0;
	
}