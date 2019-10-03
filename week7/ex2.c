#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int N;
	scanf("%d", &N);
	int *a = (int *)malloc(N * sizeof(int));
	a[0] = 0;
	for (int i = 1; i < N; ++i)
		a[i] = a[i - 1] + 1;
	for (int i = 0; i < N; ++i)
		printf("%d ", a[i]);
	printf("\n");
	free(a);
	return 0;
}
