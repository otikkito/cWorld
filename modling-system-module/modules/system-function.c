//This is the system-function implementation
//TODO find out about multiple inclusions of header files

#include <sys/types.h> //pid_t
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

//function protype
bool dirent_is_a_process(const char *);
bool file_exist(const char *);


const char* get_process_name_by_pid(pid_t pid){
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

int get_free_memory_of_system(){
	//look at /proc/meminfo

		return 0;
}

int get_cpu_utilization_of_system(){
	//look in /proc/cpuinfo

		return 0;
}

void intialize_signal_handles(){
	//location of an implementation is located in applicationstub.c

}

int get_load_average_of_the_system(){
	//This information can be found in /proc/loadavg

	return 0;
}

int get_uptime_of_system(){
	// look and decipher the two times in /proc/uptime
		return 0;
}

int get_uptime_of_application(){
   //Need to have the start time of the application stored as a global variable in the applicationstub.
	return 0;
}

int get_memory_usage_of_application_given_name(char *appname){
	// use /proc/meminfo
	return 0;
}
	
int get_memory_usage_of_application_given_pid(pid_t pid){
	// use /proc/meminfo
	return 0;
}
/*
FILE *run_system_command(const char *system_comand){

	return fp;
}
*/

const char* get_operating_system_version(){
	//look at /proc/version
	return "Version";
	
}

pid_t get_pid_by_process_name(const char* processName){ //processName is one of the naming convention issue
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
			  a)git the length of the string
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

int get_number_of_processor_cores_on_system(){
	// look at /proc/cpuinfo cpucore and/or processor
	int numCores;
	
	numCores = 1;
	
	return numCores;
}

/*bool dirent_is_a_process(const char *pname ){
	FILE *file;
	
	char* name = (char*) calloc(1024, sizeof (char));
	sprintf(name,
	if(file = fopen("
	
	
	return true;
}

bool file_exist(const char * fn){
	FILE *file;
	
	if((file = fopen(fname,"r")){
		fclose(file);
		return true
	}
	return false;
	
}

*/