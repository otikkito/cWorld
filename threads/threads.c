#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* man 7 pthreads */
/* insure that functions are thread safe and proper synchronization */
/*To compile: gcc -g -Wall -pedantic  -pthread threads.c */

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
    printf("The thread should have runned.\n");
    pthread_join(thread1, NULL);
    return EXIT_SUCCESS;

}

void *thread_run(){
    sleep(3);
    printf("In thread run.\n");
    pthread_exit(NULL);
}   
