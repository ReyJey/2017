#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{
    if(argc!= 2){
        fprintf(stderr,"usage: ./recover image\n");
        return 1;
    }
    char* infile = argv[1];
    BYTE data[512];
    int jpgname = 000;
    FILE* outpr = 0;
    char namefile[6];
    FILE* inptr = fopen(infile,"r");
    if(inptr == 0){
        fprintf(stderr,"could not open %s.\n",infile);
        return 2;
    }
    int load = 0;
    while(fread(&data,512,1,inptr)!= 0){
        if((data[0] == 0xff)&&(data[1] == 0xd8)&&(data[2] == 0xff)&&((data[3]& 0xf0)== 0xe0)){
            if(load == 1){
                fclose(outpr);
            }
            sprintf(namefile,"%03i.jpg",jpgname);
            outpr = fopen(namefile,"w");
            load = 1;
            jpgname++;
            if(load == 1){
                fwrite(data,512,1,outpr);
            }
        }
        else if(load == 1){
            fwrite(data,512,1,outpr);
        }
    }
    fclose(inptr);
    
}