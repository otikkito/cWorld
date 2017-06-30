/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


/*Funciton prototypes*/
int FunctionA(int argument_count,...);

/*Global functions*/


/*man stdarg.h*/
int main(){
    
    FunctionA(1,"It is working","Hello world", "This is argument 3");
    return EXIT_SUCCESS;
}

/* This is a variadic function
 * man stdarg.h
 * Also check out vfprintf() man stdio.h
 */
int FunctionA(int argument_count,...){
       
    va_list ap;
    va_start(ap,argument_count);
    /*TODO I need to fixed the order at which this is displayed*/
    printf("Count: %d %s %s %s\n",argument_count,va_arg(ap, char *), va_arg(ap,char *), va_arg(ap, char *));
    
    va_end(ap);
    return 0;
}