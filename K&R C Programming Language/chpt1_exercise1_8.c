#include <stdio.h>
void main(){
    int x;
    int s = 0;
    int n = 0;
    int t = 0;
    while ((x = getchar()) != EOF){
        if (x == ' ')
            s++;
        else if (x == '\n')
            n++;
        else if (x == '\t')
            t++;
    }
    printf("\nspaces: %d\n", s);
    printf("newlines: %d\n", n);
    printf("tabs: %d\n", t); 
}
