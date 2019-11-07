#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	char c;
	FILE *output;
	if (argc == 1) {
		while (scanf("%c", &c) == 1) {
			printf("%c", c);
		}
	}
	else if (argc == 2) {
		output = fopen(argv[1], "w");
		while (scanf("%c", &c) == 1) {
			fprintf(output, "%c", c);
			printf("%c", c);
		}	
	}
	else if (argc == 3) {
		output = fopen(argv[2], "a");
		while (scanf("%c", &c) == 1) {
			fprintf(output, "%c", c);
			printf("%c", c);
		}	
	}
	return 0;
}
