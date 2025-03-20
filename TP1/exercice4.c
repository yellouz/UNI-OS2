#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/times.h>

int main()
{
    __pid_t pid;
    pid = fork();

    switch(pid)
    {
    case -1:
        //fork failed
        exit(1);
    
    case 0:
        //child process will execute this code
        printf("\nHi I'm Child Process (PID = %d), I'll Return to my Parent with the Status: 10 \n", getpid());
        exit(10);

    default:
        //parent process will execute this code
        int status;
        int ChildPID = wait(&status);
        printf("\nHi I'm Parent Process, my Child (PID = %d) Returned with Status: %d \n", ChildPID, WEXITSTATUS(status));
        exit(0);
    }
}