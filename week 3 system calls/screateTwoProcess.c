#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
  int id = fork();
  int id2;
  if (id != 0)
    {
     id2 = fork();
    }
  if (id != 0)
    {
      wait();
    }
  if (id == 0 || id2 == 0)
    {
      printf("process pid :%d parent pid :%d\n", getpid(), getppid());
    }
  else
    {
      printf("process pid: %d\n", getpid());
    }
  if (id !=0)
    {
      wait();
    }
}
