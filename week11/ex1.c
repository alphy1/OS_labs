#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int ex1 = open("ex1.txt", O_RDWR); // open file ex1.txt in O_RDWR mode
	if (ex1 == -1)
	{
		printf("ERROR (Cannot open file)\n");
		return 0;	
	}

	struct stat st;
	if (fstat(ex1, &st)  == -1)
	{
		printf("ERROR (Cannot get stats of the file)\n");
		return 0;	
	}

	void* m = mmap(0, st.st_size, PROT_WRITE, MAP_SHARED, ex1, 0);
	ftruncate(ex1, sizeof("This is a nisa day!") - 1);
	memcpy(m, "This is a nice day!", sizeof("This is a nice day!"));
	msync(m, st.st_size, MS_SYNC);
	munmap(m, st.st_size);
	close(ex1);
	return 0;
}
