#include <stdio.h>
int main() {
    char ch;
    for(ch = 'A'; ch <= 'Z'; ch ++){
        putchar(ch);
        printf("\n%i\n", ch);
    }
    puts("");
}