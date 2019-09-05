#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define MAXV 1000

void bubble_sort(int *a)
{
    for (int i = 0; i < N; ++i)
        for (int j = 1; j < N; ++j)
            if (*(a + j - 1) > *(a + j))
            {
                int t = *(a + j - 1);
                *(a + j - 1) = *(a + j);
                *(a + j) = t;
            }
}

int main()
{
    srand(time(NULL));  // initialization of rand function
    int a[N];           // create array
// fill array
    for (int i = 0; i < N; ++i)
        a[i] = rand() % MAXV;
// print array
    printf("Initial array:\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", a[i]);
    printf("\n\n");
// Sort array
    bubble_sort(a);
// print array
    printf("Sorted array:\n");
    for (int i = 0; i < N; ++i)
        printf("%d ", a[i]);
}
