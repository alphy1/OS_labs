#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

#define MAXN 1000

int main()
{
	char string1[MAXN] = "I am a first string!";
	char string2[MAXN] = "Some trash";
	printf("Before pipe\nContent of first string: %s\nContent of second string: %s\n", string1, string2);
	
	int fd[2];
	if (pipe(fd) != 0)
	{	
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	}
	
	write(fd[1], string1, strlen(string1));
	close(fd[1]);
	read(fd[0], string2, MAXN);
	close(fd[0]);

	printf("After pipe\nContent of first string: %s\nContent of second string: %s\n", string1, string2);
	return 0;
}
