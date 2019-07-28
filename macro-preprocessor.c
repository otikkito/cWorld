/****************************************************************
*FILE NAME: macro-preprocessor.c
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

int main(int argc, char** argv){
    
    FILE *fp;
    
 /* #line 37 */
    
    printf("Working with macros and preprocessor directives %s %d\n",__FILE__, __LINE__);
    printf("The current time and date is %s %s \n", __DATE__,__TIME__);
    
    //#error Error test
    
    return (EXIT_SUCCESS);
}

