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
const char* get_process_name_by_pid(pid_t pid);


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
    PrintLogFile(fp,"Application started.");
    
    /*Starting place of the application. Add code below and remember to do 
    proper logging
    */
    
    return 0;
}



//Function declarations
void PrintApplicationHeader(){
    
    pid_t processid;
    processid = getpid();
    printf("The process id of this application is: %d\n",processid);
    printf("Welcome to the application stub.\nThe  purpose of this program");
    printf("is to build a solid framework \nfor the application development ");
    printf("process.\n");
    printf("----------------------------------------------------------------\n");
    printf("The process name of this process is: %s \n",get_process_name_by_pid(processid));
}

void PrintLogFile(FILE *f, char *string){
    char timestring[100];
    time_t currenttime = time(0);
    strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
    fprintf(f,"%s %s \n",timestring,string);	
}

void SigtermHandler(int signal, siginfo_t *info, void *_unused)
{
  //To terminate kill -s 15 <pid>
  fprintf(stderr, "Received SIGTERM from process with pid = %u\n",info->si_pid);
  exit(0);
}


const char* get_process_name_by_pid(pid_t pid)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name){
        sprintf(name, "/proc/%d/cmdline",pid);
        FILE* f = fopen(name,"r");
        if(f){
            size_t size;
            size = fread(name, sizeof(char), 1024, f);
            if(size>0){
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(f);
        }
    }
    return name;
}



