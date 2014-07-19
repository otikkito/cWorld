#include <stdio.h>
#include <time.h>
#include <syslog.h>



//Will basiclly log a couple of things to the application log 
//and if this code is executing on linux we will log stuff to the syslog

/* Todo need to create a macro of print_log 
 Also could do some measure ments as far as which one is quicker
*/

/*

    -Use the most verbose time granularity possible.
    -Put the timestamp at the beginning of the line. The farther you place a timestamp from the beginning, the more difficult it is to 	    tell it's a timestamp and not other data.
    -Include a four-digit year.
    -Include a time zone, preferably a GMT/UTC offset.
    -Time should be rendered in microseconds in each event. The event could become detached from its original source file at some 	  point, so having the most accurate data about an event is ideal.

*/

int print_log(char *string){

	char timestring[100];
	time_t currenttime = time(0);
	strftime(timestring,sizeof(timestring),"%c",localtime(&currenttime));
	printf("%s: %s\n",timestring,string);

	return 0;	
}

/* More information can be found man 3 syslog */
int print_syslog(char *string){
	syslog(LOG_ERR,"Just playing");
	return 0;
}

int main(){
	
	
	print_log("Error you machine is going down");
	print_syslog("Holy moly you got another error");
	return 0;

}
