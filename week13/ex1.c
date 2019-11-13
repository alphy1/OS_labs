#include <stdio.h>

int current[5][3], request[5][3];
int e[3], a[3], finished[5];

int main () {
	FILE *input = fopen("input.txt", "r");
// Reading
	for (int i = 0; i < 3; ++i)
		fscanf(input, "%d", &e[i]);
	for (int i = 0; i < 3; ++i)
		fscanf(input, "%d", &a[i]);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 3; ++j)
			fscanf(input, "%d", &current[i][j]);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 3; ++j)
			fscanf(input, "%d", &request[i][j]);
// Doing processes
	while (1) {
		int is_finished = 0;		// will show did we finish at least one process or no, firstly let's think that no
		for (int i = 0; i < 5; ++i) 
			if (finished[i] == 0)	{	// if process is not finished
				int flag = 1; 	// will show can we finish process or no, firstly let's think that can
				for (int j = 0; j < 3; ++j)
					if (request[i][j] > a[j])		// oh no, we can't
	 					flag = 0;
				if (flag) {
					finished[i] = 1;
					is_finished = 1;			// eeee, finished one
				// free resources					
					for (int j = 0; j < 3; ++j)
						a[j] += current[i][j];				
				}
						
			}

	// if nothing 
		if (is_finished == 0) 
			break;
	}	
// Output
	FILE *output = fopen("output.txt", "w");
	int no_deadlock = 1; 	// will show if there is deadlock or no, firstly let's think that no
	for (int i = 0; i < 5; ++i)
		if (finished[i] == 0) {
			fprintf(output, "%d ", i);
			no_deadlock = 0;		
		}

	if (no_deadlock == 1)
		fprintf(output, "no deadlock!");
}
