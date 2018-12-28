#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char zuSuchendesZeichen, neuesZeichen;
    int aktuellePosition = 0;

    if(argc != 4) {
        printf("Korrekter Aufruf: %s A B \"String\"\n", argv[0]);
        return 0;
    }

    zuSuchendesZeichen = *argv[1];
    neuesZeichen = *argv[2];

    while(argv[3][aktuellePosition] != '\0')
    {
        if(argv[3][aktuellePosition] == zuSuchendesZeichen)
            argv[3][aktuellePosition] = neuesZeichen;

        aktuellePosition++;
    }

    printf("%s\n", argv[3]);
    return 0;
}
