/****************************************************************
 *FILE NAME:applicationstub.c
 *www.kjoseph-it.com 
 *https://github.com/otikkito/cWorld/blob/master/nasa-c-style.pdf
 *https://en.wikipedia.org/wiki/Application_security
 *https://www.tutorialspoint.com/c_standard_library/index.htm
 *https://en.wikipedia.org/wiki/MIL-STD-498 
 *https://www.ece.ncsu.edu/people/gbyrd 
 *
 *PURPOSE: 
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
 *
 *ALGORITHM (PDL)
 */

/*
 *Global TODO
 * 1)
 * 2)
 */
 

#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <syslog.h>



/*Global variables*/
/*TODO Need to change the logfile to fit the application*/
char logfile[] = "./text-data-files/logfile.txt"; 
FILE *fp;
pid_t processid;


/*Function prototypes*/
void print_application_header();
void print_log_file(FILE *f, char *string);
void signal_handler();
void bye(void);
const char* get_process_name_by_pid(pid_t pid);

/*
 This is the entry point of program execution from the operating system and shell.
 */
int main(int argc, char** argv) {

    
    int i;
    struct sigaction action;
    action.sa_handler = signal_handler;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);
    sigaction(SIGSEGV, &action, NULL);

    

    i = atexit(bye);
    if (i != 0) {
        perror("Unable to set atexit()");
        exit(EXIT_FAILURE);
    }

    /*The current pid of the process*/
    processid = getpid();

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
     *proper logging and handling of errors by checking return codes!
     * https://github.com/otikkito/cWorld/blob/master/applicationstub.txt
     */

    sleep(60);

    return 0; /*return 0 indication successful completion of the application*/

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
    /*TODO This is the template and need to changed to fit the application needs*/
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

/*TODO print a variable argument list log file 
 https://github.com/otikkito/cWorld/blob/master/logger.c
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
    /*To terminate kill -s 15 <pid>*/
    /*https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf*/
    switch (signal) {
        case SIGINT:
            /*TODO need to find a way to print to the logfile with multiple arguments*/
            fprintf(stdout, "Received SIGINT from process with pid = %u\n", info->si_pid);
            syslog(LOG_ERR, "Received signal SIGINT and will be shutting down application.c ");
            exit(EXIT_FAILURE);
        case SIGSEGV:
            fprintf(stdout, "Received SIGSEGV from process with pid = %u\n", info->si_pid);
            syslog(LOG_ERR, "Received signal SIGSEGV and will be shutting down application.c ");
            exit(EXIT_FAILURE);
        case SIGTERM:
            fprintf(stdout, "Received SIGTERM from process with pid = %u\n", info->si_pid);
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
/*signals that should be handle 
kill -l
https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf
http://man7.org/linux/man-pages/man7/signal.7.html
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX	
 */
