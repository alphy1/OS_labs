#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
    	printf("Interrupt signal.\nProgram is terminated.\n");
	exit(0);
}

int main()
{
    	signal(SIGINT, handle_signal);

  	while (1)
	{
		printf("Program is running.\n");        
		sleep(2);
    	}

   	return 0;
}
