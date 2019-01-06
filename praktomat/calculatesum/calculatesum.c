#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int len = argc-1;
    int zahlen[len];
    int summe = 0;
    for(int i = 0; i < len; i++) {
        zahlen[i] = atoi(argv[i+1]);
        summe += zahlen[i];
    }

    // Bitte hier den Code zum Ermitteln der Summe eingeben

    printf("Summe: %d\n", summe);
    return 0;
}