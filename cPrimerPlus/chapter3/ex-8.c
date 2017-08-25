#include <stdio.h>

int main(){
	float volume;
	float temp;
	printf("Please enter the volume in cups: ");
	scanf("%f",&volume);
	printf("The volume in pint is %f\n",(volume/2));
	printf("The volume in ounces is %f\n",(volume*8));
	printf("The number of tablespoons is: %f\n",((volume*8)*2));
	printf("The number of teaspoons is: %f\n",((volume*8)*2)*3);
	
}