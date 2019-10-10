#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

const int m = 100 * 1024 * 1024;

int main()
{
	for (int i = 1; i <= 10; ++i)
	{
		int *a = (int *)malloc(m); 	// allocate some memory
		memset(a, 0, m); 		// fill by 0
		struct rusage usage;				
		getrusage(RUSAGE_SELF, &usage);
		printf("Max rss: %ld\nShared memory: %ld\nOwn memory: %ld\nOwn stack: %ld\n", usage.ru_maxrss, usage.ru_ixrss, usage.ru_idrss, usage.ru_isrss);
		sleep(1);			// sleep for 1 second
	}
	return 0;
}
