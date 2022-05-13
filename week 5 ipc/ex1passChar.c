#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define READ 0
#define WRITE 1
#define BUFFER 25

int main()
{
    int fd[2];
    pipe(fd);
    char mess[BUFFER] = "Hello";

    int id = fork();

    if (id != 0)
    {
        printf("In parent process\n");
        close(fd[0]);
        write(fd[1], mess, strlen(mess)+1);
        close(fd[1]);
        wait();
    }
    else
    {
        printf("In child process\n");
        close(fd[WRITE]);
        char read_mess[BUFFER];
        read(fd[0], read_mess, BUFFER);
        close(fd[READ]);
        printf("%s\n", read_mess);
    }
    
}