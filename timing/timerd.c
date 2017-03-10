/*
 * This program prints out the clock resolution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //sleep()

int main( void )
  {
    struct timespec res;

    if ( clock_getres( CLOCK_REALTIME, &res) == -1 ) {
      perror( "clock get resolution" );
      return EXIT_FAILURE;
    }
	sleep(1);
    printf( "Resolution is %d seconds %ld micro seconds.\n",res.tv_sec,
          res.tv_nsec / 1000 );
    return EXIT_SUCCESS;
  }
