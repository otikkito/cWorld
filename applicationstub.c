/****************************************************************
*FILE NAME:
*https://github.com/otikkito/cWorld/blob/master/nasa-c-style.pdf
*PURPOSE
*
*FILE REFERENCES:
*
*NAME		I/O		Description
*----           ---             -----------
*
*EXTERNAL VARIABLE:
*SOURCE: <         >
*
*NAME	  TYPE    	I/O		Description
*----     ----          ---             -----------
*
*EXTERNAL REFERENCES:
*
*Name		Description
*----   	-----------
*
*ABNORMAL ERMINATION CONDITIONS, ERROR AND WARINGING MESSAGES:
*
*ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS
*
*NOTES:
*
*REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*DEVELOPMENT HISTORY:
*
*Date		Author		Change ID	Release		Description of Change
*----   	------  	---------       -------         ---------------------
*2/22/2017      Kito Joseph					Added a prolog 
*ALGORITHM (PDL)
*/


#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


//Function prototype
void PrintApplicationHeader();
void PrintLogFile(FILE *f, char *string);
void SigtermHandler();
const char* get_process_name_by_pid(pid_t pid);

char logfile[]= "./text-data-files/logfile.txt";
FILE *fp;
pid_t processid;


int main(){
    //I need to find a better way to handle signals and find out what important
    //signals that I need to look out for.
    struct sigaction action = {
    .sa_handler = NULL,
    .sa_sigaction = SigtermHandler,
    .sa_mask = 0,
    .sa_flags = SA_SIGINFO,
    .sa_restorer = NULL
  };
    
    
    sigaction(SIGTERM, &action, NULL);
    processid = getpid();
            
    fp = fopen(logfile,"a+");   //initially caused a segfault because no error checking
    if(fp == NULL){
	perror("Error with fopen");
    }

    
    PrintApplicationHeader();
    PrintLogFile(fp,"Application started.");

    /*Starting place of the application. Add code below and remember to do 
    proper logging!
    */

    sleep(300);    
    return 0;

}



//Function declarations
void PrintApplicationHeader(){
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

/*signals that should handle 
kill -l
https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf
http://man7.org/linux/man-pages/man7/signal.7.html
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX	
*/

