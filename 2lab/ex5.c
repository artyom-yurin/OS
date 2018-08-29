#include <stdio.h>
#include <limits.h>
#include <float.h>

void triangle(int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < (n-i); j++)
		{
			printf(" ");	
		}	
		for(int j = 0; j < (2 * i - 1); j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void rectangleTriangle(int n)
{
	for(int i = 1; i <= n; i++)
	{	
		for(int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void leftTriangle(int n)
{
	int max = (n + 1) / 2;
	for(int i = 1; i <= max; i++)
	{	
		for(int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int i = max - 1; i > 0; i--)
	{	
		for(int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	if(sscanf(argv[1], "%d", &n) != 1)
	{
		return 1;
	}
	int mode;
	do
	{
		printf(" 1 - triangle\n 2 - rectangle triangle\n 3 - left triangle\n 0 - exit\nEnter a mode: ");
		if (scanf("%d", &mode) != 1)
		{
			return 1;
		}
		if (mode == 1)
		{
			triangle(n);
		}
		else if (mode == 2)
		{
			rectangleTriangle(n);
		}
		else if (mode == 3)
		{
			leftTriangle(n);
		}
		else if (mode == 0)
		{
			printf("Bye bye\n");
		}
		else
		{
			printf("Unknown mode\n");
		}
	}
	while (mode != 0);
	return 0;
} 
