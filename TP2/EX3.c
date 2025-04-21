#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void SIGUSR1_event(int sig_num)
{
    printf("Le signal, dont le numero: %d, est recu par le fils %d\n", sig_num, getpid());
}

int main()
{
    int pid1, pid2;
    
    pid1 = fork();

    if(pid1 != 0)
        pid2 = fork();
    
    if(pid1 != 0 && pid2 != 0)
    {
        // code executed by parent
        printf("Processus-pere: %d\n", getpid());
        kill(0, SIGUSR1);
        sleep(30);
    }
    else if(pid1 == 0)
    {
        // code executed by child 1
        printf("Le fils: %d, recoit le signal\n", getpid());
        signal(SIGUSR1, SIGUSR1_event);
        pause(); // Fonction de mise en attente de reception d'un signal.
    }
    else if (pid2 == 0)
    {
        // code executed by child 2
        printf("Le fils: %d, recoit le signal\n", getpid());
        signal(SIGUSR1, SIGUSR1_event);
        pause(); // Fonction de mise en attente de reception d'un signal.
    }
}

