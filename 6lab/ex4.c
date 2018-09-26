#include<stdio.h>
#include <signal.h>

int isTerminate = 0;

//can't be caught or ignored
//so it never calls
void killHandler()
{
  printf("\nMy blood on your hands\n");
  exit(0);
}

//can't be caught or ignored
//so it never calls
void stopHandler()
{
  printf("\nYou stop my heart\n");
  exit(0);
}

void userSignalHandler()
{
  printf("\nUser defined signal 1\n");
  exit(0);
}

void myHandler()
{
  printf("\nhttps://www.youtube.com/watch?v=70O0FsJw5lo\n");
  isTerminate = 1;
}

int main()
{
  signal(SIGINT, myHandler);
  signal(SIGKILL, killHandler);
  signal(SIGSTOP, stopHandler);
  signal(SIGUSR1, userSignalHandler);
  while(!isTerminate)
  {}
  return 0;
}
