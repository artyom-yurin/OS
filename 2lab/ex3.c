#include <stdio.h>
#include <limits.h>
#include <float.h>

void pyramid(int n)
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

int main(int argc, char* argv[])
{
	int n = 0;
	if(sscanf(argv[1], "%d", &n) != 1)
	{
		return 1;
	}
	pyramid(n);
	return 0;
} 
