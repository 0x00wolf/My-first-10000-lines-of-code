#include <stdio.h>

/* Count characters in input; 1st version */

void main()
{
    double nc;

    for (nc = 0; getchar () != EOF; ++nc)
        ;   /* NULL statement */
    printf("%.0f\n", nc);
}
