#include <stdio.h>

/* print a histogram of different characters entered as input */
void main(){
    int c, nwhite, nother, pos, innerpos;
    int repetitions[36];

    nwhite = nother = 0;

    for (pos = 0; pos < 36; pos++)
        repetitions[pos] = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else if (c >= '0' && c <= '9')
            repetitions[c- '0']++;
        else if (c >= 'a' && c <= 'z')
            repetitions[c- 'a'+10]++;
        else if (c >= 'A' && c <= 'Z')
            repetitions[c- 'A'+10]++;
        else
            nother++;
    }

    for (pos = 0; pos < 36; pos++){
        if (pos <= 9)
            printf("%d|", pos);
        else
            printf("%c|", pos - 10 + 'A');
        for (innerpos = 0; innerpos < repetitions[pos]; innerpos++)
            printf("=");
        printf("\n");
    }

    printf("white spaces|");
    for (pos = 0; pos < nwhite; pos++)
        printf("=");
    printf("\n");

    printf("other|");
    for (pos = 0; pos < nother; pos++)
        printf("=");
    printf("\n");
}
