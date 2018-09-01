#include <stdio.h>
#include <stdlib.h>


int main(){
	char line[] = "initialize_signal_handler=true";
	char lineL[300];
	char lineR[300];
	
	printf("string: %s\n",line);
	sscanf(line,"%s = %s",lineL,lineR);
	
	printf("lvalue = %s rvalue  = %s \n", lineL, lineR);
	
	return EXIT_SUCCESS;
	
}