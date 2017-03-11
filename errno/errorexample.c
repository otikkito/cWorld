#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//function prototype
void shutdown(void);

int main(){
	FILE *fp;
	int i;
	
	printf("We will be testing error codes in this program\n");
	
	i = atexit(shutdown);
	if(i!=0){
		perror("Cannot set exit function");
		exit(EXIT_FAILURE);
     }

	fp=fopen("errno1.txt","r");
	if(fp==NULL){
	perror("There was a problem opening the file errno1.txt");
	system("ls");
	exit(EXIT_FAILURE); 
//Unsuccessful  termination  for  exit();  evaluates to a non-zero value.

    }
	
	return EXIT_SUCCESS;
//Successful termination for exit(); evaluates to 0
}

void shutdown(void){
	printf("Well we are shutting down now!\n");
}
/*
We will be testing error codes in this program
There was a problem opening the file errno1.txt: No such file or directory
a.out  errno.txt  errorexample.c
[root@localhost errno]# echo $?
1

*/
