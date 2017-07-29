/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pointers.c
 * Author: otikkito
 *
 * Created on July 27, 2017, 2:31 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
   int  var1;
   char var2[10];
   int *pointer;

   printf("Address of var1 variable: %p\n", &var1  );
   printf("Address of var2 variable: %p\n", &var2  );
   
   printf("The address of pointer is %p before intialization\n",pointer);
   
   pointer++;
   printf("The address of the pointer is %p after intilaization\n",pointer);
   printf("The size of pointer is %d\n", sizeof(pointer));
   printf("The size of a int is %d\n",sizeof(var1));

    return (EXIT_SUCCESS);
}

