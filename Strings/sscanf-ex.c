#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	char *line = "initialize_signal_handler = true";
	char lineL[300];
	char lineR[300];
	int rc;
	
	printf("string: %s\n",line);
	memset(lineR,'\0',300);
	memset(lineL,'\0',300);
	rc = sscanf(line,"%s = %s",lineL,lineR);
	
	printf("The size of the string is %d\n",strlen(line));
	printf("lvalue %s rvalue  %s \n", lineL, lineR);
	printf("The return value is : %d\n",rc);
	return EXIT_SUCCESS;
	
}