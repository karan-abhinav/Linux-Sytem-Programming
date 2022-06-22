/* Demo program  - Pthread Mutex */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


static int glob = 0; // Global variable/ shared resource
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


static void *threadFunc(void *arg)
{
    int loc, j, ret;

    int loops = 10000;

    ret = pthread_mutex_lock(&mtx);
    if (ret != 0)
        perror("pthread_mutex_lock");

    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }
    ret = pthread_mutex_unlock(&mtx);
    if (ret != 0) 
       perror( "pthread_mutex_unlock");

    return NULL;
}


int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
    s = pthread_create(&t1, NULL, threadFunc, NULL);
    if (s != 0)
        perror("pthread_create");
    s = pthread_create(&t2, NULL, threadFunc, NULL);
    if (s != 0)
        perror("pthread_create");
    s = pthread_join(t1, NULL);
    if (s != 0)
        perror("pthread_join");
    s = pthread_join(t2, NULL);
    if (s != 0)
        perror("pthread_join");
    printf("glob = %d\n", glob);
    exit(0);
}
