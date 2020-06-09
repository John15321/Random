// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

/*
This is a demo task.

Write a function:

int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int solution(int A[], int N)
{
    int min = A[0];
    int max = A[0];

    for (int i = 0; i < N; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    if (min <= 0 && max <= 0)
    {
        return 1;
    }
    else if (min > 1)
    {
        return 1;
    }
    else // {1, 2, 3, -1, 6}
    {
        min = 0;
        int not_okay = 1;
        while (not_okay)
        {
            min++;
            not_okay = 0;
            for (int z = 0; z < N; z++)
            {
                if (min == A[z])
                {
                    not_okay = 1;
                }
            }
        }
        return min;
    }
}

int main()
{
    int n = 6;
    int a[6] = {1,1,1,1,1,1};

    
    printf("%d\n", solution(a, n));
}
