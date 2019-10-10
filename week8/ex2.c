#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const int m = 500 * 1024 * 1024;

int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		int *a = (int *)malloc(m); 	// allocate some memory
		memset(a, 0, m); 		// fill by 0
		sleep(1);			// sleep for 1 second
	}
	return 0;
}
