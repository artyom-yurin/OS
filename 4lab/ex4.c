#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(!system(NULL)) 
	{
		return 1;
	}
	
	char* command = malloc(20 * sizeof(char));
	
	while(1)
	{
		printf("Enter command: ");
		fgets(command, 20, stdin);
		if(strcmp("exit\n",command) == 0)
		{
			return 0;	
		}
		execv(command, argv);
	}
}
