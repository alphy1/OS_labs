#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  	int input = open("/dev/urandom", O_RDONLY);
  	char s[21]; 	// 21 because of the null character '\0'

	read(input, s, 20);
  	s[20] = '\0';

    // to make text readable
	for(size_t i = 0; i < 20; ++i){
		s[i] = (s[i] % 62) + 65;
    	}	

	printf("%s", s);
	close(input);
	
	return 0;
}
