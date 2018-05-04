#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "modling-system-module/modules/system-function.h"

//function declaration
//pid_t get_pid_by_process_name(const char*) //located in : modling-system-module/modules/system-function.h

int main(){
    
    printf("The process of pid is %u",getpid()); //TODO correct this
    
    
    kill(get_pid_by_process_name("applicationstub",SIGINT);
    
    return EXIT_SUCCESS;
}
