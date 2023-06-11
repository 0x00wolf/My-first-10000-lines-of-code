#include <stdio.h>

void main() {
    int tab = 0;
    int newline = 0;
    int space = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++space;
        }
        else if (c == '\n')
        {
            ++tab;
        }
        else if (c == '\t')
        {
            ++newline;
        }
    }
    printf("blanks: %d\nnewlines: %d\ntabs: %d\n", space, newline, tab);
}