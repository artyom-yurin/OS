#include <stdio.h>
#include <pthread.h>

int count;
int buffer[10];

void consumer()
{
	while(count <= 0){}
	count = count - 1;
	printf("Pop: %d\n", buffer[count]);
	sleep(60);
}

void producer(int i)
{
	while(count >= 10){}
	buffer[count] = i % 5;
	count = count + 1;
	
}

int main()
{
	count = 0;
	while(1)
	{
		pthread_t thread[2];				
		pthread_create(&thread[0], NULL, producer, (void*)(count));
		pthread_create(&thread[1], NULL, consumer, NULL);
	}
	return 0;
}
