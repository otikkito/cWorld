/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/*Funciton prototypes*/
int FunctionA(int arg_count,...);

/*man stdarg.h*/
int main(){
    
    FunctionA("Hello world");
    return EXIT_SUCCESS;
}

int FunctionA(int arg_count,...){
    printf("String: %s \n",string);
    return 0;
}