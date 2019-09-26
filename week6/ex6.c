#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

void handle_sigterm(int sig)
{
    	printf("Termination signal from first child.\nSecond child process is terminated.\n");
	exit(0);
}

int main()
{
	int fd[2];
	if (pipe(fd) != 0)
	{	
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	}	
	
	printf("P: I am a parent.\nP: Create first child.\n");
	pid_t child1 = fork();
	
	if (child1 == 0)
	{
		printf("CH1: I am a first child.\n");
		
		int bro_pid;
		printf("CH1: Read second child's pid.\n");
		read(fd[0], &bro_pid, sizeof(int));
		
		printf("CH1: Sleep for 5 seconds.\n");
		sleep(5);

		kill(bro_pid, SIGTERM);
	}
	else
	{
		printf("P: Creat second child.\n");
		pid_t child2 = fork();
		
		if (child2 == 0) 
		{
			printf("CH2: I am a second child.\n");
			signal(SIGTERM, handle_sigterm);
			while (1) sleep(1);
		}
		else 
		{
			printf("P: Send second child's pid to first using pipe.\n");
			write(fd[1], &child2, sizeof(int));

			printf("P: Wait for state changes in second child.\n");
			waitpid(child2, NULL, 0);
		}
	}
   	return 0;
}
