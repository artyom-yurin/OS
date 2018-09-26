#include<stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void terminateHandler()
{
  printf("Child was killed by parent\n");
  exit(0);
}

int main()
{
  pid_t p;
  p = fork();
  if (p == 0)
  {
    signal(SIGTERM, terminateHandler);
    while(1)
    {
      printf("I'm alive\n");
      sleep(1);
    }
  }
  else
  {
    sleep(10);
    kill(p, SIGTERM);
  }
  return 0;
}
