#include <regex.h>
//#include <local.h>
#include <stdio.h>
#include <stdlib.h>

/*
int regcomp(regex_t *restrict, const char *restrict, int);
size_t regerror(int, const regex_t *restrict, char *restrict, size_t);
int regexec(const regex_t *restrict, const char *restrict, size_t,
regmatch_t [restrict], int);
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
*REG_EXTENDED   int?      I   cflag parameter to the functinos that are symobolic constants
*returns:
*/
	if((rc = regcomp(&preg,pattern, REG_EXTENDED)) != 0){
		printf("regcom() failed, returning nonzero (%d)\n",rc);
		exit(1);
	}

	/*	
* ARGUMENT     TYPE      I/O DESCRIPTION
* --------     ----      --- -----------
*preg          regex_t
*string
*nmatch
*pmatch
*returns:
*/
	if((rc = regexec(&preg, string, nmatch,pmatch,0)) != 0){
		printf("failed to ERE match '%s' with '%s', returning %d.\n", string, pattern, rc);
	}
	
	regfree(&preg);
}