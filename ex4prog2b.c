#include <cstdio>
#include <unistd.h>

int main()
{
  char* argv[2];
  argv[0] = (char*)"ex4aux";
  argv[1] = nullptr;

  printf("PID %d running prog2\n", getpid());
  pid_t p = fork();

  if (p == 0)
    {
      int r = execv("./ex4aux", argv);
    }
  else
    {
      printf("PID %d exiting from prog2\n", getpid());
      wait(NULL);
    }
}
