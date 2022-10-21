/*
GRAYSON WHITAKER
ECE 2220-001
PROGRAM 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void readFunction(FILE *imageFile, char *imageName, FILE *outputFile, char *outputName);
void readheaderFunction(FILE *imageFile, FILE *outputFile, int type);
int paddingFunction(void);
void headerbytesFunction(FILE *imageFile, FILE *outputFile);
void rgbFunction(FILE *imageFile, FILE *outputFile, int padding);
void edgeFunction(FILE *imageFile, char *imageName, FILE *outputFile);

struct HEADER{
    unsigned short int Type;
    unsigned int Size;
    unsigned short int Reserved1, Reserved2;
    unsigned int Offset;
} Header;

struct INFOHEADER{
    unsigned int Size;           
    int Width, Height;           
    unsigned short int Planes;   
    unsigned short int Bits;     
    unsigned int Compression;    
    unsigned int ImageSize;      
    int xResolution, yResolution;
    unsigned int Colors;         
    unsigned int ImportantColors;
} InfoHeader;

typedef struct{
        unsigned char Blue, Green, Red;
} Pixel;

void main(int argc, char* argv[]){
    // exit if not enough arguments
    if(argc < 3){
        printf("\033[0;31mNot enough arguments...\033[0m\n");
        exit(0);
    }
    
    // create variables for command line arguments
    int read = strcmp(argv[1], "read");
    int edge = strcmp(argv[1], "edge");

    // exit if invalid arguments or invalid combinations of arguments
    if(read != 0 && edge != 0){
        printf("\033[0;31mInvalid arguments...\033[0m\n");
        exit(0);
    }
    else if(read == 0 && argc < 4){
        printf("\033[0;31mMust include output file...\033[0m\n");
        exit(0);
    }
    else if(edge == 0 && argc > 3){
        printf("\033[0;31mToo many arguments...\033[0m\n");
        exit(0);
    }

    // ensure valid file has been selected
    if(!(strstr(argv[2], ".bmp"))){
        printf("\033[0;31mInput file must be \".bmp\" type...\033[0m\n");
        exit(0);
    }

    // ensure input file opens
    FILE *imageFile = fopen(argv[2], "rb");
    if (imageFile == NULL){
        printf("\033[0;31mUnable to open file \"%s\"...\033[0m\n", argv[2]);
        exit(0);
    }

    // create output file
    FILE *outputFile;
    if(read == 0){
        readFunction(imageFile, argv[2], outputFile, argv[3]);
    }
    if(edge == 0){
        edgeFunction(imageFile, argv[2], outputFile);
    }
}

void readFunction(FILE *imageFile, char *imageName, FILE *outputFile, char *outputName){
    // create output file named by the user
    outputFile = fopen(outputName, "w");
    fprintf(outputFile, "\"%s\"\n", imageName);

    // read header info nto struct and print to output
    int type = 0;
    readheaderFunction(imageFile, outputFile, type);
    char header[sizeof(Header.Type)];
    memcpy(header, &Header.Type, sizeof(Header.Type));
    fprintf(outputFile, "Header.Type = %s\n", header);
    fprintf(outputFile, "Header.Size = %d\n", Header.Size);
    fprintf(outputFile, "Header.Offset = %d\n", Header.Offset);
    fprintf(outputFile, "InfoHeader.Size = %d\n", InfoHeader.Size);
    fprintf(outputFile, "InfoHeader.Width = %d\n", InfoHeader.Width);
    fprintf(outputFile, "InfoHeader.Height = %d\n", InfoHeader.Height);
    fprintf(outputFile, "InfoHeader.Planes = %d\n", InfoHeader.Planes);
    fprintf(outputFile, "InfoHeader.Bits = %d\n", InfoHeader.Bits);
    fprintf(outputFile, "InfoHeader.Compression = %d\n", InfoHeader.Compression);
    fprintf(outputFile, "InfoHeader.ImageSize = %d\n", InfoHeader.ImageSize);
    fprintf(outputFile, "InfoHeader.xResolution = %d\n", InfoHeader.xResolution);
    fprintf(outputFile, "InfoHeader.yResolution = %d\n", InfoHeader.yResolution);
    fprintf(outputFile, "InfoHeader.Colors = %d\n", InfoHeader.Colors);
    fprintf(outputFile, "InfoHeader.ImportantColors = %d\n", InfoHeader.ImportantColors);
    
    // calculate bytes of padding per row of pixels
    int padding = paddingFunction();
    fprintf(outputFile, "Padding = %d\n", padding);

    // read indivdual bytes of header
    headerbytesFunction(imageFile, outputFile);

    // read each pixels RGB values
    rgbFunction(imageFile, outputFile, padding);

    fclose(imageFile);
    fclose(outputFile);
}

void readheaderFunction(FILE *imageFile, FILE *outputFile, int type){
    // read magic type
    fseek(imageFile, 0x00, SEEK_SET);
    fread(&Header.Type, 2, 1, imageFile);
    if(type == 1) fwrite(&Header.Type, 2, 1, outputFile);

    // read size
    fseek(imageFile, 0x02, SEEK_SET);
    fread(&Header.Size, 4, 1, imageFile);
    if(type == 1) fwrite(&Header.Size, 4, 1, outputFile);

    // read reserved1
    fseek(imageFile, 0x06, SEEK_SET);
    fread(&Header.Reserved1, 2, 1, imageFile);
    if(type == 1) fwrite(&Header.Reserved1, 2, 1, outputFile);

    // read reserved2
    fseek(imageFile, 0x08, SEEK_SET);
    fread(&Header.Reserved2, 2, 1, imageFile);
    if(type == 1) fwrite(&Header.Reserved2, 2, 1, outputFile);

    // read offset
    fseek(imageFile, 0x0A, SEEK_SET);
    fread(&Header.Offset, 4, 1, imageFile);
    if(type == 1) fwrite(&Header.Offset, 4, 1, outputFile);

    // read info header
    fread(&InfoHeader, sizeof(InfoHeader), 1, imageFile);
    if(type == 1) fwrite(&InfoHeader, sizeof(InfoHeader), 1, outputFile);
}

int paddingFunction(void){
    // calculate bytes of padding per row of pixels
    int pad, B_per_Row = (InfoHeader.Width * 3);
    if((B_per_Row % 4) != 0){
        B_per_Row += 4 - (B_per_Row % 4);
    }
    pad = B_per_Row - (InfoHeader.Width * 3);
    return pad;
}

void headerbytesFunction(FILE *imageFile, FILE *outputFile){
    // back to start of file, read bytes up to header offset
    rewind(imageFile);
    int Byte;
    for(int i = 0; i < Header.Offset; i++){
        Byte = fgetc(imageFile);
        fprintf(outputFile, "Byte[%d] = %03d\n", i, Byte);
    }
}

void rgbFunction(FILE *imageFile, FILE *outputFile, int padding){
    // number of columns and rows (columns = 3 bytes per pixel)
    int column = (InfoHeader.Width * 3) + padding;
    int row = InfoHeader.Height;

    // read bytes containing pixel RGB values
    int red, green, blue, padbytes;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j = j + 3){
            // if at end of rgb values
            if(j == column - padding){
                fprintf(outputFile, "Padding[%d] = ", i);
                for(int k = 0; k < padding; k++){
                    if(k > 0){
                        fprintf(outputFile, ".");
                    }
                    padbytes = fgetc(imageFile);
                    fprintf(outputFile, "%03d", padbytes);
                }
                fprintf(outputFile, "\n");
            }
            // get rgb values (backwards)
            else{
                blue = fgetc(imageFile);
                green = fgetc(imageFile);
                red = fgetc(imageFile);
                fprintf(outputFile, "RGB[%d,%d] = %03d.%03d.%03d\n", i, j/3, red, green, blue);
            }
        }
    }
}

void edgeFunction(FILE *imageFile, char *imageName, FILE *outputFile){
    // matrix for edge filter
    char Matrix[3][3] = {
        {  0, -1,  0 },
        { -1,  4, -1 },
        {  0, -1,  0 }
    };

    // create output file named inputName-edge.bmp
    char *dotIndex = strchr(imageName, '.');
    *dotIndex = '\0';
    strcat(imageName, "-edge.bmp");
    outputFile = fopen(imageName, "wb");

    // read and write header data
    int type = 1;
    readheaderFunction(imageFile, outputFile, type);

    // variables for ease
    int width = InfoHeader.Width;
    int height = abs(InfoHeader.Height);

    // allocate mem for array of pixel values
    Pixel(*originalArray)[width] = calloc(height, width * sizeof(Pixel));
    Pixel(*pixelArray)[width] = calloc(height, width * sizeof(Pixel));

    // calc padding
    int padding = (4 - (width * sizeof(Pixel)) % 4) % 4;

    // create array of original pixel values to filter
    for (int i = 0; i < height; i++){
      fread(originalArray[i], sizeof(Pixel), width, imageFile);
      fseek(imageFile, padding, SEEK_CUR);
    }
    
    // apply filter to original pixel values
    int newRed, newGreen, newBlue;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1){
                // apply filter to each rgb value
                newBlue = (originalArray[i-1][j-1].Blue * Matrix[0][0]) + (originalArray[i-1][j].Blue * Matrix[0][1]) + (originalArray[i-1][j+1].Blue * Matrix[0][2]) + (originalArray[i][j-1].Blue * Matrix[1][0]) + (originalArray[i][j].Blue * Matrix[1][1]) + (originalArray[i][j+1].Blue * Matrix[1][2]) + (originalArray[i+1][j-1].Blue * Matrix[2][0]) + (originalArray[i+1][j].Blue * Matrix[2][1]) + (originalArray[i+1][j+1].Blue * Matrix[2][2]);
                newGreen =(originalArray[i-1][j-1].Green * Matrix[0][0]) + (originalArray[i-1][j].Green * Matrix[0][1]) + (originalArray[i-1][j+1].Green * Matrix[0][2]) + (originalArray[i][j-1].Green * Matrix[1][0]) + (originalArray[i][j].Green * Matrix[1][1]) + (originalArray[i][j+1].Green * Matrix[1][2]) + (originalArray[i+1][j-1].Green * Matrix[2][0]) + (originalArray[i+1][j].Green * Matrix[2][1]) + (originalArray[i+1][j+1].Green * Matrix[2][2]);
                newRed =(originalArray[i-1][j-1].Red * Matrix[0][0]) + (originalArray[i-1][j].Red * Matrix[0][1]) + (originalArray[i-1][j+1].Red * Matrix[0][2]) + (originalArray[i][j-1].Red * Matrix[1][0]) + (originalArray[i][j].Red * Matrix[1][1]) + (originalArray[i][j+1].Red * Matrix[1][2]) + (originalArray[i+1][j-1].Red * Matrix[2][0]) + (originalArray[i+1][j].Red * Matrix[2][1]) + (originalArray[i+1][j+1].Red * Matrix[2][2]);
                
                // place new pixel values into new pixel array
                pixelArray[i][j].Blue = newBlue;
                pixelArray[i][j].Green = newGreen;
                pixelArray[i][j].Red = newRed;
            }
            
            else{
                pixelArray[i][j].Blue = 0;
                pixelArray[i][j].Green = 0;
                pixelArray[i][j].Red = 0;
            }
        }
    }

    // write pixel data to outputFile
    for(int i = 0; i < height; i++){
        for (int k = 0; k < padding; k++){
            fputc(0x00, outputFile);
        }
        fwrite(&(pixelArray[i]), sizeof(Pixel), width, outputFile);
    }

    fclose(imageFile);
    fclose(outputFile);
    free(originalArray);
    free(pixelArray);
}