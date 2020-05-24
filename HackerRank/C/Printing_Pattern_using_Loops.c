#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);

    // Vertical
    for (int i = 0; i < (n); i++)
    {
        for (int f = 0; f < i; f++)
        {
            printf("%d ", n - f);
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            printf("%d ", n - i);
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("%d ", n - i);
        }
        for (int f = 0; f < i + 1; f++)
        {
            printf("%d ", f + (n - i));
        }
        printf("\n");
    }
    // Mirrored Vertical
    for (int i = n - 2; i >= 0; i--)
    {
        for (int f = 0; f < i; f++)
        {
            printf("%d ", n - f);
        }

        for (int j = 0; j < n - i - 1; j++)
        {
            printf("%d ", n - i);
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            printf("%d ", n - i);
        }
        for (int f = 0; f < i + 1; f++)
        {
            printf("%d ", f + (n - i));
        }
        printf("\n");
    }
    return 0;
}