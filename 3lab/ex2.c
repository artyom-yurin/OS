#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bubbleSort(int* arr, int size)
{
	int sorted = 0;
	while(!sorted)
	{
		sorted = 1;
		for(int i = 0; i < size - 1; i++)
		{
			if (*(arr + i) > *(arr + i + 1))
			{
				swap((arr + i), (arr + i + 1));
				sorted = 0;
			}
		}
	}
}

int main()
{
	int size = 10;
	int* arr = malloc(sizeof(int) * size);
	for(int i =0; i < size; i++)
	{
		*(arr + i) = size - i;
		printf("%d ", *(arr + i));
	}
	printf("\n");
	bubbleSort(arr,size);
	for(int i =0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
	free(arr);
	return 0;
}
