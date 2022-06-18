#include <regex.h>
//#include <local.h>
#include <stdio.h>
#include <stdlib.h>

/* Regex tutorial: https://regexone.com/ */
/* Regex in c: https://www.geeksforgeeks.org/regular-expressions-in-c/ */

/* To find out more "man regcomp"
int regcomp(regex_t *restrict, const char *restrict, int);
size_t regerror(int, const regex_t *restrict, char *restrict, size_t);
int regexec(const regex_t *restrict, const char *restrict, size_t, regmatch_t [restrict], int);
void regfree(regex_t *);
*/
int main(){

	regex_t preg;
	char *string = "a simple string";
	char *pattern = ".*(simple).*";
	int rc;
	size_t nmatch = 2;
	regmatch_t pmatch[2];
/*	
* ARGUMENT      TYPE      I/O DESCRIPTION
* --------      ----      --- -----------
*preg           regex_t   O 
*pattern        char *    I
*REG_EXTENDED   int?      I   cflag parameter to the functions that are symobolic constants
*
*returns: int,  the function regcomp shall return 0 upon succesfull completion.
*The regcomp() function shall compile the regular expression contained in the string pointed to by the pattern
*argument and place the results in the structure pointed to by preg. The cflags argument is the bitwiseinclusive
*OR of zero or more of the following flags, which are defined in the <regex.h> header:
*/
	if((rc = regcomp(&preg,pattern, REG_EXTENDED)) != 0){
		printf("regcom() failed, returning nonzero (%d)\n",rc);
		exit(1);
	}
	printf("The return code of regcomp() is : %d\n",rc);
	/*	
* ARGUMENT     TYPE      I/O DESCRIPTION
* --------     ----      --- -----------
*preg          regex_t
*string        char *
*nmatch        size_t
*pmatch        regmatch_t
*returns: int, the function regexec shall return 0 upon succesfull completion.
*/
	if((rc = regexec(&preg, string, nmatch,pmatch,0)) != 0){
		printf("failed to ERE match '%s' with '%s', returning %d.\n", string, pattern, rc);
	}
	printf("The return code of regexec() is : %d\n",rc);
	//printf("the pattern match is 
	regfree(&preg);
}
