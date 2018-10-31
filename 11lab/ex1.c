#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int f;
  f = open("ex1.txt", O_RDWR);
  struct stat bufstat;

  fstat(f, &bufstat);
  void* out;

  if ((out = (char*)mmap(0, bufstat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0)) == MAP_FAILED)
  {
    fprintf(stderr, "All is bad\n");
    return 1;
  }
  memcpy(out, "This is a nice day", bufstat.st_size);

  close(f);
  return 0;
}
