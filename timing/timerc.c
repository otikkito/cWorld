#include <stdio.h>
#include <time.h>

	void wait ( int sec )
	{
		clock_t end_wait;
		end_wait = clock () + sec * CLOCKS_PER_SEC ;

		while (clock() < end_wait) {}
	}

	int main ()
	{
		printf ("Start the Wait!\n");

		wait (5);	/* Wait for 5 seconds */

		printf ("End Wait!\n");
		return 0;
	}
