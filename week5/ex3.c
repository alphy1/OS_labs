#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXN 1000

int N = 0;
int full = 0, empty = 0;

void *thread_producer(void *vararg)
{
	while (1)
	{
		if (N == MAXN)
		{
			printf("Producer is full!\n");	
			full = 1;			
			if (full)
				sleep(1);
		}
		N++;
		printf("%d", N);
		if (N == 1)
			empty = 0;
	}
}

void *thread_consumer(void *vararg)
{
	while (1)
	{
		if (N == 0)
		{
			printf("Consumer is empty!\n");
			empty = 1;
			if (empty)
				sleep(1);
		}
		N--;
		//printf("%d", N);
		if (N == MAXN - 1)
			full = 0;
	}
}

int main()
{
	pthread_t prod;
	pthread_t cons;
	
	pthread_create(&prod, NULL, thread_producer, NULL);
	pthread_create(&cons, NULL, thread_consumer, NULL);
	
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);

	return 0;
}
