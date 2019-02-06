#include <stdio.h>
#include <stdlib.h>
#ifndef _TREE_FUNCTIONS_H
#include "tree_functions.h"
#endif

int main(int argc, char* argv[]) {
    int mitte = 0;
    int astreihen = 0;
    int i;

    if(argc != 2) {
        printf("Verwendung: ./tree.exe <ASTREIHEN>");
        return 1;
    }

    astreihen = atoi(argv[1]);
    mitte = (astreihen * 2) + 8;

    for(i = 0; i < astreihen; i++) {
        astreiheAusgeben(mitte, 1 + (i*2));
        astreiheAusgeben(mitte, 3 + (i*2));
        astreiheAusgeben(mitte, 5 + (i*2));
    }

    stumpfAusgeben(mitte);
    return 0;
}