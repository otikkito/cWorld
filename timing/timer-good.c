/****************************************************************
*FILE NAME: timer-good.c
*
*
*
*PURPOSE: To find a good way of meassuring time events within an application.
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
*ABNORMAL ERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
* None at this time.
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
*8/25/2018  Kito Joseph     01                    This file is older but anotated that this is the date that I included the file format and function headers. 
*
*ALGORITHM (PDL)
*/
//--------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>


//time programming: http://www.catb.org/esr/time-programming/
//Calculator: need to create some of this functionality but use only ns, ms,us, and second,...
//https://www.timecalculator.net/
//http://www.sengpielaudio.com/calculator-millisecond.htm
//Saleae: https://www.saleae.com/
//Oscope: https://www.testandmeasurementtips.com/category/oscilloscopes/pc-based-oscilloscopes/
/*TODO Create an alarm or timer for nanosecond, millisecond, microsecond sleep
 *man 2 nanosleep
*/

//REF: http://pubs.opengroup.org/onlinepubs/7908799/xsh/time.h.html
//How to get time in milliseconds:
//https://stackoverflow.com/questions/3756323/how-to-get-the-current-time-in-milliseconds-from-c-in-linux/17083824?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
//https://stackoverflow.com/questions/16548528/command-to-get-time-in-milliseconds/31014389#31014389
//https://en.wikibooks.org/wiki/C_Programming/time.h/time_t

/*Global variables*/
 struct timestruct{
    time_t seconds;  /*included in struct timespec*/
    time_t milliseconds;
    long microseconds;
    long nanoseconds;  /*included in struct timespec*/
  };
 
  struct timespec start; //http://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html
  struct timespec end;
  struct timespec diff1;
  struct timespec diff2;
  struct timestruct t;
  
/*Function prototype*/
void diff_timespec(struct timespec *start,struct timespec *end); 
void diff_timespec_k(struct timespec *start,struct timespec *end, struct timestruct *ts);


/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS: argc and argv
*
*
*
* ARGUMENT     TYPE    I/O DESCRIPTION
* --------     ----    --- -----------
* argc         int     I   This indicates the number of command line arguments.
* argv         char ** I   This is a pointer to an char array vector containing the command line arguments.
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/

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
    
    printf("The size of time_t is : %d \n",sizeof(time_t));
    
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

     * 
     *@@@ https://stackoverflow.com/questions/471248/what-is-ultimately-a-time-t-typedef-to
     */
    printf("It took a total of %ld sec. and %ld nanosecs. \n",diff1.tv_sec,diff1.tv_nsec);
    
    diff_timespec(&start,&end);
    
    printf("Using the new function the total seconds is %ld sec and %ld nanosecs. \n",t.seconds,t.nanoseconds);
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
 * Preemption and context switching: http://www.informit.com/articles/article.aspx?p=101760&seqNum=3
 */
/********************************************************
*
*
* FUNCTION NAME: diff_timespec`
*
*
*
* ARGUMENTS: struct timepec, struct timespec
*
*
*
* ARGUMENT     TYPE            I/O DESCRIPTION
* --------     ----            --- -----------
* *start       struct timespec I   This is the start time of the event being measured.
* *end         struct timespec I   This is the end time of the even being measured.
*
* RETURNS: currently returns void but needs to either have an output argument or return something.
*
*
*
*********************************************************/

 void diff_timespec(struct timespec *start,struct timespec *end){
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

/********************************************************
*
*
* FUNCTION NAME: diff_timespeck_k
*
*
*
* ARGUMENTS: struct timespec, struct timepsec, struct timestruct
*
*
*
* ARGUMENT     TYPE                 I/O DESCRIPTION
* --------     ----                 --- -----------
* start        struct timestruct *  I   The start time of an event.
* end          struct timestruct *  I   The end time of an event.
*
*
* RETURNS: void
*
*
*
*********************************************************/

void diff_timespec_k(struct timespec *start,struct timespec *end, struct timestruct *ts){
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

/*
 /usr/bin/time -v ./a.out 
The size of time_t is : 8 
It took a total of 0 sec. and 448293 nanosecs. 
Using the new function the total seconds is 0 sec and 448293 nanosecs. 
	Command being timed: "./a.out"
	User time (seconds): 0.00
	System time (seconds): 0.00
	Percent of CPU this job got: 0%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.00
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 480
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 161
	Voluntary context switches: 2
	Involuntary context switches: 7
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0

 */
