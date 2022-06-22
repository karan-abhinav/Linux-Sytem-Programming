/*
Demo to use execv()
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
        printf("\n Main program p1.c\n");
        //A null terminated array of character  pointers 
        char *args[]={"arg1","arg2","arg3",NULL};
        execv("./p2",args); 
      
        printf("\nThis line is not printed\n"); 
      
    return 0; 
} 
