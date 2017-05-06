#include <stdio.h>
#include <stdlib.h>

/*http://www.cprogramming.com/tutorial/cfileio.html*/
//Perform some basic io
#define MAXLINESIZE 300

int printFileToConsole(char *fn);

int main(){

	char textfile[] = "./text-data-files/rqmsgs_t";
	//char namefile[] = "./text-data-files/census-dist-male-first.txt"
	
	printFileToConsole(textfile);
	
	return 0;	
}

int printFileToConsole(char *fn){
	
	char line[MAXLINESIZE];
	FILE *fp;

	fp = fopen(fn,"r");
	
	if(fp == NULL){
		perror("Error opening file");
		exit(-1);
	}

	while(fgets(line,MAXLINESIZE,fp)){
		printf("%s",line);
	}
	
	fclose(fp);

	return 0;
}

/*post analysis
-not sure if the buffered approched is quick 
-not sure how to determine the line size I guess you could check to see the max size of a line
When ranned with the printf
real	0m1.249s
user	0m0.003s
sys	0m0.011s
When ranned without the printf
real	0m0.001s
user	0m0.001s
sys	0m0.000s

size ./a.out 
   text	   data	    bss	    dec	    hex	filename
   1588	    508	     16	   2112	    840	./a.out

valgrind --tool=memcheck ./a.out
==2791== Memcheck, a memory error detector
==2791== Copyright (C) 2002-2012, and GNU GPL'd, by Julian Seward et al.
==2791== Using Valgrind-3.8.1 and LibVEX; rerun with -h for copyright info
==2791== Command: ./a.out
==2791== 
==2791== 
==2791== HEAP SUMMARY:
==2791==     in use at exit: 0 bytes in 0 blocks
==2791==   total heap usage: 1 allocs, 1 frees, 568 bytes allocated
==2791== 
==2791== All heap blocks were freed -- no leaks are possible
==2791== 
==2791== For counts of detected and suppressed errors, rerun with: -v
==2791== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 6 from 6)

*/
