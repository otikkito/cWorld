#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>

//www.kjoseph-it.com

/*I will log a couple of things to the application log 
*and if this code is executing on Linux we will log stuff to the syslog
*/
/* TODO need to create a macro of print_log 
 Also could do some measurements as far as which one is quicker
*/

/*

    -Use the most verbose time granularity possible.
    -Put the timestamp at the beginning of the line. The farther you place a timestamp from the beginning, the more difficult it is to 	    tell it's a timestamp and not other data.
    -Include a four-digit year.
    -Include a time zone, preferably a GMT/UTC offset.
    -Time should be rendered in microseconds in each event. The event could become detached from its original source file at some 	  point, so having the most accurate data about an event is ideal.

*/

/*function prototype*/
int print_log(char *string);
int print_syslog(char *string);
int print_logfile(FILE *fp, char *string);
int print_logfile_va(FILE *fp, ...);//proof of concept
int print_logfile_s(FILE *fp, char *string,...);//proof of concept
int print_logfile_pid(FILE *fp, char *string, pid_t pid);
const char* get_process_name_by_pid(pid_t pid);

/*Global Variables*/
FILE *fp;

int main(){
	
	char logfile[]= "./text-data-files/logfile.txt";

	fp = fopen(logfile,"a+");   //Initially caused a segfault because no error checking	
	if(fp == NULL){
		perror("Errror with fopen");
	}
	print_logfile(fp,"And we printing to the log file");
	print_log("Error you machine is going down");
	print_syslog("Holy moly you got another error");
        print_logfile_pid(fp,"The pid of this process is: ",getpid());
        
	fclose(fp);
	return 0;

}

/********************************************************
*
*
* FUNCTION NAME:
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
int print_log(char *string){

	char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
	printf("%s: %s\n",timestring,string);

	return 0;	
}

/********************************************************
*
*
* FUNCTION NAME:
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
/* More information can be found man 3 syslog */
int print_syslog(char *string){
	syslog(LOG_ERR,"Just playing");
	return 0;
}
/********************************************************
*
*
* FUNCTION NAME:
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
int print_logfile(FILE *f, char *string){
	char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
	fprintf(f,"%s %s \n",timestring,string);	
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME:
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
int print_logfile_pid(FILE *fp, char *string, pid_t pid){
        char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
	fprintf(fp,"%s %s %d %s\n",timestring,string,pid,get_process_name_by_pid(pid));
    return 0;   
}

/********************************************************
*
*
* FUNCTION NAME:
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
/*
 * Doing this will make it non portable or a good idea another way is to try with sprintf
 * int sprintf(char *str, const char *format, ...);
 man stdarg.h
 https://linux.die.net/man/3/va_arg
 *
 * https://github.com/otikkito/cWorld/blob/master/varguments.c
 */
int print_logfile_va(FILE *f, ...){
    
}

/********************************************************
*
*
* FUNCTION NAME: get_process_name_by_pid
*
*
*
* ARGUMENTS: pid_t which is defined in <sys/types.h>
*
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS: A pointer to a constant char
*
*
*
*********************************************************/
/* can also be done be running ps -p PID -i comm= */
const char* get_process_name_by_pid(pid_t pid)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name){
        sprintf(name, "/proc/%d/cmdline",pid);
        FILE *f = fopen(name,"r");
        if(f){
            size_t size;
            size = fread(name, sizeof(char), 1024, f);
            if(size>0){
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(f);
        }
    }
    return name;
}
/*********************************************************************/