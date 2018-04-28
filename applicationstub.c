/****************************************************************
 *FILE NAME:applicationstub.c
 * Please see end of file for references
 * www.kjoseph-it.com 
 *
 *
 *PURPOSE: To design an application stub to begin developing applications on the
 * Linux/Unix platform
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
 *ABNORMAL TERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
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
 *----   	------  	---------       -------         ---------------------
 *2/22/2017      Kito Joseph					Added a prolog 
 *ALGORITHM (PDL)
 */

/*
 *Global TODO
 * 1) Find a way to create a file template in the IDE for c files (This can be done by using tools->Template)
 * 2) Highlight TODO Tools/Options/Team/Action Items
 * 3) Continue to clean up code and correct typos
 * 4) Remove some of the notes
 * 5) Add to the applicationstub.txt notes on what to do and remove from code
 * 6) Changed the license header to include the file format
 * 7) I need to find a way to see if there is any way to get the process and system utilization
 *    https://stackoverflow.com/questions/3769405/determining-cpu-utilization
 */
 

#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

/*Preprocessor commands*/
#define MAXLOGENTRYSIZE 300

/*Global variables*/
char logfile[] = "./text-data-files/logfile.txt";
FILE *fp;
pid_t processid;


/*Function prototypes*/
void print_application_header();
void print_log_file(FILE *f, char *string);
void signal_handler();
void bye(void);
const char* get_process_name_by_pid(pid_t pid);
void intialize_signal_handles();

/*
 This is the entry point of program execution from the operating system and shell.
 */
int main(int argc, char** argv) {
    /*As a design consideration minimize stuff in the main function*/
    int i;
    
    intialize_signal_handles();
    i = atexit(bye);
    if (i != 0) {
        perror("Unable to set atexit()");
        print_log_file(fp,"Unable to set atexit()\n");
        exit(EXIT_FAILURE);
    }

    /*The current pid of the process*/
    processid = getpid(); /*Per the documentation this function is always successful*/
    /*Open the logfile to begin logging*/
    fp = fopen(logfile, "a+");
    if(fp == NULL){
        perror("Error with fopen(). Unable to open the application log");
        exit(EXIT_FAILURE);
    }

    print_application_header();
    print_log_file(fp, "Application started.\n");
   
    /*
     * Starting place of the application. Add code below and remember to do 
     * proper logging and handling of errors by checking return codes! The main
     * function will return EXIT_SUCCESS or EXIT_FAILURE depending on if there 
     * are any runtime errors in the application. The application stub goal is 
     * to ensure that there are no compile errors thus only having runtime 
     * errors which should be handled correctly and prevented if thats possible.
     * https://github.com/otikkito/cWorld/blob/master/applicationstub.txt
     */
   
     sleep(60000);

    return EXIT_SUCCESS; /*return EXIT_SUCCESS indication successful completion of the application*/
}

/*********************************************************************/

/*Function declarations*/

/********************************************************
 *
 *
 * FUNCTION NAME: print_application_header
 *
 *
 *
 * ARGUMENTS: none
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
void print_application_header() {
    printf("The process id of this application is: %d\n", processid);
    printf("Welcome to the application stub.\nThe  purpose of this program ");
    printf("is to build a solid framework \nfor the application development ");
    printf("process.\n");
    printf("----------------------------------------------------------------\n");
    printf("The process name of this process is: %s \n", get_process_name_by_pid(processid));
}

/*********************************************************************/

/********************************************************
 *
 *
 * FUNCTION NAME: print_log_file
 *
 *
 *
 * ARGUMENTS: A pointer to a file and a pointer to a string
 *
 *
 *
 * ARGUMENT     TYPE I/O DESCRIPTION
 * --------     ---- --- -----------
 *
 *
 *
 * RETURNS:
 *Returns void
 *
 *
 *********************************************************/

/* TODO print a variable argument list log file 
 * https://github.com/otikkito/cWorld/blob/master/logger.c
 * https://github.com/otikkito/cWorld/blob/master/varguments.c
 * ===Rember to flush the buffer with fflush() when logging===
 */
void print_log_file(FILE *f, char *string) {
    char timestring[100];
    time_t currenttime = time(0);
    strftime(timestring, sizeof (timestring), "%c", localtime(&currenttime));
    fprintf(f, "%s %s \n", timestring, string);
    fflush(f);
}

/*********************************************************************/

/********************************************************
*
*
* FUNCTION NAME: intialize_signal_handles()
*
*
*
* ARGUMENTS: Void
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS: void
*
*
*
*********************************************************/

void intialize_signal_handles(){
    
    struct sigaction action;
    action.sa_handler = signal_handler;
    action.sa_flags = SA_SIGINFO; /*This is needed in order to get the pid of the offending function*/
    
    sigaction(SIGHUP, &action, NULL);
    sigaction(SIGPIPE, &action, NULL);
    sigaction(SIGALRM, &action, NULL);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    sigaction(SIGPOLL, &action, NULL);
    sigaction(SIGPROF, &action, NULL);
    sigaction(SIGVTALRM, &action, NULL);
    /*sigaction(SIGEMT, &action,NULL); Not defined in signum.h but defined in the documentation I need to cross check and get red hat distribution to verify*/
    sigaction(SIGSTKFLT, &action, NULL);
    /*sigaction(SIGHIO, &action,NULL); Not defined in signum.h but defined in the documentation I need to cross check and get red hat distribution to verify*/
    sigaction(SIGPWR, &action, NULL);
    /*sigaction(SIGLOST, &action,NULL); Not defined in signum.h but defined in the documentation I need to cross check and get red hat distribution to verify*/
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGSEGV, &action, NULL);/*Unable to recover from SIGSEGV in linux to my understanding*/ 
    
}
/********************************************************
 *
 *
 * FUNCTION NAME:signal_handler
 *
 *
 *
 * ARGUMENTS: Signal type, siginfo_t, void *
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
void signal_handler(int signal, siginfo_t *info, void *_unused) {
    /*
     * http://man7.org/linux/man-pages/man2/sigaction.2.html --> "You must set the sa_flags field"
     * "you must set the sa_flags field of your struct sigaction with the flag SA_SIGINFO"
     * https://stackoverflow.com/questions/15148714/signals-siginfo-t-info-causes-segmentation-fault
     */
    char app_log_message[MAXLOGENTRYSIZE];
    
    memset(app_log_message,'\0',sizeof(app_log_message));
    /*siginfo_t not returning properly*/
    sprintf(app_log_message,"The application received signal %d from pid: %u with process name %s",signal,info->si_pid, get_process_name_by_pid(info->si_pid));
    /*Log to the application log the signal*/
    print_log_file(fp,app_log_message);
    
    /*To terminate kill -s 15 <pid>*/
    /*man 7 signal*/
    /*TODO need to log the calling process name as well*/
    /*https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf*/
    switch (signal) {
        case SIGINT:
            /*TODO need to find a way to print to the logfile with multiple arguments*/
            fprintf(stdout, "Received SIGINT from process with pid = %u \n", info->si_pid);
            syslog(LOG_ERR, "Received signal SIGINT and will be shutting down application.c ");
            exit(EXIT_FAILURE);
        case SIGTERM:
            fprintf(stdout, "Received SIGTERM from process with pid = %u \n", info->si_pid);
            syslog(LOG_ERR, "Received signal SIGTERM and will be shutting down application.c");
            exit(EXIT_FAILURE);
    }
    
    
    
}

/*********************************************************************/
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
const char* get_process_name_by_pid(pid_t pid) {
    FILE *f;
    char* name = (char*) calloc(1024, sizeof (char));
    
    if(pid == 0){
        return "Kernel";
    }
    if (name) {
        sprintf(name, "/proc/%d/cmdline", pid);
        f = fopen(name, "r");
        if (f) {
            size_t size;
            size = fread(name, sizeof (char), 1024, f);
            if (size > 0) {
                if ('\n' == name[size - 1])
                    name[size - 1] = '\0';
            }
            fclose(f);
        }
    } 
    return name;
}
/*********************************************************************/

/********************************************************
 *
 *
 * FUNCTION NAME: bye - it performs cleanup at exit of the application.
 *
 *
 *
 * ARGUMENTS: void
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
void bye(void) {
    printf("The program is now shutting down.\n");
    fprintf(fp, "The application has ended now \n");
    fclose(fp);
}


/*
 *References:
 *1) https://github.com/otikkito/cWorld/blob/master/nasa-c-style.pdf (conformity, readablity, maintance, resuability,...)
 *2) https://en.wikipedia.org/wiki/Application_security
 *3) https://www.tutorialspoint.com/c_standard_library/index.htm
 *4) https://en.wikipedia.org/wiki/MIL-STD-498 
 *5) https://www.ece.ncsu.edu/people/gbyrd 
 *6) applicationstub.txt
 */
