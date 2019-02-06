#include <stdio.h>
#include <string.h>

int main() {
    char test[] = "Hallo";
    char temp[32];

    test[5] = 'c';
    test[6] = 'b';
    test[9] = 'h';

    strcpy(temp, test);

    printf("%s\n", temp);

    return 0;
}