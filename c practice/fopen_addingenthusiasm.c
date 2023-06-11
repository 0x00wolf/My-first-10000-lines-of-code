#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file_to_read = fopen("sometext.txt", "r");
    FILE *file_to_write = fopen("newtext.txt", "w");

    if (file_to_read == NULL || file_to_write == NULL) {
        printf("Danger Will Robinson!\n");
        return -1;
    }

    char c;
    //read characters one at a time and print to new file (change '.' for '!') (having a time -DD)
    while ((c=fgetc(file_to_read)) != EOF) {
        if (c == '.') {
            c = '!';
        }
        fputc(c, file_to_write);
    }
    fclose(file_to_read);
    fclose(file_to_write);
}