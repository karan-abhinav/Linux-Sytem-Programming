/* incorrect method of accessing global variable*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int glob = 0;

static void *threadFunc1(void *arg)
{
    int loc, j;
    int loop = 10000;
    for (j = 0; j < loop; j++) {
        loc = glob;
        loc++;
        glob = loc;
        }
    return NULL;
}

static void *threadFunc2(void *arg)
{
    int loop = 10000;
    int loc, j;
    for (j = 0; j < loop; j++) {
        loc = glob;
        loc++;
        glob = loc;
        }
    return NULL;
}


int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
    s = pthread_create(&t1, NULL, threadFunc1, NULL);
    if (s != 0)
        perror("pthread_create");
    s = pthread_create(&t2, NULL, threadFunc2, NULL);
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
