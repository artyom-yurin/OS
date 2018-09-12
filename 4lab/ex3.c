#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	if(!system(NULL)) 
	{
		return 1;
	}
	
	char* command = malloc(20 * sizeof(char));
	
	while(1)
	{
		printf("Enter command: ");
		scanf("%s", command);
		if(strcmp("exit",command) == 0)
		{
			return 0;	
		}
		system(command);
	}
}
