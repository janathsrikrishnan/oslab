#include <stdio.h>
#include <unistd.h>
//#include <cstdio>

int main()
{
  int p = fork();
  int q = fork();

  if (p == 0 && q == 0)
    {
      printf("Process pid %d parent pid %d\n", getpid(), getppid());
      char* argv[4];
      argv[0] = (char*)"./sum";
      argv[1] = (char*)"4";
      argv[2] = (char*)"5";
      argv[3] = NULL;
      int r = execv("./sum", argv);
      printf("status : %d", r);
    }
  if (p == 0 && q != 0)
    {
      wait(NULL);
      printf("process pid %d parent pid %d\n", getpid(), getppid());
      execl("./listDir.sh", "listDir.sh", NULL);
    }
  if (p != 0 && q != 0)
    {
      wait(NULL);
    }
  if (p != 0 && q == 0)
    {
      printf("process pid %d parent pid %d\n", getpid(), getppid());
    }
  if (p != 0 && q != 0)
    {
      wait(NULL);
      printf("process pid :%d\n", getpid());
    }
}
