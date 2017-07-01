#include <stdio.h>
/*http://pubs.opengroup.org/onlinepubs/009695399/functions/popen.html*/

int main(){
    
    FILE *fp;
    
    fp = popen("cat /etc/redhat-release","r");
    if(fp == NULL){
        perror("Problem with popen.");
        exit(EXIT_FAILURE);
        /*cat: write error: Broken pipe*/
    }
    
    return 0;
}
