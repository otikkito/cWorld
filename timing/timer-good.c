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
#include <sys/types.h>


/* https://en.wikipedia.org/wiki/Time
 * man clock_gettime
 * https://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
 * "If you want to compute the elapsed time between two events observed on the 
 * one machine without an intervening reboot, CLOCK_MONOTONIC is the best option." 
 * 
 * 
 * http://www.catb.org/esr/time-programming/
 */

/*
 
	
https://stackoverflow.com/questions/16740014/computing-time-in-linux-granularity-and-precision

On Linux, the available timers with increasing granularity are:

    clock() from <time.h> (20ms or 10ms resolution?)

    gettimeofday() from Posix <sys/time.h> (microseconds)

    clock_gettime() on Posix (nanoseconds?)


 */
/*
 struct timespec
time_t  tv_sec    Seconds.
long    tv_nsec   Nanoseconds.
 * 
 *POSIX.1b
 *milliseconds = nanoseconds ÷ 1,000,000
*nanoseconds = milliseconds x 1,000,000
*A microsecond is equal to 1000 nanoseconds
*stuct timespec
 *time_t  tv_sec    Seconds.
 *long    tv_nsec   Nanoseconds.
 *time_t and clock_t shall be integer or real-floating types (man type.h)
*/
/*the different resolution for sleep are listed below:
 man clock_nanosleep
 man nanosleep
 
 * 
 */

 struct timestruct{
    time_t seconds;  /*included in struct timespec*/
    time_t milliseconds;
    long microseconds;
    long nanoseconds;  /*included in struct timespec*/
  };
 
/*Function prototype*/
inline void diff_timespec(struct timespec *start,struct timespec *end); 

 struct timespec start;
 struct timespec end;
 struct timespec diff1;
 struct timespec diff2;
 struct timestruct t;

 

  
  /*Function prototype*/
  /*struct timerstruc convert_timespect(struct timestruc temp)*/

/*TODO need to break it down to seconds, milli seconds and nano seconds*/
int main(int argc, char** argv) {
    
    int i;
    
    
    i = clock_gettime( CLOCK_MONOTONIC,&start);
    if(i == -1){
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }
    
    /*Do something in the interim while time has elapsed*/
    /*sleep(3);*/
    usleep(340);
    
    
    
    i = clock_gettime( CLOCK_MONOTONIC,&end);
    if(i == -1){
        perror("clock_gettime");
    }
    
    diff1.tv_sec = (end.tv_sec - start.tv_sec);
    diff1.tv_nsec = (end.tv_nsec - start.tv_nsec);
    
    /*TODO 
     * gcc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-11)
     timer-good.c:115:5: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘__time_t’ [-Wformat=]
     printf("It took a total of %d sec. and %d nanosecs. \n",diff1.tv_sec,(double)diff1.tv_nsec);

     */
    printf("It took a total of %d sec. and %d nanosecs. \n",diff1.tv_sec,diff1.tv_nsec);
    
    diff_timespec(&start,&end);
    
    printf("Using the new function the total seconds is %d sec and %ld nanosecs. \n",t.seconds,t.nanoseconds);
    return (EXIT_SUCCESS);
}   

/*
 * https://stackoverflow.com/questions/10540826/netbeans-does-not-show-functions-list-defined-in-the-currently-opened-php-file
 */

/*This fixed does not work for me so I might have to open up a new bug. Also
 the compiler is giving errors for this as well
 error: return type is an incomplete type
 struct timestruc diff_timespec(struct timespec *start,struct timespec *end){
 * 
 * To convert between types: https://stackoverflow.com/questions/15024623/convert-milliseconds-to-timespec-gnu-porting
 */
inline void diff_timespec(struct timespec *start,struct timespec *end){
    /*
     * https://en.wikipedia.org/wiki/Inline_function
    milliseconds = nanoseconds ÷ 1,000,000
    nanoseconds = milliseconds x 1,000,000
    A microsecond is equal to 1000 nanoseconds
     */ 
    t.seconds = ((end->tv_sec)-(start->tv_sec));
    /*
     * t.milliseconds
     * t.microseconds
     */
    t.nanoseconds = ((end->tv_nsec)-(start->tv_nsec));
    
}