#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void quickSort(int* arr, int size)
{
	int i = 0;
	int j = size - 1;
 
	int mid = arr[size / 2];

	do {
		while(arr[i] < mid) {
			i++;
		}
		
		while(arr[j] > mid) {
			j--;
		}

		if (i <= j) {
			swap(&arr[i], &arr[j]);
	 
			i++;
			j--;
		}
	} while (i <= j);

	if(j > 0) {
		quickSort(arr, j + 1);
	}

	if (i < size) {
		quickSort(&arr[i], size - i);
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
	quickSort(arr,size);
	for(int i =0; i < size; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
	free(arr);
	return 0;
}
