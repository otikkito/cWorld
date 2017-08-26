#include <stdio.h>

int main(){
	
	int height;
	char name[50];
	
	printf("Pleae enter you height in inches and you first name: ");
	scanf("%d %s",&height,name);
	printf("%s, you are %f feet tall\n",name,(float)(height/12));
	
}