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
    for(count = 0 ; count < MAX ; count ++);

    sleep(5);
    printf("\nThread: threadFunc exiting now\n");
    if ( count < 500){
       return (void *) " count < 500";
    }else {
       return (void *) "count > 500";
    }
}

int main(int argc, char *argv[])
{
    pthread_t t1_id;
    void *res;
    int s;

    s = pthread_create(&t1_id, NULL, threadFunc, NULL);
    if (s != 0)
        perror("pthread_create error");


#if 1
    s = pthread_join(t1_id, &res);
    if (s != 0)
        perror("pthread_join error");
    printf("main thread: Thread returned %s\n",(char *) res);
#endif

    printf("Main Thread exiting now\n");
    pthread_exit(NULL);
}



