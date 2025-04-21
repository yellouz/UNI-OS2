#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    signal(SIGCHLD, SIG_IGN);
    int pid = fork();

    if(pid == 0)
    {
        printf("Hi I'm Child Process, here is my ID: %d\n", getpid());
    }
    else
    {
        printf("Hi I'm Parent Process, here is my ID: %d\n", getpid());
        sleep(15);
    }
}

// En verifiant la table des processus avec la commande ps -aux apres avoir execute le programme qui ignore SIGCHLD,
// on remarque que:
// Le processus enfant ne devient pas un processus zombie (état "Z") après sa terminaison. 
// Normalement, lorsqu'un processus enfant se termine et que son parent n'appelle pas wait() pour récupérer son statut,
// l'enfant reste dans un état zombie jusqu'à ce que le parent le récupère.
// Cependant, en ignorant SIGCHLD avec signal(SIGCHLD, SIG_IGN),
// le système d'exploitation libère automatiquement les ressources du processus enfant dès qu'il se termine, 
// sans avoir besoin que le parent appelle wait(). Cela empêche l'accumulation de processus zombies.
// On observe donc seulement le processus parent dans la table des processus (pendant qu'il effectue son sleep()), 
// tandis que le processus enfant disparaît complètement après sa terminaison, sans passer par l'état zombie.