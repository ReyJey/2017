/**
* Copies a BMP piece by piece, just because.
*/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    
    int n = atoi(argv[1]);
    if(n < 1 || n > 100)
    {
        printf("n is invalid");
        return 1;
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
    
    int biWidth = bi.biWidth;
    int biHeight = bi.biHeight;
    int oldpading = (4 - (bi.biWidth * sizeof(RGBTRIPLE))%4)%4;
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    int newpading = (4 - (bi.biWidth * sizeof(RGBTRIPLE))%4)%4;
    bf.bfSize = (sizeof(RGBTRIPLE) * bi.biWidth + newpading) * abs(bi.biHeight) + sizeof(BITMAPINFOHEADER) + sizeof(BITMAPFILEHEADER);
    bi.biSizeImage = (sizeof(RGBTRIPLE) * bi.biWidth + newpading) * abs(bi.biHeight);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    
    // iterate over infile's scanlines
    for (int i = 0; i < abs(biHeight); i++)
    {
        for(int b = 0; b < n; b++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for(int y = 0; y < n; y++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
    
        // then add it back (to demonstrate how)
            for (int k = 0; k < newpading; k++)
            {
                fputc(0x00, outptr);
            }
            
            if(b < n - 1)
            {
                long int nid = biWidth * sizeof(RGBTRIPLE);
                fseek(inptr, -nid, SEEK_CUR);
            }
        }
        
        fseek(inptr, oldpading, SEEK_CUR);
    }
    
    // close infile
    fclose(inptr);
    
    // close outfile
    fclose(outptr);
    
    // success
    return 0;
}