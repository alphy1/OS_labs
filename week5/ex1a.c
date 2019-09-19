#include <stdio.h> 
#include <stdlib.h> 
#include <pthread.h> 
  
void *threadFunct(void *arg) 
{ 
	printf("Printing Thread ID %d \n", (*(int *)arg)); 
	return NULL; 
} 
   
int N = 5;

int main() 
{ 
  	pthread_t thread[N]; 
	for (int i = 1; i <= N; ++i) 
	{
		printf("Thread creation\n");
		pthread_create(&thread[i], NULL, threadFunct, (void *)(&thread[i])); 
	}	
	for (int i = 1; i <= N; ++i) 
	{
		pthread_join(thread[i], NULL); 
	}	
	return 0;
}

