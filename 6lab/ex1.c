#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  char* string = "Hallo";
  char buffer[1024];
  int fds[2];
  pipe(fds);
  printf("Buffer: \"%s\"\n", buffer);
  write(fds[1], string, strlen(string) + 1);
  close(fds[1]);
  read(fds[0], buffer, strlen(string) + 1);
  close(fds[0]);
  printf("Buffer: \"%s\"\n", buffer);
  return 0;
}
