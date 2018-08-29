#include <stdio.h>
#include <limits.h>
#include <float.h>

void swap(int* f, int* s)
{
	int temp = *f;
	*f = *s;
	*s = temp;
}

int main(int argc, char* argv[])
{
	int f = 0;
	int s = 0;
	scanf("%d", &f);
	scanf("%d", &s);
	printf("%d %d\n", f, s);
	swap(&f, &s);	
	printf("%d %d\n", f, s);
	return 0;
} 
