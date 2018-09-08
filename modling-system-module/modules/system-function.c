/****************************************************************
*FILE NAME: system-function.c
*
*
*
*PURPOSE: To create a library of functions to retrive operating system 
*status and frequent functions used throughout the develpment of system applications.
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




//This is the system-function implementation
//TODO find out about multiple inclusions of header files
#include <sys/types.h> //pid_t
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include "system-function.h"


const char* getProcessNameByPid(pid_t pid){
	//This function is included in the applicationstub.c, make sure that the are the same implemntation and/or reference the same function
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
int getFreeMemoryOfSystem(){
	//look at /proc/meminfo

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
int getCpuUtilizationOfSystem(){
	//look in /proc/cpuinfo

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
void intializeSignalHsandles(){
	//location of an implementation is located in applicationstub.c

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
int getLoadAverageOfSystem(){
	//This information can be found in /proc/loadavg

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
int getUptimeOfSystem(){
	// look and decipher the two times in /proc/uptime
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
int getUptimeOfApplication(){
   //Need to have the start time of the application stored as a global variable in the applicationstub.
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
int getMemoryUsageOfApplicationGivenName(char *appname){
	// use /proc/meminfo
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
int getMemoryUsageOfApplicationGivenPid(pid_t pid){
	// use /proc/meminfo
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
FILE *run_system_command(const char *system_comand){

	return fp;
}
*/

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
const char* getOperatingSystemVersion(){
	//look at /proc/version
	return "Version";
	
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
pid_t getPidByProcessName(const char* processName){ //processName is one of the naming convention issue
	//This will be rough draft implementation need to find a better way that has direct mapping
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
    //char name[NAME_MAX];
	
	if( dr == NULL){
		printf("Could not open directory"); //also need to print to the application log.
		return (EXIT_FAILURE);
	}
	
	while((de = readdir(dr)) != NULL){
		pid_t pid;
		//printf("dirent name: %s  dirent to int/pid: %d \n",de->d_name,atoi(de->d_name)); 
		pid = atoi(de->d_name);
		if( pid > 0){
			printf("The process id in this directory is %d\n",pid);
			//sprintf(name,"/proc/%d/cmdline
			//check  to see if processName == /proc/pid/cmdline and return pid
			//if(strcmp(processName,
		}
		/*
			Algorithm
			1. if the de->name contains all digits increase count
			  a)get the length of the string
			  b)see if each character is a digit
			2.create an array or linked list conting processid and name
			
			to list all directories in path: ls -l | grep "^d"

		*/
		
		//convert de->d_name to integer if possible
		// check to see if it is an integer or string
		//update list
		
		
	}//while
	

	closedir(dr);
	return  processId; 
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
int getNumberOfProcessorCoresOnSystem(){
	// look at /proc/cpuinfo cpucore and/or processor
	int numCores;
	
	numCores = 1;
	
	return numCores;
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
* ARGUMENTS: const char *fileName
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

