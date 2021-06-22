#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Common Data Types
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;

// Function declarations
bool is_jpeg_start(BYTE *b, int size);
void write_jpeg(FILE *fname, BYTE *data, int size);
FILE *create_jpeg(int fnumber);

// Main program function
int main(int argc, char *argv[])
{
//    if (argc != 2)
//    {
//        printf("Correct usage: recover <filename>\n");
//        return 1;
//    }
    int chunk =  512;
    int fnumber = 0;
    char *input_fname = "card.raw";
    FILE *input_f = fopen(input_fname, "r");      // input file pointer
    FILE *output_f = NULL;
    int readbytes;

    do 
    {
        BYTE *buffer = malloc(chunk * sizeof(BYTE));         // buffer
        if (buffer == NULL)
        {
            printf("Not enough memory\n");
            return 1;
        }
        readbytes = fread(buffer, sizeof(BYTE), chunk, input_f);
        if (readbytes != 512)
        {
            free(buffer);
            break;
        }
        if (is_jpeg_start(buffer, chunk))
        {
            if (output_f != NULL)
            {
                fclose(output_f);
            }
            output_f = create_jpeg(fnumber);
            fnumber++;
        }
        if (output_f != NULL)
        {
            write_jpeg(output_f, buffer, chunk);
        }
        free(buffer);
    }
    while (readbytes == chunk);
    fclose(output_f);
    fclose(input_f);
}

// Check if an array is the beginning of a jpeg checking first 3 bytes
bool is_jpeg_start(BYTE *b, int size)
{
    if (b[0] == 0xff)
    {
        if (b[1] == 0xd8 & b[2] == 0xff & (b[3] & 0xf0) == 0xe0)
        {
            return true;
        }
    }
    return false;
}

// Create a new JPEG file to start writing, returns pointer
FILE *create_jpeg(int fnumber)
{
    char *fname = malloc(8 * sizeof(char));
    if (fname == NULL)
    {
        printf("Not enough memory\n");
    }
    sprintf(fname, "%03i.jpg", fnumber);
    FILE *output_f = fopen(fname, "w");
    free(fname);
    return output_f;
}

// Write buffer to JPEG file
void write_jpeg(FILE *fname, BYTE *data, int size)
{
    fwrite(data, sizeof(BYTE), size, fname);
}
    
