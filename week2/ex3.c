#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int numOfStars = 1;
    for (int i = 0; i < n; ++i)
    {
        int numOfSpace = ((2 * n - 1) - numOfStars) / 2;
        for (int j = 0; j < numOfSpace; ++j)
            printf(" ");
        for (int j = 0; j < numOfStars; ++j)
            printf("*");
        for (int j = 0; j < numOfSpace; ++j)
            printf(" ");
        printf("\n");
        numOfStars += 2;
    }
    return 0;
}
