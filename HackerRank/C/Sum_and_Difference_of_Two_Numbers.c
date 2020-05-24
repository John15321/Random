#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int a, b;
    float d, c;
    scanf("%d %d", &a, &b);
    scanf("%f %f", &d, &c);

    printf("%d %d\n%.1f %.1f\n", a + b, a - b, d + c, d - c);
    return 0;
}