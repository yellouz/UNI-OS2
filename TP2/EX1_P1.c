#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

const char *MyPipe = "mypipe";
int buffSize = 100;

int main()
{
    printf("Hi I'm Program 1 :) \n");

    char buffer[] = "AAAAAAAAAAAAA";

    int fd = open(MyPipe, O_RDWR | O_NDELAY, 2); // ouverture non bloquante
    write(fd, buffer, buffSize);
    
    printf("This is what i've written in the pipe : %s\n", buffer);
}