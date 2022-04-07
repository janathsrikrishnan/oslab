#include <stdio.h>
#include <unistd.h>

int main()
{
  int id, id1, id2;
  id = fork();
  id1 = fork();
  id2 = fork();
  if (id != 0 && id1 != 0 && id2 != 0)
    {
      printf("process pid: %d\n", getpid());
      wait(NULL);
      wait(NULL);
      wait(NULL);
    }
  if (id == 0 && id1 != 0 && id2 != 0)
    {
      wait(NULL);
      wait(NULL);
    }
  if (id == 0 && id1 == 0 && id2 != 0)
    {
      wait(NULL);
    }
  if (id != 0 && id1 == 0 && id2 != 0)
    {
      wait(NULL);
    }
  if (!(id != 0 && id1 != 0 && id2 != 0))
    {
      printf("process pid :%d parent pid: %d\n", getpid(), getppid());
    }
}
