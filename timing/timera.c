#include <time.h> //https://github.com/otikkito/cWorld/blob/master/Docs/cManPages/time.pdf
#include <stdio.h>
#include <unistd.h>

//Apllication to do timing anyalysis
//https://www.tutorialspoint.com/c_standard_library/time_h.htm
//http://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
//https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html

void delay(unsigned int d);


int main(){

	int msec;
	clock_t start,diff;
	
	start=clock();
	delay(3);
	diff = clock() -start;
	msec = diff *1000 / CLOCKS_PER_SEC; 
	printf("seconds: %d miliseconds: %d \n",msec/1000,msec%1000);
	
	/*clock_t start,end;
	double cpu_time_used;
	printf("CLOCKS_PER_SEC: %ld\n",CLOCKS_PER_SEC);
	start = clock();
	printf("start: %d\n",start);
	delay(3);
	end = clock();
	printf("end: %d\n",end);
	cpu_time_used = (((double) (end-start))/ CLOCKS_PER_SEC);

	printf("The time elapsed was : %e\n",cpu_time_used);
	*/
	return 0;
}


void delay(unsigned int d){

	sleep(d);
}
