#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// #include "bmp.h"

#define BLOCK 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    
    uint8_t buffer[BLOCK];
    int jpegCounter = 0;
    char filename[8];
    FILE *img = NULL;
    
    while (fread(&buffer, BLOCK, 1, inptr) == 1)
    {
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff 
        && (buffer[3] & 0xf0) == 0xe0)
        {
            // if an image file is open, close it
            if (img != NULL)
                fclose(img);
            
            // create a file name     
            sprintf(filename, "%03i.jpg", jpegCounter);
            
            // open a new image
            img = fopen(filename, "w");
            
            // increcement jpeg counter
            jpegCounter += 1;
        }
        
        // if a jpeg header was found and a new image is open
        if (img != NULL)
        {
            // write current block to new image file
            fwrite(&buffer, BLOCK, 1, img);
        }
            
    }
    
    if (img != NULL)
        fclose(img);
    
    fclose(inptr);
    
    return 0;
}