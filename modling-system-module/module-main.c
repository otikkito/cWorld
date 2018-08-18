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
	
	printf("Welcome to module main.\n");
	printf("The module name is: %s\n",get_process_name_by_pid(getpid()));
	
    return (EXIT_SUCCESS);
}

