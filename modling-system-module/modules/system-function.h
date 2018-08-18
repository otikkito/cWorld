/*This is the interface to the system-function module*/
//Some concept functions that are accessible to the application stub.
//Try to utilize the /proc filesystem as much as you can: https://www.tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html
//man 5 proc
//http://man7.org/linux/man-pages/man5/proc.5.html
/*Include files*/




/*Function prototype*/
const char* get_process_name_by_pid(pid_t pid);//done
pid_t get_pid_by_process_name(const char*); //stub
int get_free_memory_of_system(); //stub
int get_cpu_utilization_of_system(); //stub
void intialize_signal_handles(); //stub
int get_load_average_of_the_system(); //stub
int get_uptime_of_system();//yes use /proc file system
int get_uptime_of_application(); //stub
int get_memory_usage_of_application_given_name(char *appname);//stub
int get_memory_usage_of_application_given_pid(pid_t pid);//stub
//FILE *run_system_command(const char *system_comand); pointer to a file that contains text output of the system command
const char* get_operating_system_version(); //stub
int get_number_of_processor_cores_on_system(); //stub
  

  
/*
References: 
http://www.cs.uleth.ca/~holzmann/C/system/shell_commands.html
*/