#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

const char *MyPipe = "mypipe";
int buffSize = 100;

int main()
{
    printf("Hi I'm Program 2, I'll wait until Program 1 writes something in the pipe then I'll read it :) \n");
    
    char buffer[buffSize];

    int fd = open(MyPipe, O_RDWR); // ouverture bloquante
    read(fd, buffer, buffSize);

    printf("This is what i've read from the buffer : %s\n", buffer);
    close (fd);
}