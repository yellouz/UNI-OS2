#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/times.h>

int GlobalVariable = 1000;

int main()
{
    int LocalVariable = 1000;

    __pid_t pid;
    pid = fork();

    switch(pid)
    {
    case -1:
        //fork failed
        exit(1);
    
    case 0:
        //child process will execute this code
        printf("\nHi I'm Child Process!\n");
        printf("Before Changing Values: LocalVariable = %d, GlobalVariable = %d \n", LocalVariable, GlobalVariable);
        LocalVariable = 100;
        GlobalVariable = 100;
        printf("After Changing Values: LocalVariable = %d, GlobalVariable = %d \n", LocalVariable, GlobalVariable);
        exit(0);

    default:
        //parent process will execute this code
        wait(0);
        printf("\nHi I'm Parent Process!\n");
        printf("Before Changing Values: LocalVariable = %d, GlobalVariable = %d \n", LocalVariable, GlobalVariable);
        LocalVariable = 200;
        GlobalVariable = 200;
        printf("After Changing Values: LocalVariable = %d, GlobalVariable = %d \n", LocalVariable, GlobalVariable);
        exit(0);
    }
}