#include <stdio.h>

int main(){

	int number;
	int maxn;
	
	printf("Please enter an integer: ");
	scanf("%d",&number);
	
	maxn= number+10;
	while(number <= maxn){
			printf("%d ",number);
			number++;
	}
	
	
}
