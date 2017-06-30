/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kerneltest.c
 * Author: otikkito
 *
 * Created on June 29, 2017, 1:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    
    
    /*https://www.mkssoftware.com/docs/man3/getpriority.3.asp*/
    i = getpriority(PRIO_PROCESS, getpid());
    printf("The priority of this application is %d \n",i);
    while(true){
        sleep(1);
    }
    return (EXIT_SUCCESS);
}

