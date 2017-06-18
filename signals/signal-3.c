/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   signal-3.c
 * Author: otikkito
 *
 * Created on March 27, 2017, 10:28 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

/*
 * http://www.csl.mtu.edu/cs4411.ck/www/NOTES/signal/two-signals.html
 * man sigaction
 */

//Function declarations
void signal_handler(int sig);


int main(int argc, char** argv) {
    struct sigaction sa;
    
    sa.__sigaction_handler =signal_handler;
    sa.sa_flags =   0;
    sigemptyset(sa.sa_mask);
    
    if(sigaction(SIGINT,&sa, NULL) = -1){
        perror("There is a problem with sigaction");
        return (EXIT_FAILURE);
    }
    
    sleep(100);
    return (EXIT_SUCCESS);
}

void signal_handler(int sig){
    printf("We recieved a signal and will be handle exiting stuff");
}