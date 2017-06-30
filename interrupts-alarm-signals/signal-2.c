#include <signal.h>
#include <errno.h>
#include <stdlib.h>

static void handler(int signum)
{
    /* Take appropriate actions for signal delivery */
	printf("We recieved signal : %d\n",signum);
}


int main()
{
    struct sigaction sa;


    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART; /* Restart functions if
                                 interrupted by handler */
    if (sigaction(SIGINT, &sa, NULL) == -1){
		perror("Problem with the sigaction");
    }


    /* Further code */
	for(;;){
	//wait for the cows to come home	
	}

	return EXIT_SUCCESS;
}
