/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   alarm-k.c
 * Author: otikkito
 *
 * Created on June 29, 2017, 9:07 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

/*Function prototype*/
void signal_handler(int sig);
/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigaction(SIGALRM, &action, NULL);
    printf("Before the alarm.\n");
    
    i=alarm(5);
    printf("The value of i is %d \n",i);
    while(true){
        sleep(100);
        
    }
    return (EXIT_SUCCESS);
}

void signal_handler(int signal){
    if(signal == SIGALRM){
        printf("Recieved signal sigalarm \n");
    }
}