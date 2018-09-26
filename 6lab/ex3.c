#include<stdio.h>
#include <signal.h>

int isTerminate = 0;

void myHandler()
{
  printf("\nhttps://www.youtube.com/watch?v=70O0FsJw5lo\n");
  isTerminate = 1;
}

int main()
{
  signal(SIGINT, myHandler);
  while(!isTerminate)
  {}
  return 0;
}
