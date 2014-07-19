#include <stdio.h>
#include <time.h>



//Will basiclly log a couple of things to the application log 
//and if this code is executing on linux we will log stuff to the syslog

/* Todo need to create a macro of print_log 
 Also could do some measure ments as far as which one is quicker
*/

int print_log(char *string){

	char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
	printf("%s: %s\n",timestring,string);

	return 0;	
}

int main(){
	
	
	print_log("Error you machine is going down");
	
	return 0;

}
