#include <stdlib.h>
#include "AsciiArtTool.h"
#include "RLEList.h"

RLEList asciiArtRead(FILE* in_stream)
{   
    if(!in_stream)
    {
        return NULL;
    }
    RLEList rleAscii = RLEListCreate();
    char currentChar = ' ';

    do
    {
        currentChar = (char)fgetc(in_stream);
        if (feof(in_stream))
        {
            break;
        }
        RLEListAppend(rleAscii, currentChar);
    } while (1);

    return rleAscii;
}

RLEListResult asciiArtPrint(RLEList list, FILE* out_stream)
{
    if(!list || !out_stream)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    int sizeOfList = RLEListSize(list);
    char currChar = '\0';
    for(int i = 0; i < sizeOfList; i++)
    {
        currChar = RLEListGet(list, i, NULL);
        if(fputc(currChar, out_stream) < 0)
        {
            printf("asciiArtPrint Failed to write");
        }
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if(!list || !out_stream)
    {
        return RLE_LIST_NULL_ARGUMENT;
    }

    char* rleString = RLEListExportToString(list,NULL);
    fputs(rleString, out_stream);
    free(rleString);
    return RLE_LIST_SUCCESS;
}