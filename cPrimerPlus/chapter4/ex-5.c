#include <stdio.h>

int main(){

	float mbps;
	float mb;
	
	printf("Please enter the download speed in megabits per second and the size of the file in megabytes ");
	scanf("%f %f",&mbps,&mb);
	printf("At %.2f megabits per second, a file of %.2f megabytes\n downloads in %.2f seconds.",mbps,mb,(mbps/(mb*8)));
}
