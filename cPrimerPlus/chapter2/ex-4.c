#include <stdio.h>

void jolly();
void deny();

int main(){
	printf("For he's a ");
	jolly();
	printf(" fellow!\n");
	printf("For he's a ");
	jolly();
	printf(" fellow!\n");
	printf("For he's a ");
	jolly();
	printf(" fellow!\n");
	deny();
}


void jolly(){
	printf("jolly good");
}

void deny(){
	printf("Which nobody can deny!\n");
}