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



int main(){

struct sigaction action = {
    .sa_handler = NULL,
    .sa_sigaction = SigtermHandler,
    .sa_mask = 0,
    .sa_flags = SA_SIGINFO,
    .sa_restorer = NULL
  };

sigaction(SIGTERM, &action, NULL);

	return EXIT_SUCCESS
}

