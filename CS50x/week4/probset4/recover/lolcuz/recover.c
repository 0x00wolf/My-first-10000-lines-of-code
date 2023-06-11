#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cs50.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;
//byte buffer[0] == 0xFF;
//byte buffer[1] == 0xD8;
//byte buffer[2] == 0xDF;
int main(int argc, char *argv[])
{
    //check their are only two command line arguments
    if (argc != 2)
    {
        printf("Usage: program_name + file_to_recover\n");
        return 1;
    }
    //Open the file to recover images from
    FILE *recover_from = fopen(argv[1], "r");
    if (recover_from == NULL)
    {
        printf("Wrong file bucko.\n");
        return 1;
    }
//fread f bytes, 1 fread(data, size, number, inptr)
            //data - poihnt to where you store the data you are reading, a buffer
            // size of each element to read
            // number of elements to read
            // inptr - file you are going to read that data from
    BYTE block[BLOCK_SIZE];
    int x = 0;
    while (fread(block, 1, BLOCK_SIZE, recover_from) == BLOCK_SIZE)
    {
        if (block[0] == 255 && block[1] == 216 && block[2] == 255 && (block[3] & 240) == 224)
        {
            char *buffer = NULL;
            sprintf(buffer, "%03i.jpg", x);
            puts(buffer);
        }
        else
        {
            char* buffer = NULL;
            sprintf(buffer, "%03i.jpg", x);
            puts(buffer);
        }
    }
    printf("WORK SON. WORK WORK WORK. RIHANNANANANA\n");
}
//open memory card - fopen recover_from
//look for beginning of a jpeg if jpeg_header( typedef struct with 3 bites comrprising start of jpeg file)
//open a new jpeg file  (fwrite jpeg header, and bytes until bytes = typedef strcut jpeg header)
//write 512 bytes unit a new jpeg is found





//first 3 bytes of jpeg = 0xFF 0xD8 0xFF (255, 216, 218) or (11111111, 11011000, 11111111)
// fourth byte always starts with 1110(+ xxxx)

///open memory card
//look for begining of a jpeg
//open a new jpeg file
// write 512 byte chunks until a new jpeg

//FILE *f = fopen(filenmae, "r");
     //       buffer[0] == 0xFF
     //       buffer[1] == 0xD8
     //       buffer[2] == 0xDF
     //       buffer [3] use bitwise arithmatic
     //       (buffer[3] & 0xf0) == 0xe0
     //       filenames: ###.jpg starting at 000.jpg
     //       use sprintf(filename "%03i.jpg", 2);
     //       FILE *img = fopen(filename, "w");
     //       fwrite(data, size, number, outptr);
     //       data: pointer to bytes that will be written
     //       size : size of each element
     //       number: number of elements to write
     //       outptr: FILE * to write to
    //if byte  0xFF 0xD8 0xFF 0xef
    //0xe0, 0xe1... 0xef
    //each block 512 bytes
    //check for 4 byte jpeg header
    //loop through memory card
    //if found a block, open a new jpeg file and write to it, until you find another block that has
        //a 4 byte jpeg header, and close the current jpeg, open a new jpeg, and write to it,
        //until you have found another


//open memory card
//repeat process until end of card
    //read 512 bytes into buffer
    //then look at 512 bytes
        //if start of new jpeg
            //if first jpeg
            //start writign
            //else if not new jpeg
                //keep writing
            //else if is new jpeg
                //stop writing
                //close the file
                //open new file
        //else if already found a jpeg
            //increment jpeg fiels to write to
            //open new file