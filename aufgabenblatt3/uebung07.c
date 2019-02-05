#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPronouncedString(const int);
int convertThousandToString(const int, char *);

char *oneToNine[] = {
    "ein",
    "zwei",
    "drei",
    "vier",
    "fünf",
    "sechs",
    "sieben",
    "acht",
    "neun"
};

char *singleOne = "eins";

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Fehler: Brauche Eingabezahl.\n");
        return 1;
    }

    int input = atoi(argv[1]);

    char *test = calloc(1, sizeof(char));

    int result = convertThousandToString(1, test);

    if(result == 0)
        printf("%s\n", test);
    else
        printf("Fehler %d\n", result);
    //printPronouncedString(input);

    free(test);

    return 0;
}

void printPronouncedString(const int num) {
    int thousand;
    int currentLen = 1;
    int newLength;
    char *finalString = calloc(currentLen, sizeof(char));

    printf("final\n");

    thousand = num / 1000;
    printf("final\n");

    //printf("%s", convertThousandToString(1000));

    /*newLength = 

    if(realloc(finalString, currentLen+(int)strlen(convertThousandToString(thousand))) == NULL) {
        printf("Fehler: Zu wenig Arbeitsspeicher.\n");
    }

        printf("final\n");

    strcpy(finalString, convertThousandToString(thousand));

    printf("Konvertiert in: %s\n", finalString);*/

    free(finalString);
}

int convertThousandToString(const int num, char *finalString) {
    int newLength;

    if(num == 0 || num < 0 || num > 9)
        return 1;

    printf("%s\n", strcat(oneToNine[num-1], "tausend"));

    newLength = sizeof(char) * strlen(strcat(oneToNine[num-1], "tausend")) + 1;
    printf("New length: %d\n", newLength);
    if(realloc(finalString, newLength) == NULL)
        return 2;

    strcpy(finalString, strcat(oneToNine[num-1], "tausend"));
    return 0;
}