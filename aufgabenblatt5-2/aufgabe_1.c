#include <stdio.h>

#ifndef _TOOLS_H
#include "tools.h"
#endif

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    int primes[100];

    fillWithPrimes(primes, 100);
    //f = fopen("aufgabe_3.txt", "wb");

    //fwrite(primes, sizeof(int), 100, f);

    return 0;
}