#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void PrintNumbers(int from, int to)
{
    for (int i = from; i <= to; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

void ChildProcessPrintsNumbers(__pid_t ForkResult, int ProcessNumber, int from, int to)
{
    switch (ForkResult)
    {
    case -1:
        //fork failed
        exit(1);
    
    case 0:
        //child process will execute this code
        printf("\nChild Process Number %d: (PID = %d, PPID = %d)\n", ProcessNumber, getpid(), getppid());
        PrintNumbers(from, to);
        exit(0);

    default:
        //parent process will execute this code
        wait(0);
        break;
    }
}

int main()
{
    __pid_t pid;
    int ProcessNumber = 0;

    pid = fork();
    ProcessNumber = 1;
    ChildProcessPrintsNumbers(pid, ProcessNumber, 1, 50);

    pid = fork();
    ProcessNumber = 2;
    ChildProcessPrintsNumbers(pid, ProcessNumber, 51, 100);
}