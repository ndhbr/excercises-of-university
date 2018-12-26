#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 100

typedef struct {
    char nachname[MAX_NAME_SIZE];
    char vorname[MAX_NAME_SIZE];
    int alter;
    char geschlecht;
} person;

person *personen = NULL;

void printPersonen(int);

int main(int argc, char *argv[])
{
    FILE *file;
    char buf[1024];

    char *delimiter = ";";
    char *ptr;
    int i, a = 0;

    file = fopen("personen.csv", "r");

    fgets(buf, 1024, file);

    while(fgets(buf, 1024, file))
    {
        ptr = strtok(buf, delimiter);

        if(personen == NULL)
            personen = (person*) calloc(1, sizeof(person));
        else
            personen = (person*) realloc(personen, (a+1)*sizeof(person));
        
        strcpy(personen[a].nachname, ptr);
        ptr = strtok(NULL, delimiter);

        strcpy(personen[a].vorname, ptr);
        ptr = strtok(NULL, delimiter);

        personen[a].alter = atoi(ptr);
        ptr = strtok(NULL, delimiter);

        personen[a].geschlecht = *ptr;
        ptr = strtok(NULL, delimiter);

        a++;
    }

    printPersonen(a);

    return 0;
}

void printPersonen(int numberOfPersons)
{
    int i;

    for(i = 0; i < numberOfPersons; i++)
    {
        printf("Nachname: %s, Vorname: %s, Alter: %d, Geschlecht %c\n",
            personen[i].nachname, personen[i].vorname, personen[i].alter,
            personen[i].geschlecht);
    }
}