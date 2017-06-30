/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <strings.h>


/*Funciton prototypes*/
int FunctionA(int argument_count,...);

/*Global functions*/
char log_string[300];

/*man stdarg.h*/
int main(){
    memset(log_string,'\0',sizeof(char *));
    FunctionA(3,"It is working","Hello world", "This is argument 3");
    return EXIT_SUCCESS;
}

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