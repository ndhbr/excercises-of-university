#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATIENTENANZAHL 4

typedef struct _patient {
    int     nummer;
    char    name[32];
    char    vorname[32];
    char    strasse[64];
    int     postleitzahl;
    char    ort[32];
} patient;

struct _patient patienten[PATIENTENANZAHL];

void readPatientAndAddToPatienten(patient*, int);
void seedPatienten();
void sortPatienten();
void printPatientenNummer();

int main(int argc, char* argv[]) {
    int i;

    /*
    for(i = 0; i < PATIENTENANZAHL; i++) {
        readPatientAndAddToPatienten(&patienten[i], i);
    }*/

    seedPatienten();

    printPatientenNummer();
    sortPatienten();
    printPatientenNummer();

    return 0;
}

void readPatientAndAddToPatienten(patient *p, int num) {
    p->nummer = num;

    printf("Name: ");
    scanf("%s", &p->name);

    printf("Vorname: ");
    scanf("%s", &p->vorname);

    printf("Strasse: ");
    scanf("%s", &p->strasse);

    printf("Postleitzahl: ");
    scanf("%d", &p->postleitzahl);

    printf("Ort: ");
    scanf("%s", &p->ort);
}

void seedPatienten() {
    patienten[0].nummer = 0;
    strcpy(patienten[0].name, "Ziesche");
    strcpy(patienten[0].vorname, "Tim");
    strcpy(patienten[0].strasse, "Galgenbergstrasse");
    patienten[0].postleitzahl = 93057;
    strcpy(patienten[0].ort, "Mainburg");

    patienten[1].nummer = 1;
    strcpy(patienten[1].name, "Huber");
    strcpy(patienten[1].vorname, "Andreas");
    strcpy(patienten[1].strasse, "Limestherme");
    patienten[1].postleitzahl = 93333;
    strcpy(patienten[1].ort, "Goegging");

    patienten[2].nummer = 2;
    strcpy(patienten[2].name, "Butz");
    strcpy(patienten[2].vorname, "Stefan");
    strcpy(patienten[2].strasse, "Ringstrasse");
    patienten[2].postleitzahl = 84076;
    strcpy(patienten[2].ort, "Pfeffenhausen");

    patienten[3].nummer = 3;
    strcpy(patienten[3].name, "Mueller");
    strcpy(patienten[3].vorname, "Christoph");
    strcpy(patienten[3].strasse, "Ringstrasse");
    patienten[3].postleitzahl = 84048;
    strcpy(patienten[3].ort, "Mainburg");
}

void sortPatienten() {
    int i, j;
    char tempName[32];

    for(i = 0; i < PATIENTENANZAHL; i++) {
        for(j = 0; j < PATIENTENANZAHL-1; j++) {
            if(strcmp(patienten[j].name, patienten[j+1].name) > 0) {
                strcpy(tempName, patienten[j].name);
                strcpy(patienten[j].name, patienten[j+1].name);
                strcpy(patienten[j+1].name, tempName);
            }
        }
    }
}

void printPatientenNummer() {
    int i;

    for(i = 0; i < PATIENTENANZAHL; i++) {
        printf("Nummer: %d - Name %s\n", patienten[i].nummer, patienten[i].name);
    }
}

