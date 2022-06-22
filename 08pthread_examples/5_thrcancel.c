#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 100

static void *threadFunc(void *arg)
{
    char *s = (char *) arg;
    int count = 0;
    printf("Thread: threadFunc started\n");

    while(1){
        sleep(1);
        printf("\nthreadFunc: executing loop\n");
    }

    sleep(5);
    printf("\nThread: threadFunc exiting now\n");
}

int main(int argc, char *argv[])
{
    pthread_t t1_id;
    void *res;
    int s, count;

    printf("\nMain thread started:\n");
    s = pthread_create(&t1_id, NULL, threadFunc, NULL);
    if (s != 0)
        perror("pthread_create error");

    for(count = 0 ; count < 10 ; count ++){
        sleep(2);
        printf("\n    Main thread: count value = (%d)\n",count);
    }
    pthread_cancel(t1_id);

    printf("Main Thread exiting now\n");
    pthread_exit(NULL);
}



