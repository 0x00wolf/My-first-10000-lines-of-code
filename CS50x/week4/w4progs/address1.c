#include <stdio.h>

int main(void)
{
// Store's and prints an integer's address
    int n = 50;
    int *p = &n;
    printf("%p\n", p);
// Stores and prints an integer via its address
    printf("%i\n", *p);
}


// The & operator means get the address of this variable.
// The * declares the variable as a pointer
// * is also the dereference operator, which goes to an address to get teh value stored there