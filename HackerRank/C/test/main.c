#include <stdio.h>
#include <stdlib.h>

// I will try to put comments that mean what i thought when I was writing my code
// I hope thats something good for you as an interviewer (ofc normally its also nice to put comments)
char *solution(int N)
{
    // First we create a string thats the length of N dynamically
    // so that we dont looise it after this functions finishes
    // because if we were to do char s[N] that would be freed when the scope 
    // of the function ends
    char *s = (char *)malloc((N+1) * sizeof(char));
    // We ask for one more for the sake of \0 character to end the string correctly
    s[N]='\0';
    // Also I should here check if we acutally got the newly allocated memory
    // that we asked for. By checking if malloc returns a null pointer
    // but I actually dont know how that would work on the Codility platform(?)
    int i = 0;
    // Also if we were to declare i inside the loop we would have to destroy our 
    // variables twice (once when we exit the loop and the secont time when the function ends)
    // but now i is simply gonna be disposed off togheder with N
    // when the function ends
    for (; i < N; i++)
    {
        // Here simply every second character should be a "-" etc
        if (i % 2 == 0)
        {
            s[i] = '+';
        }
        else
        {
            s[i] = '-';
        }
    }
    // Here we return a pointer to our newly allocated
    // and filled (with "+"s and "-"s) string
    return s;
}

int main()
{
    int n;
    char *k;
    scanf("%d", &n);
    k=solution(n);
    printf("%s\n", k);
    return 0;
}