#include <stdio.h>

/*
    Im going to write a simple alogirth that 
    first checks n%2 is equal to 1, if so, then we know that would be
    a 1 in binary, hence we increment sum by 1
    then it divides n by 2 
    and so on, until the number is 0
*/
int solution(int A, int B)
{
    // We simply store A*B
    int n = A * B;
    // This is our sum of 1s we are going to return at the end
    int sum = 0;
    // Here we go over n until its 0
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            sum++;
        }
        n = n / 2;
    }
    return sum;
}

int main()
{
    printf("%d\n", solution(34, 1));
    return 0;
}