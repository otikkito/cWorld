/*This is the interface to the system-function module*/
//Some concept functions that are accessible to the application stub.
//Try to utilize the /proc filesystem as much as you can: https://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
//man 5 proc
//http://man7.org/linux/man-pages/man5/proc.5.html
/*Include files*/

#include <sys/types.h> //pid_t


/*Function prototype*/
const char* get_process_name_by_pid(pid_t pid);
pid_t get_pid_by_process_name(const char*);
int get_free_memory_of_system();
int get_cpu_utilization_of_system();
void intialize_signal_handles();
int get_load_average_of_the_system();
int get_uptime();//yes use /proc file system
int get_memory_usage_of_application_given_name(char *appname);
int get_memory_usage_of_application_given_pid(pid_t pid);
FILE *run_system_command(const char *system_comand);  //This should be a pointer to a file that contains text output of the system command
const char* get_operating_system_version();
int get_number_of_processor_cores_on_system();
  

  
/*
References: 
http://www.cs.uleth.ca/~holzmann/C/system/shell_commands.html
*/