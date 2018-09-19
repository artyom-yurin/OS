#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count;
int buffer[10];
int wakeConsumer;
int wakeProducer;

void producer();

void consumer()
{
	while(1)
	{
		if(count == 0)
		{
			wakeConsumer = 0;
			while(!wakeConsumer)
			{
			}	
		}
		count = count - 1;
		int item = buffer[count];
		if(count == 9)
		{
			wakeProducer = 1;
		}
		printf("Item is %d\n", item);
		sleep(60);
	}
}

void producer()
{
	while(1)
	{
		int item = 1;
		if(count == 10)
		{
			wakeProducer = 0;
			while(!wakeProducer)
			{
			}
		}
		buffer[count] = item;
		count = count + 1;
		if(count == 1)
		{
			wakeConsumer = 1;
		}
	}	
}

int main()
{
	count = 0;
	wakeProducer = 1;
	wakeConsumer = 1;
	pthread_t thread[2];				
	pthread_create(&thread[0], NULL, producer, NULL);
	pthread_create(&thread[1], NULL, consumer, NULL);
	pthread_exit(NULL);
	return 0;
}
