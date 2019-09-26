#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

#define MAXN 1000

int main()
{
	char string[MAXN] = "I am a string!";
	printf("Content of string: %s\n", string);
	
	int fd[2];
	if (pipe(fd) != 0)
	{	
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	}


	write(fd[1], string, strlen(string));
	close(fd[1]);
	
	if (fork() == 0)
	{
		printf("I am child.\n");
		char s[MAXN] = "";
		read(fd[0], s, MAXN);
		printf("Content of string passed: %s\n", s);
	}
	else
		printf("I am parent.\n");
	return 0;
}
