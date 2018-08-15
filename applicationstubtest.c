#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
//#include "modling-system-module/modules/system-function.h"

//function declaration
//pid_t get_pid_by_process_name(const char*) //located in : modling-system-module/modules/system-function.h

int main(){
    
    printf("Welcome tot the application-stub Test harness\n"); 
    printf("The process id of the test harness is %u\n",getpid());
    printf("-------------------------------------------------\n");
    
    
   // kill(get_pid_by_process_name("applicationstub"),SIGINT);
    
    printf("Thanks for using the application-stub Test harness.\nWe are now closing down.\n");
    printf("-------------------------------------------------\n");
         
    return EXIT_SUCCESS;
}
