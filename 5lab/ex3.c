#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int count;
int buffer[10];
pthread_cond_t consumerCond;
pthread_mutex_t count_mutex;
pthread_cond_t producerCond;

void producer();

void consumer()
{
	while(1)
	{
		while(count == 0)
		{
			pthread_cond_wait(&consumerCond, &count_mutex);
		}
		count = count - 1;
		int item = buffer[count];
		if(count == 9)
		{
			pthread_cond_signal(&producerCond);
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
		while(count == 10)
		{
			pthread_cond_wait(&producerCond, &count_mutex);
		}
		buffer[count] = item;
		count = count + 1;
		if(count == 1)
		{
			pthread_cond_signal(&consumerCond);
		}
	}	
}

int main()
{
	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&producerCond, NULL);
	pthread_cond_init(&consumerCond, NULL);

	count = 0; 
	pthread_t thread[2];				
	pthread_create(&thread[0], NULL, producer, NULL);
	pthread_create(&thread[1], NULL, consumer, NULL);
   	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&producerCond);
	pthread_cond_destroy(&consumerCond);
	pthread_exit(NULL);
	return 0;
}
