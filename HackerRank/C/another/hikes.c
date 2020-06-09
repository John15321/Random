
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Complete the countingValleys function below.
int countingValleys(int n, char *s)
{
    int last_sign = 0;
    int level = 0;
    int valleys = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            level++;
        }
        else if (s[i] == 'D')
        {
            level--;
        }
        else
        {
            printf("Hey thats not a proper letter: %d\n", i);
        }
        if (last_sign < 0 && level >= 0)
        {
            valleys++;
        }

        last_sign = level;
    }
    return valleys;
}

int main()
{
    int n = 8;
    char s[] = "DDUUUUDD";
    int result = countingValleys(n, s);
    printf("%d\n", result);
    return 0;
}
