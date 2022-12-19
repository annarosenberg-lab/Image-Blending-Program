#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned short WORD; 
typedef unsigned int DWORD; 
typedef unsigned int LONG; 
typedef struct tagBITMAPFILEHEADER{
    char bfType[2];
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
}   BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER{
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
}BITMAPINFOHEADER;

typedef unsigned char BYTE;
typedef struct RGB
{
    BYTE r;
    BYTE g;
    BYTE b;
}RGB;




int main(int argc, char *argv[])
{
    if (argc != 5){
        printf("You have inputed missing parameters, please format your input as the following:\n[programname] [imagefile1] [imagefile2] [ratio] [outputfile]\n");
            return 0;
    }
    float ratio =  atof(argv[3]);
    if (ratio < 0.0 | ratio > 1.0){
        printf("You have inputed wrong parameters, please format your input as the following:\n[programname] [imagefile1] [imagefile2] [ratio] [outputfile]\nThe ratio must be between 0.0 an 1.0.");
            return 0;
    }
    


    BITMAPFILEHEADER fh;
    BITMAPINFOHEADER fih;
    //BYTE *data = new BYTE[fih.biSizeImage];
    RGB pxl;
    FILE *image1 = 0;
    image1 = fopen(argv[1], "rb");
    if(image1 ==0){
            printf("You have inputed wrong parameters, please format your input as the following:\n[programname] [imagefile1] [imagefile2] [ratio] [outputfile]\n");
            return 0;
        }
    //FILE *image1 = fopen("lion.bmp", "rb");
    fread(&fh.bfType,2,1,image1);
    fread(&fh.bfSize,sizeof(int),1,image1);
    fread(&fh.bfReserved1,sizeof(short),1,image1);
    fread(&fh.bfReserved2,sizeof(short),1,image1);
    fread(&fh.bfOffBits,sizeof(int),1,image1);

    fread(&fih.biSize,sizeof(int),1,image1);
    fread(&fih.biWidth,sizeof(int),1,image1);
    fread(&fih.biHeight,sizeof(int),1,image1);
    fread(&fih.biPlanes,sizeof(short),1,image1);
    fread(&fih.biBitCount,sizeof(short),1,image1);
    fread(&fih.biCompression,sizeof(int),1,image1);
    fread(&fih.biSizeImage,sizeof(int),1,image1);
    fread(&fih.biXPelsPerMeter,sizeof(int),1,image1);
    fread(&fih.biYPelsPerMeter,sizeof(int),1,image1);
    fread(&fih.biClrUsed,sizeof(int),1,image1);
    fread(&fih.biClrImportant,sizeof(int),1,image1);
    //BYTE *data = new BYTE[fih.biSizeImage];
    //fread(data,fih.biSizeImage, 1, image1);


    //fclose(image1);
    FILE *copy = fopen("copyimage1.bmp", "wb");

    fwrite(&fh.bfType,2,1,copy);
    fwrite(&fh.bfSize,sizeof(int),1,copy);
    fwrite(&fh.bfReserved1,sizeof(short),1,copy);
    fwrite(&fh.bfReserved2,sizeof(short),1,copy);
    fwrite(&fh.bfOffBits,sizeof(int),1,copy);

    fwrite(&fih.biSize,sizeof(int),1,copy);
    fwrite(&fih.biWidth,sizeof(int),1,copy);
    fwrite(&fih.biHeight,sizeof(int),1,copy);
    fwrite(&fih.biPlanes,sizeof(short),1,copy);
    fwrite(&fih.biBitCount,sizeof(short),1,copy);
    fwrite(&fih.biCompression,sizeof(int),1,copy);
    fwrite(&fih.biSizeImage,sizeof(int),1,copy);
    fwrite(&fih.biXPelsPerMeter,sizeof(int),1,copy);
    fwrite(&fih.biYPelsPerMeter,sizeof(int),1,copy);
    fwrite(&fih.biClrUsed,sizeof(int),1,copy);
    fwrite(&fih.biClrImportant,sizeof(int),1,copy);
    

    for(int y=0;y<fih.biHeight;y++)
        for(int x=0;x<fih.biWidth;x++)
        {
            fread(&pxl.r, sizeof(BYTE), 1, image1);
            fread(&pxl.g, sizeof(BYTE), 1, image1);
            fread(&pxl.b, sizeof(BYTE), 1, image1);
            fwrite(&pxl.r, sizeof(BYTE), 1, copy);
            fwrite(&pxl.g, sizeof(BYTE), 1, copy);
            fwrite(&pxl.b, sizeof(BYTE), 1, copy);
        }

 

    fclose(image1);
    

    FILE *image2 = 0;
    image2 = fopen(argv[2], "rb");
    if(image2 ==0){
            printf("You have inputed wrong parameters, please format your input as the following:\n[programname] [imagefile1] [imagefile2] [ratio] [outputfile]\n");
            return 0;
        }
    fread(&fh.bfType,2,1,image2);
    fread(&fh.bfSize,sizeof(int),1,image2);
    fread(&fh.bfReserved1,sizeof(short),1,image2);
    fread(&fh.bfReserved2,sizeof(short),1,image2);
    fread(&fh.bfOffBits,sizeof(int),1,image2);

    fread(&fih.biSize,sizeof(int),1,image2);
    fread(&fih.biWidth,sizeof(int),1,image2);
    fread(&fih.biHeight,sizeof(int),1,image2);
    fread(&fih.biPlanes,sizeof(short),1,image2);
    fread(&fih.biBitCount,sizeof(short),1,image2);
    fread(&fih.biCompression,sizeof(int),1,image2);
    fread(&fih.biSizeImage,sizeof(int),1,image2);
    fread(&fih.biXPelsPerMeter,sizeof(int),1,image2);
    fread(&fih.biYPelsPerMeter,sizeof(int),1,image2);
    fread(&fih.biClrUsed,sizeof(int),1,image2);
    fread(&fih.biClrImportant,sizeof(int),1,image2);

    FILE *copy2 = fopen("copyimage2.bmp", "wb");

    fwrite(&fh.bfType,2,1,copy2);
    fwrite(&fh.bfSize,sizeof(int),1,copy2);
    fwrite(&fh.bfReserved1,sizeof(short),1,copy2);
    fwrite(&fh.bfReserved2,sizeof(short),1,copy2);
    fwrite(&fh.bfOffBits,sizeof(int),1,copy2);

    fwrite(&fih.biSize,sizeof(int),1,copy2);
    fwrite(&fih.biWidth,sizeof(int),1,copy2);
    fwrite(&fih.biHeight,sizeof(int),1,copy2);
    fwrite(&fih.biPlanes,sizeof(short),1,copy2);
    fwrite(&fih.biBitCount,sizeof(short),1,copy2);
    fwrite(&fih.biCompression,sizeof(int),1,copy2);
    fwrite(&fih.biSizeImage,sizeof(int),1,copy2);
    fwrite(&fih.biXPelsPerMeter,sizeof(int),1,copy2);
    fwrite(&fih.biYPelsPerMeter,sizeof(int),1,copy2);
    fwrite(&fih.biClrUsed,sizeof(int),1,copy2);
    fwrite(&fih.biClrImportant,sizeof(int),1,copy2);

    for(int y=0;y<fih.biHeight;y++)
        for(int x=0;x<fih.biWidth;x++)
        {
            
            fread(&pxl.r, sizeof(BYTE), 1, image2);
            fread(&pxl.g, sizeof(BYTE), 1, image2);
            fread(&pxl.b, sizeof(BYTE), 1, image2);
            fwrite(&pxl.r, sizeof(BYTE), 1, copy2);
            fwrite(&pxl.g, sizeof(BYTE), 1, copy2);
            fwrite(&pxl.b, sizeof(BYTE), 1, copy2);
        }

    fclose(image2);

    copy = fopen("copyimage1.bmp", "rb");
    fclose(copy2);
    copy2 = fopen("copyimage2.bmp", "rb");
    fread(&fh.bfType,2,1,copy2);
    fread(&fh.bfSize,sizeof(int),1,copy2);
    fread(&fh.bfReserved1,sizeof(short),1,copy2);
    fread(&fh.bfReserved2,sizeof(short),1,copy2);
    fread(&fh.bfOffBits,sizeof(int),1,copy2);

    fread(&fih.biSize,sizeof(int),1,copy2);
    fread(&fih.biWidth,sizeof(int),1,copy2);
    fread(&fih.biHeight,sizeof(int),1,copy2);
    fread(&fih.biPlanes,sizeof(short),1,copy2);
    fread(&fih.biBitCount,sizeof(short),1,copy2);
    fread(&fih.biCompression,sizeof(int),1,copy2);
    fread(&fih.biSizeImage,sizeof(int),1,copy2);
    fread(&fih.biXPelsPerMeter,sizeof(int),1,copy2);
    fread(&fih.biYPelsPerMeter,sizeof(int),1,copy2);
    fread(&fih.biClrUsed,sizeof(int),1,copy2);
    fread(&fih.biClrImportant,sizeof(int),1,copy2);

    //fclose(image1);
    
    FILE *merged = 0;
    
    merged = fopen(argv[4], "wb");
    
    fwrite(&fh.bfType,2,1,merged);
    fwrite(&fh.bfSize,sizeof(int),1,merged);
    fwrite(&fh.bfReserved1,sizeof(short),1,merged);
    fwrite(&fh.bfReserved2,sizeof(short),1,merged);
    fwrite(&fh.bfOffBits,sizeof(int),1,merged);

    fwrite(&fih.biSize,sizeof(int),1,merged);
    fwrite(&fih.biWidth,sizeof(int),1,merged);
    fwrite(&fih.biHeight,sizeof(int),1,merged);
    fwrite(&fih.biPlanes,sizeof(short),1,merged);
    fwrite(&fih.biBitCount,sizeof(short),1,merged);
    fwrite(&fih.biCompression,sizeof(int),1,merged);
    fwrite(&fih.biSizeImage,sizeof(int),1,merged);
    fwrite(&fih.biXPelsPerMeter,sizeof(int),1,merged);
    fwrite(&fih.biYPelsPerMeter,sizeof(int),1,merged);
    fwrite(&fih.biClrUsed,sizeof(int),1,merged);
    fwrite(&fih.biClrImportant,sizeof(int),1,merged);

    RGB pxl_1;
    RGB pxl_2;
    RGB pxl_merged;

   
    for(int y=0;y<fih.biHeight;y++)
        for(int x=0;x<fih.biWidth;x++)
        {
            fread(&pxl_1.r, sizeof(BYTE), 1, copy);
            fread(&pxl_1.g, sizeof(BYTE), 1, copy);
            fread(&pxl_1.b, sizeof(BYTE), 1, copy);
            fread(&pxl_2.r, sizeof(BYTE), 1, copy2);
            fread(&pxl_2.g, sizeof(BYTE), 1, copy2);
            fread(&pxl_2.b, sizeof(BYTE), 1, copy2);

            pxl_merged.r = (pxl_1.r*ratio) + (pxl_2.r*(1-ratio));
            pxl_merged.g = (pxl_1.g*ratio) + (pxl_2.g*(1-ratio));
            pxl_merged.b = (pxl_1.b*ratio) + (pxl_2.b*(1-ratio));

            fwrite(&pxl_merged.r, sizeof(BYTE), 1, merged);
            fwrite(&pxl_merged.g, sizeof(BYTE), 1, merged);
            fwrite(&pxl_merged.b, sizeof(BYTE), 1, merged);
        }


   
        



    fclose(copy);
    fclose(copy2);
    fclose(merged);
    return 0;
}
