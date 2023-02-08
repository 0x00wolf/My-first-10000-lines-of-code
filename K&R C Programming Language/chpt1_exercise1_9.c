#include <stdio.h>

void main(){
    int c;
    int i = 0;
    while ((c = getchar()) != EOF){
        if (i == 0) {
            if (c == ' '){
                i = 1;
                putchar(c);
            }
            else
                putchar(c);
        }
        else {
            if (c == ' ')
                ;
            else {
                i = 0;
                putchar(c);
            }
        }
    }
}
