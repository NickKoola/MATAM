#include <stdio.h>
#include <string.h>

#include "AsciiArtTool.h"
#include "RLEList.h"

#define CHUNK_SIZE 2
typedef enum
{
    SUCCESS, 
    ERROR
} Status;

void error(char* message) 
{
	fprintf(stderr,"%s\n", message);
}

Status writeInverted(FILE* in_stream, FILE* out_stream)
{
    char buffer[CHUNK_SIZE];
    while (fgets(buffer, CHUNK_SIZE,in_stream) != NULL)
    {
        if(buffer[0] == '@')
        {
            buffer[0] = ' ';
        }
        else if(buffer[0] == ' ')
        {
            buffer[0] = '@';
        }
        fputs(buffer, out_stream);
    }
    return SUCCESS;
}

Status writeEncoded(FILE* in_stream, FILE* out_stream)
{
    RLEList asciiRleList = asciiArtRead(in_stream);
    if(!asciiRleList)
    {
        return ERROR;
    }
    asciiArtPrintEncoded(asciiRleList, out_stream);
    RLEListDestroy(asciiRleList);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        error("Usage: ./AsciiArtTool <flags> <source> <target>");
        return 1;
    }

    if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1],"-i") != 0)
    {
        error("Flags can only be -i or -e.");
        return 1;
    }

    FILE* in_stream = fopen(argv[2], "r");
    if(!in_stream)
    {
        fclose(in_stream);
        error("Error opening source file.");
        return 1;
    }

    FILE* out_stream = fopen(argv[3], "w");
    if(!out_stream)
    {
        fclose(out_stream);
        error("Error opening target file.");
        return 1;
    }

    if(strcmp(argv[1], "-i") == 0)
    {
        Status writeInvertedStatus = writeInverted(in_stream, out_stream);
        if(writeInvertedStatus == ERROR)
        {
            error("Error writing inverted ascii art.");
        }

    }

    if(strcmp(argv[1], "-e") == 0)
    {
        Status writeEncodedStatus = writeEncoded(in_stream, out_stream);
        if(writeEncodedStatus == ERROR)
        {
            error("Error writing encoded ascii art.");
        }
        
    }
    
    fclose(in_stream);
    fclose(out_stream);

    return 0;
}