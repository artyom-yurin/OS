#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N = 0;
  printf("Enter count of elements: ");
  if(!scanf("%d", &N))
  {
    printf("Can't read\n");
    return 1;
  }
  if(N < 1)
  {
    printf("Count can't be 0 or negative\n");
    return 1;
  }
  int* arr = (int*)malloc(N * sizeof(int));
  for(int i = 0; i < N; i++)
  {
    arr[i] = i;
    printf("%d ", arr[i]);
  }
  printf("\n");
  free(arr);
  return 0;
}
