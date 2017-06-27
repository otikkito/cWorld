#include <stdio.h>   //printf
#include <stdlib.h>  //man stdlib.h
#include <stdbool.h> //true
#include <unistd.h>  //sleep
#include <sys/types.h> //defines pid_t


//Good tutorial on understanding of process memory --> 
//https://techtalk.intersec.com/2013/07/memory-part-1-memory-types/
//https://techtalk.intersec.com/2013/07/memory-part-2-understanding-process-memory/
//Use pmap in conjection with running this program to get a better understand of whats going on
//ex.  pmap
//Tutorial about the buffers http://wr.informatik.uni-hamburg.de/_media/teaching/wintersemester_2012_2013/epc-1213-brauer-buffer-praesentation.pdf
//heap -> malloc
//stack -> function calls,arguments
//TODO Need to find out if there is a way to print the stack frame
//TODO see if we can find out if there is buffer overflow
/*
	^     heap allocation    |
	|     stack allocation   |
	|     static allocation  |
	|
    flexibility                  allocation cost
*/
//static declaration of memory is quicker than dynamic allocation
int main(){
	int i;
	char string[] = "string that is a string in memory.c";
	
	
	printf("The pid of this program is: %d\n",getpid());
	printf("The address of i is %p \n",&i);
	
	while(true){
		sleep(100);
	}
	return 0;
}
