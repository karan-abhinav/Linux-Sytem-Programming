#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void display_message(int s) {
     printf("Generated SIGALARM\n" );
     

     //signal(SIGALRM, SIG_IGN);
     signal(SIGALRM, SIG_DFL);

     alarm(2);    //for every second
}

int main(void) {
    signal(SIGALRM, display_message);
    alarm(2);

    while (1);

}
