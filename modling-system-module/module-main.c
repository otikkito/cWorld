/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   module-main.c
 * Author: otikkito
 *
 * Created on July 18, 2017, 12:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modules/system-function.h"

/*
 * 
 */
int main(int argc, char** argv) {

	//variable declaration
	
	printf("Welcome to module-main.c we will be testing some of the functions here.\n");
	printf("----------------------------------------------------------------------\n");
	printf("The module name is: %s\n",getProcessNameByPid(getpid()));
	printf("Does the file exist. 1 if it does: %d\n",fileExist("/home/Kito Joseph/sandbox/cWorld/text-data-files"));
	printf("Does the file exist. 1 if it doesL %d\n",fileExist("c:\test.h"));
	
	
	
    return (EXIT_SUCCESS);
}

