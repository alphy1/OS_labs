#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int input = open("ex1.txt", O_RDONLY);
	int output = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IRUSR + S_IWUSR + S_IRGRP + S_IWGRP + S_IROTH); // flags and permissions
	if (input == -1)
	{
		printf("ERROR (Cannot open file)\n");
		return 0;	
	}
	if (output == -1)
	{
		printf("ERROR (Cannot open file)\n");
		return 0;	
	}

	struct stat st;
	if (fstat(input, &st) == -1) 
	{
		printf("ERROR (Cannot get stats of the file)\n");
		return 0;	
	}

	void *im = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, input, 0);
	void *om = mmap(NULL, st.st_size, PROT_WRITE, MAP_SHARED, output, 0);

	ftruncate(output, st.st_size);

	memcpy(om, im, st.st_size);
	msync(om, st.st_size, MS_SYNC);

	munmap(im, st.st_size);
	munmap(om, st.st_size);

	close(input);
	close(output);
	return 0;
}
