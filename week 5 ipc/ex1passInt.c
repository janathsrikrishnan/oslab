#include <stdio.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define BUFFER 25

int main()
{
    int fd[2];
    pipe(fd);

    int send_num[2];
    send_num[0] = 5;
    send_num[1] = 2;

    int id = fork();

    if (id != 0)
    {
        printf("Inside the parent process\n");
        close(fd[READ]);
        write(fd[WRITE], &send_num, sizeof(send_num));
        close(fd[WRITE]);
        wait();
    }
    else
    {
        printf("Inside the child process\n");
        close(fd[WRITE]);
        int receiver[2];
        read(fd[READ], &receiver, sizeof(int)*2);
        printf("a = %d\n", receiver[0]);
        printf("b = %d\n", receiver[1]);
        printf("sum = %d\n", receiver[0] + receiver[1]);
    }
    return 0;
}