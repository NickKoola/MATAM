#ifndef HW1_ASCII_ART_TOOL_H
#define HW1_ASCII_ART_TOOL_H
#include <stdio.h>
#include "RLEList.h"

/**
 * asciiArtRead: reads a file and shrinks it's contents using the RLE way 
 * 
 * @param in_stream - a FILE* that holds the contents of the image
 * @return 
 *   a new RLEList that holds the contents of the image
 */
RLEList asciiArtRead(FILE* in_stream);

/**
 * asciiArtPrint: takes and image that is represented by 
 *                      an RLEList and writes it into a file
 * 
 * @param list - the RLE list which we will write into the file
 * @param out_stream - The file that'll recieve the RLE list
 * @return
 *   RLE_LIST_NULL_ARGUMENT if list or out_stream are NULL
 *   RLE_SUCCESS if writing was successful
 */
RLEListResult asciiArtPrint(RLEList list, FILE* out_stream);

/**
 * asciiArtPrintEncoded: 
 * 
 * @param list - the RLE list which holds the contents of the image
 * @param out_stream - a FILE* that we'll write the shrinked image into
 * @return 
 *   RLE_LIST_NULL_ARGUMENT if list or out_stream are NULL
 *   RLE_SUCCESS if writing was successful
 */
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);

#endif