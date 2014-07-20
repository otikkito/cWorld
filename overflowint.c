#include <stdio.h>
#include <unistd.h>

int main(){
	int i=0;
	printf("The size of a int is: %ld bytes\n",sizeof(i));
	for(i=0;;i++){
		if((i > 2147483640) || (i<10)){
			printf("i= %d ",i);
			if(i <0 && i != -2147483648){
			  printf("\n");
			  return 0;
			}
	
		}
	}
	return 0;
}
//Conclusion overflow happens and does not give a runtime error. In code I will have to check for overflow.
//TODO Find solutions and best practice for overflow protection

/*
/usr/bin/time -v ./a.out 
The size of a int is: 4 bytes
i= 0 i= 1 i= 2 i= 3 i= 4 i= 5 i= 6 i= 7 i= 8 i= 9 i= 2147483641 i= 2147483642 i= 2147483643 i= 2147483644 i= 2147483645 i= 2147483646 i= 2147483647 i= -2147483648 i= -2147483647 
	Command being timed: "./a.out"
	User time (seconds): 4.10
	System time (seconds): 0.00
	Percent of CPU this job got: 100%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 0:04.10
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 1680
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 130
	Voluntary context switches: 1
	Involuntary context switches: 416
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0

*/
