/*
------------------------------------------------------------------------------------------
File:    huffman.c
Project: huffmancode
Purpose: 
==========================================================================================

Program Description:
    CP 264 Huffman Coding
This file contains the main program 
and user interface for running your Huffman Encoder/Decoder. 
------------------------------------------------------------------------------------------
Authors:  Memet Rusidovski, Vibeesshanan Thevamanoharan, Tyler Dezeeuw, Arif Omogbolahan Ashogbon, Alexander Schwarze
User ID: rusi1550, thev0240, deze3010, asho0840, schw6340
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BST.h"

void encode(char *inputFile, char *outputFile){
    encodeFile(inputFile, outputFile);
}

void decode(char *inputFile, char *outputFile){
    decodeFile(inputFile, outputFile);
}

/*int main(void){
    //setbuf(stdout, NULL);

    //encode("medium.txt", "savefile.dat");

    decode("savefile.dat", "medium_copy.txt");

}*/


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr,
                "USAGE: ./main [encode | decode] "
                "<input file> <output file>\n");
        return 0;
    }

    int i = 0;


    if (strcmp(argv[1], "encode") == 0)
        encode(strdup(argv[2]), strdup(argv[3]));
    else if (strcmp(argv[1], "decode") == 0)
        decode(strdup(argv[2]), strdup(argv[3]));
    else
        fprintf(stderr,
                "USAGE: ./huffman [encode | decode] "
                "<input file> <output file>\n");



    return 0;
}
