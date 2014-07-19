#include <stdio.h>

//Perform some basic io
#define MAXLINESIZE 300

int printFileToConsole(char *fn);

int main(){

	char filename[] = "./text-data-files/rqmsgs_t";
	
	printFileToConsole(filename);
	
	return 0;	
}

int printFileToConsole(char *fn){
	
	char line[MAXLINESIZE];
	FILE *fp;

	fp = fopen(fn,"r");
	
	if(fp == NULL){
		perror("Error opening file");
		return -1;
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

*/
