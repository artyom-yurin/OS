#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculateRatio(const char* file_name, int numberPageFrame)
{
  FILE* file = fopen (file_name, "r");
  if(file == NULL)
  {
    fprintf(stderr, "Can't open %s\n", file_name);
    exit(EXIT_FAILURE);
  }
  int number = 0;

  int page[numberPageFrame];
  int again[numberPageFrame];

  for(int i = 0; i < numberPageFrame; i++)
  {
    page[i] = 0;
    again[i] = 0;
  }

  int hitRatio = 0;
  int missRatio = 0;

  int printShit = 0;
  while(!feof(file))
  {
     fscanf (file, "%d", &number);
     int miss = 1;
     int findIndex = -1;
     int minValueIndex = -1;
     int minValue = 256;
     int haveFreePlace = 0;

     for(int i = 0; i < numberPageFrame; i++)
     {
       if(page[i] == 0)
       {
         haveFreePlace = 1;
         minValueIndex = i;
       }
       if(number == page[i])
       {
         miss = 0;
         findIndex = i;
       }
       if(!haveFreePlace && again[i] < minValue)
       {
         minValue = again[i];
         minValueIndex = i;
       }
     }

     if(!miss)
     {
       hitRatio = hitRatio + 1;
       for(int i = 0; i < numberPageFrame; i++)
       {
         again[i] = again[i] >> 1;
       }
       again[findIndex] = again[findIndex] | 0x80;
     }
     else
     {
       missRatio = missRatio + 1;
       page[minValueIndex] = number;
       again[minValueIndex] = 0;
       for(int i = 0; i < numberPageFrame; i++)
       {
         again[i] = again[i] >> 1;
       }
       again[minValueIndex] = again[minValueIndex] | 0x80;
     }

  }
  printf("For %d number of pages\n", numberPageFrame);
  printf("Hit Ratio: %d\n", hitRatio);
  printf("Miss Ratio: %d\n", missRatio);
  fclose(file);
}

int main()
{
  calculateRatio("Lab 09 input.txt", 10);
  calculateRatio("Lab 09 input.txt", 50);
  calculateRatio("Lab 09 input.txt", 100);
  return 0;
}
