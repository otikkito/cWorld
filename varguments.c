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

/*man stdarg.h*/
int main(){
    
    FunctionA(1,"Hello world","It is working");
    return EXIT_SUCCESS;
}

/* This is a variadic function
 * man stdarg.h
 * Also check out vprintf()
 */
int FunctionA(int argument_count,...){
    va_list ap;
    va_start(ap,argument_count);
    
    printf("Count: %d %s %s\n",argument_count,va_arg(ap, char *), va_arg(ap,char *));
    return 0;
}