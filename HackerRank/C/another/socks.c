#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ifalready(int ar_count, int *arc, int check)
{
    for (int i = 0; i < ar_count; i++)
    {
        if (arc[i] == check)
        {
            return 1;
        }
    }
    return 0;
}

// Complete the sockMerchant function below.
int sockMerchant(int n, int ar_count, int *ar)
{
    int *arc = (int *)calloc(ar_count, sizeof(int));
    // Todo later: check if not null pointer
    int gc = 0;
    int same_color = 0;
    int current_color;
    int pairs = 0;
    int newone;
    for (int i = 0; i < ar_count; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (!ifalready(ar_count, arc, ar[j]))
            {
                current_color = ar[j];
                newone = j;
                j = n;
            }
        }

        for (int j = i; j < n; j++)
        {
            if (!ifalready(ar_count, arc, ar[j]))
            {
                if (current_color == ar[j])
                {
                    same_color++;
                }
            }
        }
        arc[i] = ar[newone];
        pairs = pairs + same_color / 2;
        same_color = 0;
    }
    return pairs;
}

int main()
{
    int n = 6;
    int ar_count = 1;
    int a[6] = {2, 2, 2, 2, 2, 2};
    int result = sockMerchant(n, ar_count, a);

    printf("%d\n", result);

    return 0;
}
