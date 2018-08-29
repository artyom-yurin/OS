#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Size int: %lu Int max: %d\n",sizeof(int), a);
	printf("Size float: %lu Float max: %f\n",sizeof(float), b);
	printf("Size double: %lu Double max: %f\n",sizeof(double), c);
	return 0;
} 
