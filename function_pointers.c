#include <stdio.h>
#include <stdlib.h>

void funktion_ausfuehren(int (int, int), int, int);
int sub(int, int);
int add(int, int);

int main(int argc, char* argv[]) {
    funktion_ausfuehren(sub, 3, 8);
    funktion_ausfuehren(add, 3, 8);

    return 0;
}

void funktion_ausfuehren(int methode(int, int), int a, int b) {
    printf("Ergebnis: %d\n", methode(a, b));
}

int sub(int a, int b) {
    return a - b;
}

int add(int a, int b) {
    return a + b;
}