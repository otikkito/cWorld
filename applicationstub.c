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
 *-Some of the abnormal conditions will exit the program using the bye funcction and EXIT_FAILURE...
 *
 *ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
 *
 *NOTES:
 *
 *REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
 *
 *DEVELOPMENT HISTORY:
 *
 *Date		     Author		  Change ID	   Release		Description of Change
 *----   	     ------  	  ---------    -------      ---------------------
 *2/22/2017      Kito Joseph					        Added a prolog.I am not sure if it should be prolog or file format...
 *8/19/2018      Kito Joseph                            Continuing correction/refining documentation and file format/prolog to form a standard file format for application development.
 *8/26/2018      Kito Joseph                            Formating the file to conform to the nasa-c-style
 *
 *ALGORITHM (PDL)
 *
 */

/*
 *Global TODO
 * 1) Find a way to create a file template in the IDE for c files (This can be done by using tools->Template). I would like use the applicationstub for template after its cleaned up
 * 2) Highlight TODO Tools/Options/Team/Action Items
 * 3) Continue to clean up code and correct typos
 * 4) Remove some of the notes
 * 5) Add to the applicationstub.txt notes on what to do and remove from code
 * 6) Changed the license header to include the file format and which license you would like to use. 
 * 7) I need to find a way to see if there is any way to get the process and system utilization
 *    https://stackoverflow.com/questions/3769405/determining-cpu-utilization
 * 8) Figure out how to read in the configuration file and configuration file variables (i.e. application log location,...)
 * 9) Skeleton (computer programming) wiki
 * 10) Fix the application log so that it displays the time the application for terminated
 * 11) Correct the naming convention of functions and variables to match the nasa-c-style.
 * 12) ...
 */
 

#include <stdio.h> //FILE, printf, fopen
#include <time.h>
#include <unistd.h> //alarm, getcwd, getpid, ...
#include <stdlib.h> //EXIT_SUCCESS, EXIT_FAILURE, NULL,...
#include <syslog.h>
#include <string.h> //memset
#include <stdbool.h> //true,false
//#include <signal.h>
//#include <errno.h>
//#include <sys/types.h>

/*Preprocessor commands*/
#define MAXLOGENTRYSIZE 300
#define MAXCONFIGLINESIZE 300

/*Global variables*/
char logfile[] = "./text-data-files/logfile.txt";
FILE *fp; /*Used for global log file TODO add a more descriptive name.*/
pid_t processid; /*TODO try to use more descriptive name*/
struct configurationDirectives{
	bool initializeSignalHandler;
};

/*
Function prototypes or function declarations: //EXIT_SUCCESS or EXIT_FAILURE
https://stackoverflow.com/questions/8496284/terminology-forward-declaration-versus-function-prototype?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
int printApplicationHeaderToConsole(); 
int readConfigurationFile();
int printLogFile(FILE *f, char *string);
void signalHandler();
void bye(void);
const char* getProcessNameByPid(pid_t pid);
int initializeSignalHandles();



/*This is the entry point of program execution from the operating system and shell.*/
int main(int argc, char** argv) {
    /*As a design consideration minimize stuff in the main function for no particular reason other than readability and modulation */
    int i;
    
    initializeSignalHandles();
    i = atexit(bye);
    if (i != 0) {
        perror("Unable to set atexit()");
        printLogFile(fp,"Unable to set atexit()\n");
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

    printApplicationHeaderToConsole();
    printLogFile(fp, "Application started.\n");
    readConfigurationFile();
	
    /*
     * Starting place of the application and application logic. Add code below and remember 
     * to do proper logging and handling of errors by checking return codes! The main
     * function will return EXIT_SUCCESS or EXIT_FAILURE depending on if there 
     * are any runtime errors in the application. The application stub goal is 
     * to ensure that there are no compile errors thus only having runtime 
     * errors which should be handled correctly and prevented if thats possible.
     * https://github.com/otikkito/cWorld/blob/master/applicationstub.txt
     */
   
	printLogFile(fp, "This is before the sleep");
	
     sleep(60);
    
     printLogFile(fp, "Application terminated.\n");
 
     return (EXIT_SUCCESS); /*return EXIT_SUCCESS indication successful completion of the application*/
}

/*********************************************************************/


/********************************************************
 *
 *
 * FUNCTION NAME: printApplicationHeaderToC`onsole
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
 * RETURNS: EXIT_SUCCESS or EXIT_FAILURE
 *
 *
 * TODO:
 * 1) print also to the log file and console (stdout)
 *********************************************************/
int printApplicationHeaderToConsole() {
    printf("The process id of this application is: %d\n", processid);
    printf("Welcome to the application stub.\nThe  purpose of this program ");
    printf("is to build a solid framework \nfor the application development ");
    printf("process.\n");
    printf("----------------------------------------------------------------\n");
    printf("The process name of this process is: %s \n", getProcessNameByPid(processid));
	
	return(EXIT_SUCCESS);
}

/********************************************************
*
*
* FUNCTION NAME: redConfigurationFile();
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
* N/A
*
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/

int readConfigurationFile(){
	
	//open the file
	FILE *config_file;
	char line[MAXCONFIGLINESIZE];
	//char configDirective[MAXCONFIGLINESIZE];
	
	config_file = fopen("applicationstub.conf","r");
	
	if(config_file == NULL){
		perror("Unable to open the configuration file.\n");
		printLogFile(fp,"Unable to open the configuration file for the applicationstub.");
		return EXIT_FAILURE;
	}
	
	//populate the global cconfiguration structure
	while((fgets(line,MAXCONFIGLINESIZE,config_file)) != NULL){
		if((line[0] == '#') || (line[0] == ' ' ) || (line[0] == '\n')) { 
			continue;
		}
		else{
			printf("Config- %s\n",line);
		
			char leftConfigDirective[MAXCONFIGLINESIZE];
			char rightConfigDirective[MAXCONFIGLINESIZE];
						
			sscanf(line,"%s=%s",leftConfigDirective,rightConfigDirective);			
			printf("The left value is:%s and the right value is %s\n",leftConfigDirective,rightConfigDirective);
			
		}
	}
	//close the file
	
	fclose(config_file);
	
	return EXIT_SUCCESS;
}

/********************************************************
 *
 *
 * FUNCTION NAME: printLogFile
 * The function prints a new line at the end of the string.
 *
 *
 * ARGUMENTS: A pointer to a file and a pointer to a string
 *
 *
 *
 * ARGUMENT     TYPE    I/O DESCRIPTION
 * --------     ----    --- -----------
 * f            FILE *  I   a pointer to a file
 * string       char *  I   pointer to a character array.
 *
 *
 * RETURNS: EXIT_SUCCESS or EXIT_FAILURE
 *
 *
 *
 *********************************************************/

/* TODO print a variable argument list log file 
 * https://github.com/otikkito/cWorld/blob/master/logger.c
 * https://github.com/otikkito/cWorld/blob/master/varguments.c
 * ===Rember to flush the buffer with fflush() when logging===
 */
int printLogFile(FILE *f, char *string) {
    char timestring[100];
    time_t currenttime = time(0);
    strftime(timestring, sizeof (timestring), "%c", localtime(&currenttime));
    fprintf(f, "%s %s \n", timestring, string);
    fflush(f);
	
	return(EXIT_SUCCESS);
}

/*********************************************************************/

/********************************************************
*
*
* FUNCTION NAME: intializeSignalHandles()
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
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/

int initializeSignalHandles(){
   /* Link that talks about different types of signals: https://en.wikipedia.org/wiki/Signal_(IPC)#SIGTRAP */
    struct sigaction action;
    action.sa_handler = signalHandler;
    action.sa_flags = SA_SIGINFO; /*This is needed in order to get the pid of the offending function*/
    
	/*
	-To retrive signal names check out man 7 signal
	-Signals that will not be caught please comment out
	-Actions for each signal
	*Term: default actions is to terminate the process
	*Ign: default action is to ignore the signal
	*Core: Default action is to terminate the process and dump core
	*Stop: Default actions is to stop the process
	*Cont: Default action is to continue the process if it is currently stopped

	**Per man page a process can change the disposition of a signal using sigaction(2) or signal(2)
    * signals are define in signal.h	
	*/
    sigaction(SIGHUP, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGILL, &action, NULL);
	sigaction(SIGTRAP, &action, NULL);
	sigaction(SIGABRT, &action, NULL);
	sigaction(SIGBUS, &action, NULL);
	sigaction(SIGFPE, &action, NULL);
	sigaction(SIGKILL, &action, NULL);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGSEGV, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGPIPE, &action, NULL);
	sigaction(SIGALRM, &action, NULL);
	sigaction(SIGTERM,&action, NULL);
	//sigaction(SIGSTKFLT, &action, NULL);  //This gives a compiler error and I need to cross check with Red Hat documentation.
	sigaction(SIGCHLD, &action, NULL);
	sigaction(SIGCONT,&action, NULL);
	sigaction(SIGSTOP, &action, NULL);
	sigaction(SIGTSTP, &action, NULL);
	sigaction(SIGTTIN, &action, NULL);
	sigaction(SIGTTOU, &action, NULL);
	sigaction(SIGURG, &action, NULL);
	sigaction(SIGXCPU, &action, NULL);
	sigaction(SIGXFSZ, &action, NULL); //25
	sigaction(SIGVTALRM,&action, NULL);
	sigaction(SIGPROF, &action, NULL);
	sigaction(SIGWINCH, &action, NULL);
	sigaction(SIGIO, &action, NULL); //29
	sigaction(SIGPWR, &action, NULL);
	sigaction(SIGSYS, &action, NULL);
	sigaction(SIGRTMIN, &action, NULL);
	sigaction(SIGRTMIN+1, &action, NULL);
	sigaction(SIGRTMIN+2, &action, NULL);
	sigaction(SIGRTMIN+3, &action, NULL);
	sigaction(SIGRTMIN+4, &action, NULL);
	sigaction(SIGRTMIN+5, &action, NULL);
	sigaction(SIGRTMIN+6, &action, NULL);
	sigaction(SIGRTMIN+7, &action, NULL);
	sigaction(SIGRTMIN+8, &action, NULL);
	sigaction(SIGRTMIN+9, &action, NULL);
	sigaction(SIGRTMIN+10, &action, NULL);
	sigaction(SIGRTMIN+11, &action, NULL);
	sigaction(SIGRTMIN+12, &action, NULL);
	sigaction(SIGRTMIN+13, &action, NULL);
	sigaction(SIGRTMIN+14, &action, NULL);
    sigaction(SIGRTMIN+15, &action, NULL);
	sigaction(SIGRTMAX-14, &action, NULL);
	sigaction(SIGRTMAX-12, &action, NULL);
	sigaction(SIGRTMAX-11, &action, NULL);
	sigaction(SIGRTMAX-10, &action, NULL);
	sigaction(SIGRTMAX-9, &action, NULL);
	sigaction(SIGRTMAX-8, &action, NULL);
	sigaction(SIGRTMAX-7, &action, NULL);
	sigaction(SIGRTMAX-6, &action, NULL);
	sigaction(SIGRTMAX-5, &action, NULL);
	sigaction(SIGRTMAX-4, &action, NULL);
	sigaction(SIGRTMAX-3, &action, NULL);
	sigaction(SIGRTMAX-2, &action, NULL);
	sigaction(SIGRTMAX-1, &action, NULL);
	sigaction(SIGRTMAX, &action, NULL);

	return(EXIT_SUCCESS);
}
/********************************************************
 *
 *
 * FUNCTION NAME:signalHandler
 *
 *
 *
 * ARGUMENTS: Signal type, siginfo_t, void *
 *
 *
 *
 * ARGUMENT     TYPE        I/O DESCRIPTION
 * --------     ----        --- -----------
 * signal       int         O   The signal that is being handled  
 * info         siginfo_t   O   This is additional information about the signal and called signal
 * *_unused     void *      U   This is unused and is passes null in the function call
 *
 * RETURNS: void
 *
 *
 *
 *********************************************************/
void signalHandler(int signal, siginfo_t *info, void *_unused) {
    /*
     * http://man7.org/linux/man-pages/man2/sigaction.2.html --> "You must set the sa_flags field"
     * "you must set the sa_flags field of your struct sigaction with the flag SA_SIGINFO"
     * https://stackoverflow.com/questions/15148714/signals-siginfo-t-info-causes-segmentation-fault
	 *read man signal.h
     */
    char app_log_message[MAXLOGENTRYSIZE];
    
    memset(app_log_message,'\0',sizeof(app_log_message));
    /*siginfo_t not returning properly*/
    sprintf(app_log_message,"The application received signal %d from pid: %u with process name %s",signal,info->si_pid, getProcessNameByPid(info->si_pid));
    /*Log to the application log the signal*/
    printLogFile(fp,app_log_message);  
    
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
 * FUNCTION NAME: getProcessNameByPid
 *
 *
 *
 * ARGUMENTS: pid_t which is defined in <sys/types.h>
 *
 *
 *
 *
 * ARGUMENT     TYPE    I/O DESCRIPTION
 * --------     ----    --- -----------
 *pid           pid_t   I   This is the proccess ID of the application.
 *
 *
 * RETURNS: A pointer to a constant char
 *
 *
 *
 *********************************************************/

/* can also be done be running ps -p PID -i comm= */
const char* getProcessNameByPid(pid_t pid) {
    FILE *f;
    char* name = (char*) calloc(1024, sizeof (char));
    //Need to determine if RHEL 7 or 6 is being used. /etc/redhat-release
    if(pid == 0){
        return "Kernel"; //This is the abstraction point. It abstracts systemd which should be included as well for better pin pointing.
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
 * void         void U   This function takes no arguments
 *
 *
 * RETURNS: void
 *
 *
 *
 *********************************************************/
void bye(void) {
    printf("The program is now shutting down.\n");
	printLogFile(fp,"The application has ended now");
    fclose(fp);
}


/*
 *References:
 *1) https://github.com/otikkito/cWorld/blob/master/Docs/nasa-c-style.pdf (conformity, readablity, maintance, resuability,...)
 *2) https://en.wikipedia.org/wiki/Application_security
 *3) https://www.tutorialspoint.com/c_standard_library/index.htm
 *4) https://en.wikipedia.org/wiki/MIL-STD-498 
 *5) https://www.ece.ncsu.edu/people/gbyrd 
 *6) applicationstub.txt
 *7) Reading code: http://wiki.c2.com/?TipsForReadingCode
 */
