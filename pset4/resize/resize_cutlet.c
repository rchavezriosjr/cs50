/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize float infile outfile\n");
        return 1;
    }

    // remember filenames
    int resize_factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];


    // ensure float is within range
    if (resize_factor < 0 || resize_factor == FLT_MAX )
       {
           printf("Please enter a resize factor between zero and whatever");
       }
           
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // Store width of original image
    int oldWidth = bi.biWidth;
    
    // Store padding of original image
    int oldPadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Multiply width in header file by resize factor
    bi.biWidth *= resize_factor;
    bi.biHeight *= resize_factor;
    
    // Calculate new padding
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Calculate biSizeImage and biSize
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);
    bi.biSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // RGBTRIPLE currRow[oldWidth];
    // int rowNum = -1;
 
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
		{
				// Write each line factor-times
				for(int n = 0; n < resize_factor; n++)
				{
						// iterate over pixels in scanline
						for (int j = 0; j < oldWidth; j++)
						{
								// temporary storage
								RGBTRIPLE triple;

								// read RGB triple from infile
								fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

								// write RGB triple to outfile
								for(int m = 0; m < resize_factor; m++) 
								{
										fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
								}
						}

						// skip over padding in infile
						fseek(inptr, oldPadding, SEEK_CUR);

						// then add it to outfile
						for (int k = 0; k < padding; k++)
								fputc(0x00, outptr);

						fseek(inptr, -(oldWidth * 3 + oldPadding ), SEEK_CUR);

				}
				fseek(inptr, oldWidth * 3 + oldPadding, SEEK_CUR);
		}
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
