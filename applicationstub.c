#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


//Function prototype
void PrintApplicationHeader();
void PrintLogFile();
void SigtermHandler();


int main(){
    
    struct sigaction action = {
    .sa_handler = NULL,
    .sa_sigaction = SigtermHandler,
    .sa_mask = 0,
    .sa_flags = SA_SIGINFO,
    .sa_restorer = NULL
  };
    
    
    sigaction(SIGTERM, &action, NULL);
    
    char logfile[]= "./text-data-files/logfile.txt";
    FILE *fp;
    fp = fopen(logfile,"a+");   //initially caused a segfault because no error checking
    if(fp == NULL){
	perror("Error with fopen");
    }

    
    PrintApplicationHeader();
    PrintLogFile(fp,"This is the first line that is printed to the log file");
    sleep(60);
    return 0;
}



//Function declarations
void PrintApplicationHeader(){
    
    pid_t processid;
    processid = getpid();
    printf("The process id of this application is: %d\n",processid);
    printf("Welcome to the application stub.\nThe  purpose of this program");
    printf("is to build a solid framework \nfor the application development");
    printf("process.\n");
}

int PrintLogFile(FILE *f, char *string){
    char timestring[100];
    time_t currenttime = time(0);
    strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
    fprintf(f,"%s %s \n",timestring,string);	
    return 0;
}

void SigtermHandler(int signal, siginfo_t *info, void *_unused)
{
  fprintf(stderr, "Received SIGTERM from process with pid = %u\n",info->si_pid);
  exit(0);
}
