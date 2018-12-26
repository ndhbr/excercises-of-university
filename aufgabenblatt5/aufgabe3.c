#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *file;
    long primeNumbers[100];
    int i;
    char charBuf[1024];

    file = fopen("aufgabe2.txt", "r");

    if(!file)
    {
        return 1;
    }

    for(i = 0; i < 100; i++)
    {
        fgets(charBuf, 1024, file);
        primeNumbers[i] = atol(charBuf);
    }

    printf("49: %ld\n50: %ld\n51: %ld\n", primeNumbers[48], primeNumbers[49], primeNumbers[50]);

    return 0;
}