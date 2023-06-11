#include <stdio.h>

int main() {
    int j = 100;
    int i = 0;
    while (i < j)
    {
        printf("%d\n", i++);
    }
    do
    {
        printf("%i\n", i);
        i--;
    }    
    while (i >= 0);
}