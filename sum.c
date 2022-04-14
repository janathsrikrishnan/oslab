#include <stdio.h>

int main(int args, char** argv)
{
  //for (int i = 0; i < args; i++) printf("%s\n", argv[i]);
  printf("Inside sum program\n");
  int a = atoi(argv[1]) + atoi(argv[2]);
  printf("sum is %d\n", a);
}
