#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAIRS 10
#define KEYVALUE_LEN 32

typedef struct _keyvalue {
    char key[KEYVALUE_LEN];
    char value[KEYVALUE_LEN];
} KeyValue;

struct _keyvalue KeyValuePairs[PAIRS];

void readKeyValuePair(int);
void printKeyValuePairs();

int main(int argc, char *argv[]) {
    int i;

    for(i = 0; i < PAIRS; i++) {
        readKeyValuePair(i);
    }

    printKeyValuePairs();

    return 0;
}

void readKeyValuePair(int index) {
    char tempPair[(KEYVALUE_LEN*2)+1];
    char *secondPart;
    char *delimiter = "=";
    int i;

    printf("Bitte KEY=VALUE eingeben: ");
    scanf("%s", tempPair);

    secondPart = strtok(tempPair, delimiter);
    
    for(i = 0; i < 2; i++) {
        if(i % 2)
            strcpy(KeyValuePairs[index].value, secondPart);
        else
            strcpy(KeyValuePairs[index].key, secondPart);
        
        secondPart = strtok(NULL, delimiter);
    }
}

void printKeyValuePairs() {
    int i;

    for(i = 0; i < PAIRS; i++) {
        printf("Key: %s, Value: %s\n", KeyValuePairs[i].key, KeyValuePairs[i].value);
    }
}