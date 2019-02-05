#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *, int);
void decrypt(char *, int);
void printText(char *);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Verwendung: SEED<0-9>+ TEXT<TEXT>\n");
        return 1;
    }

    int seed = atoi(argv[1]);
    char text[64];

    strcpy(text, argv[2]);
    
    printText(text);
    encrypt(text, seed);
    printText(text);
    decrypt(text, seed);
    printText(text);

    return 0;
}

void encrypt(char *text, int seed) {
    int counter = 0;

    while(text[counter] != '\0') {
        text[counter] += seed;
        counter++;
    }
}

void decrypt(char *text, int seed) {
    int counter = 0;

    while(text[counter] != '\0') {
        text[counter] -= seed;
        counter++;
    }
}

void printText(char *text) {
    printf("Gespeicherter Text: %s\n", text);
}