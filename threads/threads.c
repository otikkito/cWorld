#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* man 7 pthreads */
/* insure that functions are thread say and proper synchronization */

/*Function prototype*/
void *thread_run();

int main(){
        
    int i;
    pthread_t thread1;
    
    printf("Welcome to pthread tutorial\n");
    
    i = pthread_create(&thread1,NULL,thread_run,NULL); 
    if(i !=0){
        perror("There was a problem with pthread_create");
    }
	
    return 0;

}

void *thread_run(){
    sleep(3);
    pthread_exit(NULL);
}   