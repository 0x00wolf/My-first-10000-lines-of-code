#include <unistd.h>

void _start(void)
{
    register int a = 10;
    register int b = 20;

    a +=b;
    _exit (a);
}
