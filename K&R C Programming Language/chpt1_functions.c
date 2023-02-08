#include <stdio.h>

int power(int m, int n);

/* test power function */
void main(){
    int i;

    for (i = 0; i < 16; ++i)
        printf("%3d %5d %8d\n", i, power(2,i), power(3,i));
}

/* power: rases base to the n-th power; n >= 0 */
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
