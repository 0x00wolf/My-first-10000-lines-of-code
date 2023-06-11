#include <stdio.h>

/* count characters in input; 1st version */
int main()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
    {
        ++nc;
    }   
    // -1 so that '\0' (NULL), does not add 1 to count.
    printf("%ld\n", nc - 1);
    return 0;
}