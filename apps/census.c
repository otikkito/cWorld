/****************************************************************
*FILE NAME: census.c
*
*
*
*PURPOSE: 
* 
*
*FILE REFERENCES:
*
*NAME		I/O		Description
*----           ---             -----------
*
*EXTERNAL VARIABLE:
*SOURCE: <         >
*
*NAME	  TYPE    	I/O		Description
*----     ----          ---             -----------
*
*EXTERNAL REFERENCES:
*
*Name		Description
*----   	-----------
*
*ABNORMAL ERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
*
*ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
*
*NOTES:
*
*REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*DEVELOPMENT HISTORY:
*
*Date		Author		Change ID	Release		Description of Change
*----   	------  	---------   -------     ---------------------
*
*ALGORITHM (PDL)
*/

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   census.c
 * Author: otikkito
 *
 * Created on May 6, 2017, 5:31 PM
 * 
 * http://stackoverflow.com/questions/11280523/c-reading-from-file-into-structure
 * https://docs.python.org/2/library/os.html  ->converting file to a easy format
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>

#define MAXLINESIZE 1000

/*Global variables*/


/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS: argc and argv
*
*
*
* ARGUMENT     TYPE    I/O DESCRIPTION
* --------     ----    --- -----------
*argc          int      I  the number of command line arguments
*argv          char **  I  the char arraay vector for the command line arguments
*
* RETURNS:
*
*
*
*********************************************************/
int main(int argc, char** argv) {

    FILE *fp;
    char line[MAXLINESIZE];
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL){
        fprintf(stdout, "Current working dir: %s\n", cwd);
    }
    else
       perror("getcwd() error");
    
    fp=fopen("../text-data-files/census-dist-male-first.txt","r");
    
    if (fp == NULL){
        perror("Unable to open:../text-data-files/census-dis-male-first.txt");
        exit(EXIT_FAILURE);
    }
    
    while(fgets(line,MAXLINESIZE,fp)){
        printf("%s",line);
        char *tokens;
        tokens = strtok(line," ");
        while(tokens != NULL){
            printf("%s \n",tokens);
            tokens = strtok(NULL, " ");
        }
        
    }
    fclose(fp);
    return (EXIT_SUCCESS);
}


/*TODO design a function that takes a string separated by a undefined number of 
 * of spaces and returns a token for each of the space delimited words