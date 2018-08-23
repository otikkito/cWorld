#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void signal_handler(int signal, siginfo_t *info, void *_unused);


int main (void)
{
  //handling of the signals  
  struct sigaction action;
  
  action.sa_handler = signal_handler;
  sigaction(SIGINT, &action, NULL);
  
  sleep(6000);

  return 0;
  
  }

  
void signal_handler(int signal, siginfo_t *info, void *_unused){
    
	switch(signal){
        case SIGINT:
            fprintf(stdout, "Received SIGINT from process with pid = %u\n",info->si_pid);
            exit(0);
            break;
    }
  
}