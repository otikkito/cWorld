/****************************************************************
*FILE NAME:signal-1.c
*https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/signal.pdf
*http://www.csl.mtu.edu/cs4411.choi/www/Resource/signal.pdf
*http://www.thegeekstuff.com/2012/03/catch-signals-sample-c-code
*https://users.cs.cf.ac.uk/Dave.Marshall/C/node24.html
*https://en.wikipedia.org/wiki/C_signal_handling
*
*PURPOSE: To find the best design practice to handle signals
* 
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
*2/22/2017      Kito Joseph					Added a "prolog/File header"
*ALGORITHM (PDL)
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//Function prototype
void SigtermHandler();

int main(){

int sa_return;
struct sigaction action = {
    .sa_handler = NULL,
    .sa_sigaction = SigtermHandler,
    .sa_mask = 0,
    .sa_flags = SA_SIGINFO,
    .sa_restorer = NULL
  };

	sa_return = sigaction(SIGTERM, &action, NULL);
	if(sa_return == -1){
		perror("Error with sigaction");
	}


	for(;;){
		//wait for the cows to come home    
	}
	return EXIT_SUCCESS;
}

void SigtermHandler(int signal, siginfo_t *info, void *_unused)
{
  //To terminate kill -s 15 <pid>
  fprintf(stderr, "Received SIGTERM from process with pid = %u\n",info>si_pid);
  exit(0);
}

