#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  for(int i = 0; i < 10; i++)
  {
    void* ptr = malloc(10 * 1024 * 1024);
    memset(ptr, 0, 10 * 1024 * 1024);
    sleep(1);
    free(ptr);
  }
  return 0;
}
