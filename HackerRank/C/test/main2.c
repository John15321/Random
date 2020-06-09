#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// I cant find if I am allowed to use helper functions like strlen in for example string.h
// but it works so i guess it is permited. So I will

/*
    What we are going to do is a simple. We are going to first loop over each 
    character in our string
    (we know its length thanks to strlen() function) and when we get that character
    from our first loop then we are going to loop over everything else till
    we find another one thats the same. Given our assumptions aka there is only
    one repeated character etc. I will not be checking if thats true. When we find that 
    repeater character we can simply exit the function and return it
*/
char *solution(char *S)
{
    // The task says only that I should return a single-character
    // and that return value of this function has to be a char*
    // So I am guessing they want me to allocate it and return a new char
    char *k = (char *)malloc(2 * sizeof(char));
    // Also I should check for a null pointer (which would mean that it
    // failed to allocate memory for our program)
    // but I dont know how that would work for codility

    // Here again we have to have an end of our string
    k[1] = '\0';

    // Same thing here like I said in the first task
    // no need to declare those variables inside loops if
    // its a functions that will end in a few lines
    int i;
    int j;
    // Here is out "dobule" loop
    for (i = 0; i < strlen(S); i++)
    {
        for (j = i + 1; j < strlen(S); j++)
        {
            if (S[i] == S[j])
            {
                k[0] = S[i];
                return k;
            }
        }
    }
    // Altho given assumptions given to me by Codility
    // That function would have to return something anyway
    // but C may have problems with me leaving it with a return
    // thats only in an if statement (for example if compiled with -Wall flag)
    // thats why im leaving here this return, so it would return at least something
    k[0] = S[0];
    return k;
}

int main()
{
    char k[] = "aba";
    solution(k);
    // printf("%c\n", *solution(k));
    printf("%c\n", *solution(k));
    return 0;
}