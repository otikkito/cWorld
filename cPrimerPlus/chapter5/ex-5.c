#include <stdio.h>

int main(){
	
	int count,sum, maxval;
	
	count = 0;
	sum = 0;
	
	printf("Please enter a max value: ");
	scanf("%d",&maxval);
	
	while(count++ < maxval)
		sum = sum + count;
	printf("sum = %d\n",sum);
	
	return 0;
	
}
	