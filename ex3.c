#include <stdio.h>
#include <unistd.h>

int main()
{
  int id = fork();
  int id2, id3;
  if (id == 0)
    {
      id2 = fork();
      if (id == 0 && id2 != 0)
	{
	  wait(NULL);
	}
    }
  else
    {
      id3 = fork();
    }
  if (id !=0 && id3 != 0 && id2 != 0)
    {
      printf("process pid: %d\n", getpid());

    }
  else
    {
      printf("process pid: %d parent pid :%d\n", getpid(),getppid());
    }
  if (id != 0 && id3 != 0 && id2 != 0)
    {
      wait(NULL);
      wait(NULL);
    }
}
