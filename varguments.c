/****************************************************************
*FILE NAME: varguments.c
*
*
*
*PURPOSE: explore the functionality of variadic functions
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
*ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
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
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <strings.h>

/*Preprocessor directives*/
#define MAXLOGSTRING 300

/*Funciton prototypes*/
int FunctionA(int argument_count,...);
void print_log_va(FILE *fp,int argcount,...);

/*Global variables*/
char log_string[MAXLOGSTRING];

/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/

/*man stdarg.h*/
int main(){
    
    FILE *fp;

    
    memset(log_string,'\0',sizeof(char *));
    fp = fopen("./text-data-files/logfile.txt","w");
    if(fp == NULL){
        perror("There was a problem with fopen");
    }
    FunctionA(3,"It is working","Hello world", "This is argument 3");
    print_log_va(fp,4,"This is argument 1 ","This is argument 2 ", "This is argument 3", "This is argument 4" );
    
    fclose(fp);
    
    return EXIT_SUCCESS;
}

/********************************************************
*
*
* FUNCTION NAME: FunctionA
*
*
*
* ARGUMENTS:argument_count, variadic argument
*
*
*
* ARGUMENT      TYPE I/O DESCRIPTION
* --------      ---- --- -----------
*argument_oount int  I   the number of  variables that are in this list
*...            
*
* RETURNS:
*
*
*
*********************************************************/

/* This is a variadic function
 * man stdarg.h
 * Also check out vfprintf() man stdio.h
 */
int FunctionA(int argument_count,...){
       
    va_list ap;
    va_start(ap,argument_count);
    
    while(argument_count--){
        strcat(log_string,va_arg(ap,char *));
        strcat(log_string," ");
    }
    
    printf("Log string: %s \n",log_string);
    va_end(ap);
    
    return 0;
}

/********************************************************
*
*
* FUNCTION NAME: print_log_va
*
*
*
* ARGUMENTS: fp,argcount
*
*
*
* ARGUMENT     TYPE   I/O DESCRIPTION
* --------     ----   --- -----------
* fp           FILE * I   pointer to a file
* argcount     int    I   the number of arguments that are being passsed in
* ...          
*
* RETURNS: void
*
*
*
*********************************************************/

/* https://stackoverflow.com/questions/14358497/what-is-the-difference-between-fprintf-and-vfprintf-in-c*/
/*int vfprintf(FILE *stream, const char *format, va_list ap);*/
/* man vfprintf */
void print_log_va(FILE *fp,int argcount,...){
    va_list ap;
    va_start(ap,argcount);
    while(argcount--){
        vfprintf(fp,"%s ",ap);
    }
    
    
}