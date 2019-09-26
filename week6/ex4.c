#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigkill(int sig)
{
    	printf("Cannot catch SIGKILL signal.\n");
	exit(0);
}

void handle_sigstop(int sig)
{
    	printf("Cannot catch sigstop signal.\n");
	exit(0);
}

void handle_sigusr1(int sig)
{
    	printf("User defined signal 1.\nProgram is terminated.\n");
	exit(0);
}

int main()
{
    	signal(SIGKILL, handle_sigkill);
    	signal(SIGSTOP, handle_sigstop);
    	signal(SIGUSR1, handle_sigusr1);	// We can see output of this handle only, because SIGKILL and SIGSTOP signals cannot be caught or ignored

  	while (1)        
		sleep(2);

   	return 0;
}
