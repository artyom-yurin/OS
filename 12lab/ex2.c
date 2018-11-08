#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int append = 0;
  if(argc > 1)
  {
    if(strcmp("-a", argv[1]) == 0)
    {
      append = 1;
    }
  }
  char* buffer =  (char*)malloc(52);
  fgets(buffer, 51, stdin);
  printf("%s\n", buffer);
  for(int i = 1 + append; i < argc; i++)
  {
    FILE* fp;
    if(append)
    {
      fp = fopen(argv[i],"a");
    }
    else
    {
      fp = fopen(argv[i], "w");
    }
    if(fp == NULL)
    {
      fprintf(stderr, "File %s doesn't exist\n", argv[i]);
      continue;
    }
    fputs(buffer, fp);
    fclose(fp);
  }
  return 0;
}
