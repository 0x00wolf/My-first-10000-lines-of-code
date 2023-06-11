#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;


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
    BYTE buffer[BLOCK_SIZE];
    char filename[16];
//loop through the file by 512 byte blocks
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (x == 0)
        {
            if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
            {
                sprintf(filename, "%03i.jpg", x + 1);
                FILE *output = fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, output);
            }
            else
            {
                continue;
            }
        }
        else if (x != 0)
        {
            if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
            {
                x++;
                sprintf(filename, "%03i.jpg", x);
                FILE *output = fopen(filename, "w");
                fwrite(buffer, BLOCK_SIZE, 1, output);
                fclose(output);
            }
            else
            {
                sprintf(filename, "%03i.jpg", x);
                FILE *output = fopen(filename, "a");
                fwrite(buffer, BLOCK_SIZE, 1, output);
                fclose(output);
            }
        }
    }
    return 0;
}
