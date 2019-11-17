/****************************************************************
*FILE NAME: system-function.h
*
*
*
*PURPOSE: provides  function prototype and variable declarations
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
*ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
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



/*This is the interface to the system-function module
*Some concept functions that are accessible to the application stub.
*Try to utilize the /proc filesystem as much as you can: https://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
*man 5 proc
*http://man7.org/linux/man-pages/man5/proc.5.html
*/

/*Include files*/
#include <stdbool.h>
#include <unistd.h>

/*Preprocessor directives*/

/*#define NAME_MAX 50 Longest file name component which is system-dependent (K&R)*/

/*Function prototype*/
const char* getProcessNameByPid(pid_t pid);/*done*/
pid_t getPidByProcessName(const char*); /*stub*/
int getFreeMemoryOfSystem(); /*stub*/
int getCpuUtilizationOfSystem(); /*stub*/
void intialize_signal_handles(); /*stub*/
int getLoadAverageOfSystem(); /*stub*/
int getUptimeOfSystem();/*/proc file system*/
int getUptimeOfApplication(); /*stub*/
int getMemoryUsageOfApplicationGivenName(char *appname);/*stub*/
int getMemoryUsageOfApplicationGivenPid(pid_t pid);/*stub*/
/*FILE *runSystemCommand(const char *system_command); pointer to a file that contains text output of the system command*/
const char* getOperatingSystemVersion(); /*stub*/
int getNumberOfProcessorCoresOnSystem(); /*stub*/
bool direntIsAProcess(const char *);
bool fileExist(const char *file_name);
  
  
/*
References: 
http://www.cs.uleth.ca/~holzmann/C/system/shell_commands.html
*/
