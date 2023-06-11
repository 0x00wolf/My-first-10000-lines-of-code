// Modifies the volume of an audio file
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
// Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

// Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
//USES a float to create a scalable factor for the volume
    float factor = atof(argv[3]);
    //maybe create a header + 1 b
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
//first fread() first 44 bytse from input.wav and then
//fwrite to write 44 bytes to the output file

//Use array of 44 bit unsigned integers (uint8_t) array[44]

//uint8_t stores unsigned 8 bit unsigned integers (1 Byte)

//uint16_t stores unsigned 16 bit integers
// perfect size for 2 byte samples
// TODO: Copy header from input file to output file
//fwrite() to new file the header from input file

// TODO: Read samples from input file and write updated data to output file
//scaling 16 bits. 0.5 = volume in half; 2.0 = double the volume; 1.1 = turn the knob to 11 mate.
// Close files
fclose(input);
    fclose(output);
}
