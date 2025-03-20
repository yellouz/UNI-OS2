#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/times.h>

void PrintProcessInfos(char *WhatProcess)
{
    printf("\nHello I'm %s Process!\n", WhatProcess);
    printf("UID = %d \n", getuid());
    printf("EUID = %d \n", geteuid());
    printf("EGID = %d \n", getegid());

    char Directory[1000];
    unsigned long taille = 1000;
    getcwd(Directory, taille);
    printf("Directory = %s \n", Directory);
    printf("Taille = %ld \n", taille);

    int priority = -10;
    nice(priority);
    printf("Priority = %d \n", priority);

    struct tms buffer;
    times(&buffer);
    printf("Temps Utilisateur = %ld \n", buffer.tms_utime);
    printf("Temps Systeme = %ld \n", buffer.tms_stime);
    printf("Temps Utilisateur des Fils = %ld \n", buffer.tms_cutime);
    printf("Temps Systeme des Fils = %ld \n", buffer.tms_cstime);
}

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
        PrintProcessInfos("Child");
        exit(0);

    default:
        //parent process will execute this code
        wait(0);
        PrintProcessInfos("Parent");
        exit(0);
    }
}