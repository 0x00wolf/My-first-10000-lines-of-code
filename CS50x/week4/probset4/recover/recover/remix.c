#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

void print_shit(FILE *file, int x, BYTE array[BLOCK_SIZE]);

int main(int argc, char *argv[])
{
//Check that only two arguments supplied on input
    if (argc != 2)
    {
        puts("YOU SHALL NOT PASS.");
        return 1;
    }
//Open the file supplied by argv[1]
    FILE *file = fopen(argv[1], "r");
//If fopen failed print out you suck
    if (file == NULL)
    {
        puts("YOU SHALL NOT PASS.");
        return 1;
    }
    int x = 0;
    int y = 0;
    BYTE buffer[BLOCK_SIZE];
    char filename[9];
//loop through the file by 512 byte blocks
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {

        if (buffer[0] == 0 && buffer[1] == 0 && buffer[2] == 0 && buffer[3] == 0)
        {
            printf("Damn son, where'd you find this.\n");
            break;
        }
        if (y == 0)
        {
            if ( y ==buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
            {
                y++;
                sprintf(filename, "%03i.jpg", x);
                FILE *output = fopen(filename, "w");
                if (output != NULL)
                {
                    print_shit(output, &buffer, x);
                }
            }
            else
            {
                continue;
            }
        }
        else if (y == 1)
        {
            if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
            {
                x++;
                sprintf(filename, "%03i.jpg", x);
                FILE *output = fopen(filename, "w");
                if (output != NULL);
                {
                    print_shit(output, buffer, x);
                }
            }
            else if (buffer[0] != 255 && buffer[1] != 216 && buffer[2] != 255)
            {
                FILE *output = fopen(filename, "a");
                if (output != NULL)
                {
                    print_shit(output, buffer, x);
                }
            }
            else if (buffer[0] == NULL && buffer[1] == NULL && buffe[2] == NULL && buffer[3] == NULL)
            {
                continue;
            }
        }
    }
    return 0;
}

void print_shit(FILE *file, int x, BYTE array[BLOCK_SIZE])
{
    fwrite(array, 512, 1, file);
    fclose(file);
}