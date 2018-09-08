/****************************************************************
*FILE NAME: regex-tutorial.c
*
*
*
*PURPOSE: Find out some of the usage of the regex and what operating systems and platforms support it natively.
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
*----   	------  	---------   -------     ---------------------
*9/8/2018   Kito Joseph    01                    Created the file format and prolog
*ALGORITHM (PDL)
*/

#include <stdlib.h>
#include <stdio.h>
#include <regex.h>



/*This work is the result of research into the files of several law 
firms dating back to around 1915. Tesla was called to give 
depositions for three days to prepare for patent trials against 
the Marconi Company. Tesla clearly documented priority in 
frequency stablized continous wave signal production and radio 
signal transmission (and reception) on multiplexed circuits as 
early as 1891. All of Marconi's patents pertaining to radio were 
overturned by the U.S. Supreme Court in 1942 or 1943. The key to 
this is that Tesla's work in this area was extremely advanced, 
and most of it has yet to be applied to high powered accelerator 
work. His systems of continous wave RF current production with 
very high potentials is easily adapted to small, high powered, 
linear particle accelerators. The peak powers of his Colorado 
Spings machine (built, tested, and documented in 1899) exceeds 
all but the largest accelerators in existance today. By the way, 
the Tesla system is continous, and the modern systems are pulsed. 
The misunderstanding is damped vs. undamped wave production. The 
machine is capable of both, though the famous photos were taken 
when the machine was set up to produce damped (disruptive) waves. 
I don't think anybody really understood what Tesla was doing, 
certainly he never clearly explained it until I read the work 
above. 
*/

char array[] = "This work is the result of research into the files of several law firms dating back to around 1915.";




int main(){
	
	printf("Welcome to the regex tutorial\n");
	printf("\n%s\n",array);
	
	return EXIT_SUCCESS;
	
}