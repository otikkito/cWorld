/****************************************************************
*FILE NAME: applicationstub.c
* Please see end of file for references
* www.kjoseph-it.com
* http://kitojoseph.dyndns.org
* Kito Joseph, CpE, IEEE Member #93471157
*
*PURPOSE: To design an application stub to begin developing applications on the
* Linux/Unix platform
*
*FILE REFERENCES:
*
*NAME		I/O		Description
*----      ---     -----------
*
*EXTERNAL VARIABLE:
*SOURCE: <         >
*
*NAME	  TYPE    	I/O		Description
*----    ----      ---     -----------
*
*EXTERNAL REFERENCES:
*
*Name		Description
*----   	-----------
*
*ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*-Some of the abnormal conditions will exit the program using the bye (atexit) 
*function and EXIT_FAILURE or EXIT_SUCCESS...
*
*ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
*
*NOTES:
*
*REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*DEVELOPMENT HISTORY:
*
*Date		     Author       Change ID    Release      Description of Change
*----   	     ------  	  ---------    -------      ---------------------
*2/22/2017      Kito Joseph      1                     Added a prolog.I am not sure if it should be prolog or file format...
*8/19/2018      Kito Joseph      2                     Continuing correction/refining documentation and file format/prolog to form a standard file format for application development.
*8/26/2018      Kito Joseph      3                     Formatting the file to conform to the NASA-c-style
*9/2/2018       Kito Joseph      4                     Added the configuration file reading ability to the applicationstub.c
*9/23/2018      Kito Joseph      5                     Included the application up-time to the application stub. It will print it to the application log
*5/18/2019      Kito Joseph      6                     Provided application uptime to be printed to the console
*
*ALGORITHM (PDL)
*
*/

/*
*Global TODO
* 1) Find a way to create a file template in the IDE for c files (This can be done by using tools->Template).
*	I would like use the applicationstub for template after its cleaned up
* 2) Highlight TODO Tools/Options/Team/Action Items
* 3) Continue to clean up code and correct typos
* 4) Remove some of the notes
* 5) Add to the applicationstub.txt notes on what to do and remove from code
* 6) Changed the license header to include the file format and which license you would like to use.
* 7) I need to find a way to see if there is any way to get the process and system utilization
*	https://stackoverflow.com/questions/3769405/determining-cpu-utilization
* 8) Figure out how to read in the configuration file and configuration file variables (i.e. application log location,...)
* 9) Skeleton (computer programming) wiki: https://en.wikipedia.org/wiki/Skeleton_(computer_programming)
* 10) Correct the naming convention of functions and variables to match the nasa-c-style.
* 11) Store in a variable the start time of the application in order to see how long the application has been running. --first implementation done next step is to add seconds
* 12) Fix in the logging facility the gap between logs except for the termination and start of a new application invocation.
* 13) Find out about the tab convention and use tabs instead of spaces for better readability.
*	a) https://netbeans.org/bugzilla/show_bug.cgi?id=143795
*	b) https://www.quora.com/Which-tab-size-is-better-for-programming-generally-Two-or-four 
*	c) https://github.com/kbilsted/CodeQualityAndReadability/blob/master/Articles/Readability/OptimalIndentSizeForCodeReadability.md
* 14) Read in environmental variables: https://en.wikipedia.org/wiki/Environment_variable
* 15) Remove magic numbers
  16) Document in the applicationstub.txt or another file about compiler coding practices that is cpu agnostic: https://www.keil.com/support/man/docs/armcc/armcc_chr1359124220881.htm
  17) Document in the applicationstub.txt or another file about coding standards in general: https://www.gnu.org/prep/standards/standards.html
*/

/*Include directives*/
#include <stdio.h> //FILE,printf,fopen
#include <time.h>
#include <stdlib.h> //EXIT_SUCCESS,EXIT_FAILURE,NULL,...
#include <syslog.h>
#include <string.h> //memset
#include <stdbool.h> //true,false
#include <signal.h> //sigaction
#include <errno.h>
#include <unistd.h> //getpid
#include <sys/types.h> //getpid

/*Preprocessor directives*/
#define MAXLOGENTRYSIZE 300
#define MAXCONFIGLINESIZE 300

/*Global variables*/
char logfile[] = "./text-data-files/logfile.txt";
FILE *fp; /* name short for "file pointer" */
pid_t processid; 
struct configurationDirectives{
	bool useSignalHandler;
	//Add additional configuration directives here and the configuration directives should be read in the readConfigurationFile() function
}cd;
struct timespec start_time;
struct timespec elapsed_time;

/*
Function prototypes or function declarations: //EXIT_SUCCESS or EXIT_FAILURE
https://stackoverflow.com/questions/8496284/terminology-forward-declaration-versus-function-prototype?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
*/
int printApplicationHeaderToConsole();
int readConfigurationFile();
int printLogFile(FILE *f, char *string); //already contains newline at the end of the string.
void signalHandler();
void bye(void);
const char* getProcessNameByPid(pid_t pid);
int initializeSignalHandles();
int printApplicationUptime();
int printDebugInfo();

/********************************************************
*
*
* FUNCTION NAME: main
*
*
*
* ARGUMENTS: argc, argv
*
*
*
* ARGUMENT     TYPE     I/O DESCRIPTION
* --------     ----     --- -----------
* argc         int      I   the number of command line arguments
* argv         char **  I   the character array vector to list the command line arguments
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*This is the entry point of program execution from the operating system and shell.
*
*********************************************************/
int main(int argc, char** argv) {
	/*As a design consideration minimize stuff in the main function for no particular reason other than readability and modularization */
	int i;

	/*Get the start time of the application to see how long the application has been running.*/
	i = clock_gettime( CLOCK_MONOTONIC,&start_time);
	if(i == -1){
		perror("clock_gettime");
		exit(EXIT_FAILURE);
	}

	i = atexit(bye);
	if (i != 0) {
		perror("Unable to set atexit()");
		printLogFile(fp,"Unable to set atexit()");
		exit(EXIT_FAILURE);
	}

	/*The current pid of the process*/
	processid = getpid(); /*Per the documentation (i.e. "man getpid") this function is always is successful*/
	/*Open the log file to begin logging*/
	fp = fopen(logfile, "a+"); 
	if(fp == NULL){
		perror("Error with fopen(). Unable to open the application log");
		exit(EXIT_FAILURE);
	}

	printApplicationHeaderToConsole();
	printLogFile(fp, "Application started.");

	int rc;
	rc = readConfigurationFile();

	if(rc == EXIT_SUCCESS){
			printLogFile(fp,"Successfully read the configuration file.");
	}

	if(cd.useSignalHandler){
		initializeSignalHandles();
	}


	/*
	* Starting place of the application and application logic. Add code below 
	* and remember to do proper logging and handling of errors by checking 
	* return codes! The main function will return EXIT_SUCCESS or EXIT_FAILURE 
	* depending on if there are any run-time errors in the application. The 
	* application stub goal is to ensure that there are no compile errors thus 
	* only having run-time errors which should be handled correctly and 
	* prevented if that's possible.
	* https://github.com/otikkito/cWorld/blob/master/applicationstub.txt
	* https://github.com/otikkito/cWorld/blob/master/applicationstub.conf
	* https://github.com/otikkito/cWorld/blob/master/Docs/compilenote.txt
	* https://man7.org/linux/man-pages/man1/systemctl.1.html
	* https://github.com/otikkito/cWorld/blob/master/crefresh.c
	* https://github.com/otikkito/cWorld/blob/master/Docs/clanguage.txt
	* https://access.redhat.com/solutions/56021  (core dump KB)
	*/


	sleep(10);

	//printApplicationUptime();



   printLogFile(fp, "Application terminated.");

   return (EXIT_SUCCESS); /*return EXIT_SUCCESS indication successful completion of the application. 
                           exit status can be checked using "echo $?" from the shell*/
}

/********************************************************
*
*
* FUNCTION NAME: printApplicationHeaderToConsole
*
*	
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
* none
*
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
* TODO:
* 1) print also to the log file and console (stdout)
*********************************************************/
int printApplicationHeaderToConsole() {
	//print to the console	
	printf("The process id of this application is: %d\n", processid);
	printf("Welcome to the application stub.\nThe  purpose of this program ");
	printf("is to build a solid framework \nfor the application development ");
	printf("process.\n");
	printf("----------------------------------------------------------------\n");
	printf("The process name of this process is: %s \n", getProcessNameByPid(processid));
	//TODO print to the application log file
	
	return(EXIT_SUCCESS);
}

/********************************************************
*
*
* FUNCTION NAME: readConfigurationFile();
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
* none
*
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*TODO: I need to terminate the configuration line directive with a semicolon
*
*********************************************************/
int readConfigurationFile(){

	FILE *config_file;
	char line[MAXCONFIGLINESIZE];

	config_file = fopen("applicationstub.conf","r");
	//Initialize the global configuration directive variable.
	cd.useSignalHandler = false;

	if(config_file == NULL){
		perror("Unable to open the configuration file.\n");
		printLogFile(fp,"Unable to open the configuration file for the applicationstub.c");
		return EXIT_FAILURE;
	}

	//populate the global configuration structure
	while((fgets(line,MAXCONFIGLINESIZE,config_file)) != NULL){
	/*this needs to be corrected and/or add a special character to the front
	of the configuration file line indicating it is a configuration directive*/
		if((line[0] == '#') || (line[0] == ' ' ) || (line[0] == '\n')) {  
			continue;
		}
		else{
			char leftConfigDirective[MAXCONFIGLINESIZE];
			char rightConfigDirective[MAXCONFIGLINESIZE];
			memset(leftConfigDirective,'\0',MAXCONFIGLINESIZE);
			memset(rightConfigDirective,'\0',MAXCONFIGLINESIZE);
			//TODO I also have to include the semicolon to terminate the line
			sscanf(line,"%s=%s;",leftConfigDirective,rightConfigDirective);
			//printf("The left value is:%s and the right value is %s\n",leftConfigDirective,rightConfigDirective);
			//TODO finish right configuration directive (i.e. true or false, etc)
			if( ((strcmp(leftConfigDirective,"initialize_signal_handler")) == 0) && ((strcmp(rightConfigDirective,"true") == 0)) ){
					cd.useSignalHandler = true;
			}
		}
	}

	//close the file to scale
	int rc;
	rc = fclose(config_file);

	if(rc == 0){
		return EXIT_SUCCESS;
	}
	else{
		perror("Unable to close the configuration file.");
		return EXIT_FAILURE;
	}

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
* TODO print a variable argument list log file
* https://github.com/otikkito/cWorld/blob/master/logger.c
* https://github.com/otikkito/cWorld/blob/master/varguments.c
* ===Remember to flush the buffer with fflush() when logging===
*
*********************************************************/
int printLogFile(FILE *f, char *string) {
	char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring, sizeof (timestring), "%c", localtime(&currenttime));
	fprintf(f, "%s %s \n", timestring, string);
	fflush(f);

	return(EXIT_SUCCESS);
}

/********************************************************
*
*
* FUNCTION NAME: intializeSignalHandles()
*
*
*
* ARGUMENTS: none
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*none
*
*
* RETURNS: EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/
int initializeSignalHandles(){
	/* Link that talks about different types of signals: https://en.wikipedia.org/wiki/Signal_(IPC)#SIGTRAP
	*https://en.wikipedia.org/wiki/Signal_(IPC)*/
	struct sigaction action;
	action.sa_handler = signalHandler;
	action.sa_flags = SA_SIGINFO; /*This is needed in order to get the pid of the offending process*/

	/*
	-To retrieve signal names check out "man 7 signal"
	-Signals that will not be caught please comment out
	-Actions for each signal
	*Term: default actions is to terminate the process
	*Ign: default action is to ignore the signal
	*Core: Default action is to terminate the process and dump core
	*Stop: Default actions is to stop the process
	*Cont: Default action is to continue the process if it is currently stopped
	*/
	/*Per the man page a process can change the disposition of a signal using sigaction(2) or signal(2)
	* signals are define in signal.h*/

	sigaction(SIGHUP, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGILL, &action, NULL);
	sigaction(SIGTRAP, &action, NULL);
	sigaction(SIGABRT, &action, NULL);
	sigaction(SIGBUS, &action, NULL);
	sigaction(SIGFPE, &action, NULL);
	sigaction(SIGKILL, &action, NULL);
	sigaction(SIGUSR1, &action, NULL); //use to dump configuration file and other debug information
	sigaction(SIGSEGV, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);  //use to dump configuration file and other debug information
	sigaction(SIGPIPE, &action, NULL);
	sigaction(SIGALRM, &action, NULL);
	sigaction(SIGTERM,&action, NULL);
	//sigaction(SIGSTKFLT, &action, NULL);  //This gives a compiler error and I need to verify this with Red Hat documentation and get a Red Hat paid subscription for support.
	sigaction(SIGCHLD, &action, NULL);
	sigaction(SIGCONT,&action, NULL);
	sigaction(SIGSTOP, &action, NULL);
	sigaction(SIGTSTP, &action, NULL);
	sigaction(SIGTTIN, &action, NULL);
	sigaction(SIGTTOU, &action, NULL);
	sigaction(SIGURG, &action, NULL);
	sigaction(SIGXCPU, &action, NULL);
	sigaction(SIGXFSZ, &action, NULL);
	sigaction(SIGVTALRM,&action, NULL);
	sigaction(SIGPROF, &action, NULL);
	sigaction(SIGWINCH, &action, NULL);
	sigaction(SIGIO, &action, NULL);
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
	printApplicationUptime();
	/*To terminate kill -s 15 <pid>*/
	/*man 7 signal*/
	/*TODO need to log the calling process name as well*/
	/*TODO find out more about journalctl vs older syslog implementations of logging*/
	/* Using journalctl: https://www.loggly.com/ultimate-guide/using-journalctl/ */
	/* Logging with journald tutorial: https://sematext.com/blog/journald-logging-tutorial/ */
	/*https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf*/
	switch (signal) {
		case SIGINT:
			/*TODO need to find a way to print to the logfile with multiple arguments*/
			fprintf(stdout, "Received SIGINT from process with pid = %u \n", info->si_pid);
			syslog(LOG_ERR, "Received signal SIGINT and will be shutting down applicationstub.c ");
			exit(EXIT_FAILURE);
		case SIGTERM:
			fprintf(stdout, "Received SIGTERM from process with pid = %u \n", info->si_pid);
			syslog(LOG_ERR, "Received signal SIGTERM and will be shutting down applicationstub.c");
			exit(EXIT_FAILURE);
		case SIGUSR1:
			//This is terminating the program but this is not the behavior that we won't. I need to find out what the corrective actions that I need to take.
			printLogFile(fp,"The user has requested to dump debug data");
			printDebugInfo();
			break;
	}

}

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
*pid           pid_t   I   This is the process id of the application.
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
	//ubuntu
	//Need to determine what os version (i.e RHEL 7 or 6) is being used (e.g. "/etc/redhat-release" on ubuntu/openSuse "/etc/os-release" )
	if(pid == 0){
	        return "Kernel"; //This is the abstraction point...better pin pointing.
	}

	if(pid ==1){//on rhel 7 and above
	    return "Systemd";
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

/********************************************************
*
*
* FUNCTION NAME: printApplicationUptime()
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
* The granularity of this function will be in mins and seconds.
*
*********************************************************/
int printApplicationUptime(){

	int mins;
	int secs;
	int i;
	char logentry[MAXLOGENTRYSIZE];

	i = clock_gettime( CLOCK_MONOTONIC,&elapsed_time);
	if(i == -1){
		perror("clock_gettime");
		exit(EXIT_FAILURE);
	}

	mins = (elapsed_time.tv_sec - start_time.tv_sec)/60;
	secs = (elapsed_time.tv_sec - start_time.tv_sec)%60;
	sprintf(logentry,"This application has an uptime of %d mins and %d seconds",mins,secs);
	printLogFile(fp,logentry);
	printf("%s\n",logentry);
	//need to add variadic arguments for the printlogfile.
	//printLogFile(fp,"The application has been up for %d mins"

	return EXIT_SUCCESS;
}

/********************************************************
*
*
* FUNCTION NAME: printDebugInfo
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
int printDebugInfo(){
	printf("The application will now print debug info.\n");
	return EXIT_SUCCESS;
}


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
	printApplicationUptime();
	printLogFile(fp,"The application has ended now.");
	printLogFile(fp,"------------------------------");
	fclose(fp); //flushes the buffer and close the log file.
}

/*
*References:
*1) NASA C coding style: https://github.com/otikkito/cWorld/blob/master/Docs/nasa-c-style.pdf (conformity, readability, maintenance, re-usability,...)
*2) Application Security: https://en.wikipedia.org/wiki/Application_security
*3) C Standard Library Reference Tutorial: https://www.tutorialspoint.com/c_standard_library/index.htm
*4) MIL-STD-498 Military Staandard Software Development and Documentation: https://en.wikipedia.org/wiki/MIL-STD-498
*5) Former professor (Dr. Greg Byrd): https://www.ece.ncsu.edu/people/gbyrd
*6) Application development template: https://github.com/otikkito/cWorld/blob/master/applicationstub.txt
*7) IEEE POSIX Specifications: https://pubs.opengroup.org/onlinepubs/9699919799/
*8) Linux application development training: https://training.linuxfoundation.org/training/developing-applications-for-linux/
*9) Configuration file: https://github.com/otikkito/cWorld/blob/master/applicationstub.conf
*10) Reading code: http://wiki.c2.com/?TipsForReadingCode
*11) On the changing notion of code readability: https://github.com/kbilsted/CodeQualityAndReadability/blob/master/Articles/Readability/TheChangingNotionOfReadability.md
*12) c/c++ IDEs in linux: https://codecondo.com/best-c-c-ides-editors-to-consider-for-linux/
*13) Computer system programming: https://github.com/otikkito/cWorld/blob/master/ECE_209.pdf
*14) The Linux man-pages: https://www.kernel.org/doc/man-pages/
*15) Linux Device Drivers: https://www.linkedin.com/learning-login/share?forceAccount=false&redirect=https%3A%2F%2Fwww.linkedin.com%2Flearning%2Flinux-device-drivers%3Ftrk%3Dshare_ent_url%26shareId%3D%252FlnqNdSOSjyTwihZQY%252FnIw%253D%253D
*16) Cscope: https://cscope.sourceforge.net/
*17) Journalctl: https://www.linkedin.com/learning-login/share?forceAccount=false&redirect=https%3A%2F%2Fwww.linkedin.com%2Flearning%2Fred-hat-certified-system-administrator-ex200-cert-prep-1-deploy-configure-and-manage%3Ftrk%3Dshare_ent_url%26shareId%3DK%252F5ITP0FRXW8tYTX2vjO8Q%253D%253D
18) C programming language standard: https://www.open-std.org/jtc1/sc22/wg14/
19) man signal-safety : Note that sig_atomic_t is not thread-safe, only async-signal safe.
20) https://en.wikipedia.org/wiki/Reentrancy_(computing)
*/
