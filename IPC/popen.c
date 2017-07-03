#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 300
/*http://pubs.opengroup.org/onlinepubs/009695399/functions/popen.html*/

int main(){
    
    FILE *fp;
    char line[LINESIZE];
    
    fp = popen("cat /etc/redhat-release","r");
    if(fp == NULL){
        perror("Problem with popen.");
        exit(EXIT_FAILURE);
        /*cat: write error: Broken pipe*/
        /*Possible bug. Further investigation is required
         https://bugzilla.redhat.com/show_bug.cgi?id=1323401
        */
    }
    while(fgets(line,LINESIZE,fp)){
        printf("The line is : %s \n",line);
    }
    
    return 0;
}
