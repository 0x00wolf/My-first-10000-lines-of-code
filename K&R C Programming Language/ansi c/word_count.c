#include <stdio.h>


/* Count lines, words, and characters in input */
void main()
{
    int c, n1, nw, nc, state;

    state = OUT;
    n1 = nw = nc = 0;   /* Assignments associate 
                           from right to left */
    while ((c = getchar()) != EOF) 
    {
        ++nc;
        if (c == '\n')
        {
            ++n1;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", n1, nw, nc);
}