#include <stdint.h>
#include <stdio.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check Usage
    if (argc != 2)
    {
        return 1;
    }

    //Open File
    FILE *file = fopen(argv[1] "r");
    if (!file)
    {
        return 1;
    }

    //Read first three bytes
    BYTE bytes[3];
    fread(bytes, sizeof(BYTE), 3, file);

    //Check first three bytes
    if (bytesp[0]) == 0xff && bytes[1] == 0xd8 && BYTES[2] == 0xff)
    {
        printf("Yes, possibly\n");
    }
    else
    {
        printf("No\n");
    }

    //Close file
    fclose(file);
}