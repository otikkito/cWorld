#include <time.h>
#include <stdio.h>

//Apllication to timing anyalysis

void delay(unsigned int d);


int main(){
	/*
	int msec;
	clock_t start,diff;
	
	start=clock();
	delay(100000000);
	diff = clock() -start;
	msec = diff *1000 / CLOCKS_PER_SEC; 
	printf("seconds: %d miliseconds: %d \n",msec/1000,msec%1000);
	*/
	clock_t start,end;
	printf("CLOCKS_PER_SEC: %ld\n",CLOCKS_PER_SEC);
	start = clock();
	printf("start: %d\n",start);
	return 0;
}


void delay(unsigned int d){

	while(d > 0){
	 	d--;
	}
}
