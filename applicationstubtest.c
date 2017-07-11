#include <stdlib.h>
#include <signal.h>

int main(){
    
    kill(15043,SIGINT);
    
    return EXIT_SUCCESS;
}