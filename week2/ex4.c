#include <stdio.h>

void swap(int* const a, int* const b)
{
    int c;
    c = (*a);
    (*a) = (*b);
    (*b) = c;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}
