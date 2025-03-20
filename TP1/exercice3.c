#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/times.h>

// PS: Run The Following Command on Another Terminal Window to Check if the Process had Became a Zombie
// ps -aux | grep defunct

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
        printf("\nHi I'm Child Process, I Just Finished my Work, Now I'll Return to my Parent :-) \n");
        exit(0);

    default:
        //parent process will execute this code
        printf("\nHi I'm Parent Process, I'll Sleep for 30 Seconds :-) \n");
        sleep(30);
        exit(0);
    }
}