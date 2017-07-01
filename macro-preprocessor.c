/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   macro-preprocessor.c
 * Author: otikkito
 *
 * Created on July 1, 2017, 9:57 AM
 */

/* Reference: 
 * https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/1.7.html 
 * http://en.cppreference.com/w/c/language/constant_expression
 * https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
 * http://northstar-www.dartmouth.edu/doc/ibmcxx/en_US/doc/language/concepts/cuexpcon.htm
 */
/*Notes:
 * constant_expression: A constant expression is an expression with a value that 
 * is determined during compilation. That value can be evaluated at runtime, but
 * cannot be changed. Constant expressions can be composed of integer, 
 * character, floating-point, and enumeration constants, as well as other 
 * constant expressions.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * 
 */
int main(int argc, char** argv){
    
    FILE *fp;
 /* #line 37 */
    printf("Working with macros and preprocessor directives %s %d\n",__FILE__, __LINE__);
    
    return (EXIT_SUCCESS);
}

