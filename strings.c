/* This application will present every thing there is no know about strings
 * or at least try.
 */

//http://stackoverflow.com/questions/9834067/difference-between-char-and-const-char
//https://www.cs.bu.edu/teaching/c/string/intro/
#include <stdio.h>
#include <string.h>

struct Person{
	char name[100];
	int age;
};

int main(){
	char c; //character
	char array[] = "This is a array of characters"; //character array
	char carray[3];

	struct 	Person a;
	
	strcpy(a.name,"John mf Doe"); //copies string and null terminates the string
	a.age= 45;


	printf("%s\n",array);	
	printf("%s\n",a.name);
	
	printf("garbage %c\n",carray[0]);
	carray[0]='y';
	printf("index 0: %c\n",carray[0]);
	
	return 0;
}
