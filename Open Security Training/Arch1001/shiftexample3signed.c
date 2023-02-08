#include <stdlib.h>

int main(int argc, char **argv)
{
    int a, b, c;
    a = atoi(argv[1]);
    b = a * 8;
    c = b / 16;
    return c;
}
