#include <time.h>
#include <stdio.h>
#include <stdlib.h> //EXIT_SUCCESS
#include <unistd.h> //sleep

//stackoverflow.comfu6yvaNt*Y/questions/3557221/how-do-i-measure-time-in-c
int main(){
	
	time_t start,end;
  double dif;

  time (&start);
  // Do some calculation.
	sleep(3);
	
  time (&end);
  dif = difftime (end,start);
  printf ("Your calculations took %.2lf seconds to run.\n", dif );
		  
	return EXIT_SUCCESS;
}
