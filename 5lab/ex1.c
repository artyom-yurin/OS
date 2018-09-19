#include <stdio.h>
#include <pthread.h>

void func(int number)
{
	printf("I'm %d\n", number);
}

int main()
{
	pthread_t threads[10];
	for(int i = 0; i < 10; i++)
	{
		pthread_create(&threads[i], NULL,func, (void*)i);
	}
	for(int i = 0; i < 10; i++)
	{
		pthread_join(threads[i], NULL);
	}

	printf("_________________\n");	

	for(int i = 0; i < 10; i++)
	{
		pthread_create(&threads[i], NULL,func, (void*)i);
		pthread_join(threads[i], NULL);
	}
	return 0;
}
