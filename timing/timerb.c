#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*
https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
*/


int main(void){

    time_t start, end;
    int i;

     start=time(NULL);
     for(i=0;i<7899999;i++){
          i++; 
	printf("i= %d\n",i);
     }
     end = time(NULL);
     printf("The loop used %f seconds.\n", difftime(end,start));

    return EXIT_SUCCESS;
}


