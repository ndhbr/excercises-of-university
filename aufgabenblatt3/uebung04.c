#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int counter = 0;

    if(argc != 3) {
        printf("Verwendung: <TEILZEICHENKETTE> <ZEICHENKETTE>\n");
    }

    while(argv[2] != NULL) {
        argv[2] = strstr(argv[2]+1, argv[1]);

        if(argv[2] != NULL)
            counter++;
    }

    printf("Ergebnis: %i\n", counter);

    return 0;
}