#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

/*http://www.alexonlinux.com/signal-handling-in-linux*/
void signal_handler(int signum){
    printf("Received signal %d\n",signum)
}

int main(){
    
    signal(SIGINT, sig_handler);
    sleep(10); // This is your chance to press CTRL-C

    return 0;
}