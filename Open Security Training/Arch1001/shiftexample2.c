#include <stdlib.h>
/* compile with -O2 to maximize speed */

int main(int argc, char **argv)
{
    unsigned int a, b, c;
    a = atoi(argv[1]);
    b = a * 8;
    c = b / 16;
    return c;
}

