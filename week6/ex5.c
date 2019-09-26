#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigterm(int sig)
{
    	printf("Termination signal from parent.\nChild process is terminated.\n");
	exit(0);
}

int main()
{
	pid_t p = fork();
	if (p == 0)
	{
		signal(SIGTERM, handle_sigterm);
		while (1)
		{
			printf("I'm alive\n");
			sleep(1);		
		}	
	}
	else
	{
		sleep(10);
		kill(p, SIGTERM);
	}
   	return 0;
}
