#include "hotrace.h"

int main()
{
    char *temp;
    long long i;

    i = 0;
    temp = (char *)malloc(16711560000900);
    if (!temp)
        printf("failed");
    while (i < 16711560000900)
    {
        temp[i] = 'a';
        if (i % 100000 == 0)
            printf("%lld\n", i);
        i++;
    }
    temp[16711560000899] = 'a';
    printf("%c\n", temp[16711560000899]);
    free(temp);
}