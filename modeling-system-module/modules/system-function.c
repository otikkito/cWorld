/****************************************************************
*FILE NAME: system-function.c
*
*
*
*PURPOSE: To create a library of functions to retrieve operating system 
*status and frequent functions used throughout the development of system applications.
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
*Date		Author		  Change ID	      Release		Description of Change
*----   	------  	  ---------       -------       ---------------------
*9-7-2018   Kito Joseph       1                         Included the function stubs and file format and function prolog   
*ALGORITHM (PDL)
*/


//https://superuser.com/questions/716001/how-can-i-get-files-with-numeric-names-using-ls-command

/*This is the system-function implementation*/
/*TODO find out about multiple inclusions of header files*/
#include <sys/types.h> /* pid_t */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "system-function.h"


/********************************************************
*
*
* FUNCTION NAME: getProcessNameByPid
*
*
*
* ARGUMENTS: pid
*
*
*
* ARGUMENT     TYPE    I/O DESCRIPTION
* --------     ----    --- -----------
* pid          pid_t   I   This is the process id of the process that I am inquiring about.
*
*
* RETURNS: returns the process name given the process id.
*
*citation: from stack overflow but will have to do proper citing later.
*
*********************************************************/
const char* getProcessNameByPid(pid_t pid){
	/*This function is included in the applicationstub.c, make sure that the are the same implementation and/or reference the same function*/
	FILE *f;
	char* name = (char*) calloc(1024, sizeof (char));
    	/*Need to determine if RHEL 7 or 6 is being used. /etc/redhat-release*/
    	if(pid == 0){
        	return "Kernel"; /*This is the abstraction point. It abstracts systemd which should be included as well for better pin pointing.*/
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
* FUNCTION NAME: getFreeMemoryOfSystem
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
* RETURNS: returns an integer value of the number of bytes/kilobytes/megabytes/... of the system.
*
*
*
*********************************************************/
int getFreeMemoryOfSystem(){
	/*look at /proc/meminfo */

		return 0;
}

/********************************************************
*
*
* FUNCTION NAME: getCpuUtilizationOfSystem
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
* RETURNS: returns the percentage of cpu utilization most would be 100%
*
*
*
*********************************************************/
int getCpuUtilizationOfSystem(){
	/* look in /proc/cpuinfo */

		return 0;
}

/********************************************************
*
*
* FUNCTION NAME: intializeSignalHsandles
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
* RETURNS: returns EXIT_SUCCESS or EXIT_FAILURE
*
*
*
*********************************************************/
void intializeSignalHsandles(){
	/*location of an implementation is located in applicationstub.c */

}

/********************************************************
*
*
* FUNCTION NAME: getLoadAverageOfSystem
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
* RETURNS: returns the load average of the system in the format of "one five fifteen" minutes
*
*
*
*********************************************************/
int getLoadAverageOfSystem(){
	/*This information can be found in /proc/loadavg*/

	return 0;
}

/********************************************************
*
*
* FUNCTION NAME: getUptimeOfSystem
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
* RETURNS: the length of time system has been up since reboot and the time since it has been idle in seconds
*
*
*
*********************************************************/
int getUptimeOfSystem(){
	/* look and decipher the two times in /proc/uptime */
		return 0;
}

/********************************************************
*
*
* FUNCTION NAME: getUptimeOfApplication()
*
*
*
* ARGUMENTS: In design. start and stop time/time of function invocation 
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*TBD
*
*
* RETURNS: returns the seconds that the application has been running.
*
*
*
*********************************************************/
int getUptimeOfApplication(){
   /*Need to have the start time of the application stored as a global variable in the applicationstub.c */
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME: getMemoryUsageOfApplicationGivenName
*
*
*
* ARGUMENTS: app_name
*
*
*
* ARGUMENT     TYPE   I/O DESCRIPTION
* --------     ----   --- -----------
*app_name      char * I   This is the name of the application or maybe should be the pid 
*
*
* RETURNS: returns an integer value of the number of bytes/kilobytes/megabytes/... of the application in question.
*
*
*
*********************************************************/
int getMemoryUsageOfApplicationGivenName(char *app_name){
	/* use /proc/meminfo */
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME: getMemoryUsageOfApplicationGivenPid
*
*
*
* ARGUMENTS: pid
*
*
*
* ARGUMENT     TYPE   I/O DESCRIPTION
* --------     ----   --- -----------
* pid          pid_t  I   The pid of the process
*
*
* RETURNS: returns an integer value of the number of bytes/kilobytes/megabytes/... of the application in question.
*
*
*
*********************************************************/	
int getMemoryUsageOfApplicationGivenPid(pid_t pid){
	/* use /proc/meminfo */
	return 0;
}

/********************************************************
*
*
* FUNCTION NAME: run_system_command
*
*
*
* ARGUMENTS: In design
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS: In design
*
*
*
*********************************************************/
/*
FILE *run_system_command(const char *system_comand){

	return fp;
}
*/

/********************************************************
*
*
* FUNCTION NAME: getOperatingSystemVersion
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
* RETURNS: In design
*
*
*
*********************************************************/
const char* getOperatingSystemVersion(){
	/* look at /proc/version */
	return "Version";
	
}

/********************************************************
*
*
* FUNCTION NAME: getPidByProcessName
*
*
*
* ARGUMENTS: In design
*
*
*
* ARGUMENT     TYPE I/O DESCRIPTION
* --------     ---- --- -----------
*
*
*
* RETURNS: in design
*
*
*
*********************************************************/
pid_t getPidByProcessName(const char* processName){ /* processName is one of the naming convention issue */
	/*This will be rough draft implementation need to find a better way that has direct mapping */
	/*
	Algorithm
	1) Goto the /proc directory
	2) create an array of pid given in the proc directory that are process ids
	3)search the /proc/pid/cmdline for string containing the prodcess name
	4) return the integer portion that is mapped to the process name
	*/
	pid_t processId;
	processId = 0;
	struct dirent *de;
	DIR *dr = opendir("/proc");
        /*char name[NAME_MAX]; */
	
	if( dr == NULL){
		printf("Could not open directory"); /*also need to print to the application log.*/
		return (EXIT_FAILURE);
	}
	
	while((de = readdir(dr)) != NULL){
		pid_t pid;
		/* printf("dirent name: %s  dirent to int/pid: %d \n",de->d_name,atoi(de->d_name)); */
		pid = atoi(de->d_name);
		if( pid > 0){
			printf("The process id in this directory is %d\n",pid);
			/* sprintf(name,"/proc/%d/cmdline */
			/* check  to see if processName == /proc/pid/cmdline and return pid */
			/* if(strcmp(processName, */
		}
		/*
			Algorithm
			1. if the de->name contains all digits increase count
			  a)get the length of the string
			  b)see if each character is a digit
			2.create an array or linked list conting processid and name
			
			to list all directories in path that begin with digit (possible proceses): ls | grep "^[[:digit:]]"
			to list a file that contains all digits in file name: ls | grep -E '^[0-9]+$'
		*/
		/*
		1. convert de->d_name to integer if possible
		2. check to see if it is an integer or string
		3. update list
		*/
		
	} /* while */
	

	closedir(dr);
	return  processId; 
}

/********************************************************
*
*
* FUNCTION NAME: getNumberOfProcessorCoresOnSystem
* 
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
* RETURNS: the number of cores on the given processor
*
*
*
*********************************************************/
int getNumberOfProcessorCoresOnSystem(){
	/* look at /proc/cpuinfo cpucore and/or processor */
	int numCores;
	
	numCores = 1;
	
	return numCores;
}

/********************************************************
*
*
* FUNCTION NAME: direntIsAProcess
*
*
*
* ARGUMENTS: pname
*
*
*
* ARGUMENT     TYPE          I/O DESCRIPTION
* --------     ----          --- -----------
*process_name  const char *  I   This would be the name of the process from the proc filesystem that we are trying to get in order to see if it has a pid.
*
*
* RETURNS: return true if it is a process under the /proc file system
*
*
*
*********************************************************/
bool direntIsAProcess(const char *pname ){
	
	
	return true;
}

/********************************************************
*
*
* FUNCTION NAME: fileExist
*
*
*
* ARGUMENTS: file_name
*
*
*
* ARGUMENT     TYPE           I/O DESCRIPTION
* --------     ----           --- -----------
*file_name     cconst char *  I   This is the complete path of the file that is being checked.
*
*
* RETURNS: returns true (1) if the file exist and false otherwise
*
*
*
*********************************************************/
bool fileExist(const char * file_name){
	
	FILE *fp;
	
	fp = fopen(file_name,"r");
	if(fp == NULL){
		return false; 
	}
	return true;
}

