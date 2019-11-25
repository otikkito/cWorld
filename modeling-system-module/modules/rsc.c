#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


struct rscOut{
	FILE *output; /* A pointer to the output of the command */
	int rc; /* The return code of the command */
};

FILE *runSystemCommand(const char *system_comand); /*File return implementation */
struct rscOut *runSystemCommandStruc(const char *system_comand); /* structure implementation */



/*
 Some of the problems and design considerations for runSystemCommand
 1. ensure that the command is right before trying to running the command
 2. I ran into a problem with "ps -aux" and "ps - aux" with cygwin
 3. locating substring in string "strstr()" function
 4. Return code of the process echo $? of piped process
 
 example commands to run on RHEL and cygwin:
 1. "ps -aux"-> RHEL, "ps - aux" ->cygwin
 2. ls
*/
/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS:
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS:
*
*
*
*********************************************************/
int main(int argc, char** argv) {
	FILE *fp;
	char line[LINE_MAX];
	int rc; /* Return code of the closed process*/
	
	printf("Welcome to run system command.\n");
	
	fp = runSystemCommand("ls");
	
	if(fp == NULL ){
		perror("Unable to use popen with that command or error with popen.");
		exit(EXIT_FAILURE);
	}
	/* char *fgets(char *s, int size, FILE *stream); */
	while((fgets(line,LINE_MAX,fp)) != NULL){
		printf("%s",line);
	}
	rc = pclose(fp);
	printf("The return code for this runSystemCommand is: %d \n",rc);
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME:
*
*
*
* ARGUMENTS:
*
*
*
* ARGUMENT         TYPE        I/O DESCRIPTION
* --------         ----        --- -----------
* system_command   const char   I   this is the command that will be run
*
*
* RETURNS:
*
*
*
*********************************************************/
FILE *runSystemCommand(const char *system_command){
	/* man popen */
	/*
 	FILE *popen(const char *command, const char *type);
        int pclose(FILE *stream);
        */

	FILE *fp = NULL;
	fp=popen(system_command,"r");
	
	
	return fp;
}

/********************************************************
*
*
* FUNCTION NAME: runSystemCommandStruc
*
*
*
* ARGUMENTS:
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS:
*
*
*
*********************************************************/
struct rscOut *runSystemCommandStruc(const char *system_comand){
	
}