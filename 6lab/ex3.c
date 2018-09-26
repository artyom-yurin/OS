#include<stdio.h>
#include <signal.h>

int isTerminate = 0;

void myHandler()
{
  printf("\nTerminate program\n");
  isTerminate = 1;
}

int main()
{
  signal(SIGINT, myHandler);
  while(!isTerminate)
  {}
  return 0;
}
