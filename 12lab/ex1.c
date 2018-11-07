#include <string.h>
#include <stdio.h>

int main()
{
  FILE* fp = fopen("/dev/urandom", "r");
  for(int i = 0; i < 20; i++)
  {
    char ch;
    fscanf(fp, "%c", &ch);
    printf("%c", ch);
  }
  printf("\n");
  fclose(fp);
  return 0;
}
