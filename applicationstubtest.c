#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    
    printf("The process of pid is %u",getpid());
    kill(5432,SIGINT);
    
    return EXIT_SUCCESS;
}