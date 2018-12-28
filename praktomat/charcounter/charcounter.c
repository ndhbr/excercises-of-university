#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int buchstabenZaehler[26] = {0};
    int aktuellerZaehler = 0;
    int i = 0;

    if(argc != 2)
    {
        printf("Syntax: PROGRAMMNAME \"SATZ\"\n");
        return 1;
    }

    while(argv[1][aktuellerZaehler] != '\0')
    {
        if(argv[1][aktuellerZaehler] >= 65 && argv[1][aktuellerZaehler] <= 90)
            argv[1][aktuellerZaehler] += 32;

        if(buchstabenZaehler[argv[1][aktuellerZaehler] - 97] > 0)
            buchstabenZaehler[argv[1][aktuellerZaehler] - 97] += 1;
        else
            buchstabenZaehler[argv[1][aktuellerZaehler] - 97] = 1;

        aktuellerZaehler++;
    }

    for(i = 0; i < 26; i++)
    {
        if(buchstabenZaehler[i] > 0)
            printf("%c: %d\n", i+65, buchstabenZaehler[i]);
    }

    return 0;
}