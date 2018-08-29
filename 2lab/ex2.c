#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* T = (char*)malloc(sizeof(char) * 50);
	fgets(T, 50, stdin);
	for(int i = strlen(T) - 2; i >= 0; i--)
	{
		printf("%c", *(T + i));
	}
	printf("\n");
	free(T);
	return 0;
}
