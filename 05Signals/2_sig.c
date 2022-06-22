#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


/* handler for SIGINT and SIGTERM */
static void signal_handler (int signo)
{
    if (signo == SIGINT)
        printf ("Caught SIGINT!\n");
    else if (signo == SIGTERM)
        printf ("Caught SIGTERM!\n");
    exit (EXIT_SUCCESS);
}


int main (void)
{

    printf("\n process ID is(%d)\n",getpid());
    if (signal (SIGINT, SIG_IGN) == SIG_ERR) {
        fprintf (stderr, "Cannot ignore SIGHUP!\n");
        exit (EXIT_FAILURE);
    }


    if (signal (SIGTERM, SIG_IGN) == SIG_ERR) {
        fprintf (stderr, "Cannot handle SIGTERM!\n");
        exit (EXIT_FAILURE);
    }
    while(1);
}
