/* Demo to show SIGUSR signal between child-parent process*/

#include<stdio.h> 
#include<stdlib.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  

static void signal_handler (int signo)
{
    if (signo == SIGUSR1)
        printf ("Parent: Caught SIGUSR1 in parent!\n");
}

int main() 
{ 
    pid_t cpid; 
    int status = 0;
    int num  = 5;
    cpid = fork();
    if(cpid == -1)
        exit(-1);           /* terminate */

    if(cpid == 0){
        printf("\nChild: Before exec\n");
        execl("./program2","arg1","arg2",NULL);
        printf("\n Child: line is not printed\n");
    } 
    else{   
        if (signal (SIGUSR1, signal_handler) == SIG_ERR) {
            fprintf (stderr, "Cannot handle SIGUSR1!\n");
            exit (-1);
        }
 
        printf("\nParent: Parent executing before wait(), child process created by parent is = (%d)\n",cpid);
        sleep(2);
        kill(cpid,SIGUSR2);
        cpid = wait(&status); /* waiting for child process to exit*/
        printf("\nParent: wait() in parent done\nParent pid = %d\n", getpid()); 
        printf("\nParent: cpid returned is (%d)\n",cpid);
        printf("\nParent: status is (%d)\n",status);
    }
  
    return 0; 
} 
