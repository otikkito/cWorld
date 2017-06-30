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
    
    FunctionA("Hello world");
    return EXIT_SUCCESS;
}

/*This is a variadic function
 man stdarg.h
 */
int FunctionA(int argument_count,...){
    va_list ap;
    va_start(ap,count);
    
    printf("String: %s \n",string);
    return 0;
}