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

    pthread_detach(pthread_self());
    for(count = 0 ; count < MAX ; count ++);

    sleep(5);
    printf("\nThread: threadFunc exiting now\n");
}

int main(int argc, char *argv[])
{
    pthread_t t1_id;
    void *res;
    int s;

    s = pthread_create(&t1_id, NULL, threadFunc, NULL);
    if (s != 0)
        perror("pthread_create error");


    printf("Main Thread exiting now\n");
    pthread_exit(NULL);
}



