#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 1e6;

int main()
{
    char s[MAX_SIZE];
    scanf("%s", s);
    for (int i = strlen(s) - 1; i >= 0; --i)
        printf("%c", s[i]);
    return 0;
}
