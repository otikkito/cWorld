#include <stdio.h>

int main(){
	
	int secoperand;
	int firoperand;
	
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d",&secoperand);
	printf("Now enter the first operand: ");
	scanf("%d",&firoperand);
	printf("%d %% %d is %d\n",firoperand,secoperand,firoperand % secoperand);
	
	while(firoperand > 0){
		printf("Enter next number for the first operand (<= 0 to quit): ");
		scanf("%d",&firoperand);
		printf("%d %% %d is %d\n",firoperand,secoperand,firoperand % secoperand);
	}
	
	return 0;
	
}