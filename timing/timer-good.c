/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   timerg.c
 * Author: otikkito
 *
 * Created on June 18, 2017, 9:23 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


/* man clock_gettime
 * https://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
 * "If you want to compute the elapsed time between two events observed on the 
 * one machine without an intervening reboot, CLOCK_MONOTONIC is the best option." 
 */
/*
 struct timespec
time_t  tv_sec    Seconds.
long    tv_nsec   Nanoseconds.
 * 
 */

//milliseconds = nanoseconds ÷ 1,000,000
//nanoseconds = milliseconds x 1,000,000
//stuct timespec
//time_t  tv_sec    Seconds.
//long    tv_nsec   Nanoseconds.
// time_t and clock_t shall be integer or real-floating types (man type.h)
/*
 
 struct timestruct{
    time_t seconds;
    time_t milliseconds;
    long nanoseconds;
  };
 
 */

  
  //Function prototype
  //struct timerstruc convert_timespect(struct timestruc temp)

/*TODO need to break it down to seconds, milli seconds and nano seconds*/
int main(int argc, char** argv) {
    
    int i;
    struct timespec start;
    struct timespec end;
    struct timespec diff;
    
    
    i = clock_gettime( CLOCK_MONOTONIC,&start);
    if(i == -1){
        perror("clock_gettime");
    }
    
    /*Do something in the interim while time has elapsed*/
    sleep(3);
    //usleep(34);
    
    
    
    i = clock_gettime( CLOCK_MONOTONIC,&end);
    if(i == -1){
        perror("clock_gettime");
    }
    
    diff.tv_sec = (end.tv_sec - start.tv_sec);
    diff.tv_nsec = (end.tv_nsec - start.tv_nsec);
    
    printf("It took a total of %d sec. and %ld nanosecs \n",diff.tv_sec,diff.tv_nsec);
    return (EXIT_SUCCESS);
}   

