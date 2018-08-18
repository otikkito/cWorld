//This is the system-function implementation
//TODO find out about multiple inclusions of header files

#include <sys/types.h> //pid_t
#include <stdio.h>
#include <stdlib.h>



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
	

		return 0;
}

int get_cpu_utilization_of_system(){
	

		return 0;
}

void intialize_signal_handles(){
	

}

int get_load_average_of_the_system(){


	return 0;
}

int get_uptime_of_system(){
	
		return 0;
}

int get_uptime_of_application(){

	return 0;
}

int get_memory_usage_of_application_given_name(char *appname){
	
	return 0;
}
	
int get_memory_usage_of_application_given_pid(pid_t pid){
	
	return 0;
}
/*
FILE *run_system_command(const char *system_comand){

	return fp;
}
*/

const char* get_operating_system_version(){
	
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
	
	
	return  processId; 
}

int get_number_of_processor_cores_on_system(){
	// look at /proc/cpuinfo cpucore and/or processor
	int numCores;
	
	numCores = 1;
	
	return numCores;
}