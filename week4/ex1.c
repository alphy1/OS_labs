#include <stdio.h>
#include <unistd.h>

int main()
{
	int n = 5;
	int p = fork();
	if (p == 0)
		printf("Hello from child [%d - %d]\n", p, n);
	else
		printf("Hello from parent [%d - %d]\n", p, n);
	return 0;
}
