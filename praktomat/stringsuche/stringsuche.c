#include <stdio.h>
#include <string.h>
/*
char *suche(char *, char *, unsigned int);

int main(int argc, char *argv[])
{
    printf("%s\n", suche("dreierleieierei", "ei", 1)); // ergibt: eierleieierei
    printf("%s\n", suche("dreierleieierei", "ei", 3)); // ergibt: eierei
    printf("%s\n", suche("dreierleieierei", "ei", 4)); // ergibt: ei
    printf("%s\n", suche("barbara macht barbarei", "arba", 2)); // ergibt: arbarei
    if(suche("barbara macht barbarei ", "asdf", 1) == NULL)
        printf("nicht vorhanden!\n"); // sollte ausgegeben werden, da es nicht vorkommt
    if(suche("barbara macht barbarei ", "barba", 3) == NULL)
        printf("nicht vorhanden!\n"); // sollte ausgegeben werden, da es nur 2-mal vorkommt

    return 0;
}*/

char *suche(char *str, char *such, unsigned int n)
{
    int zaehler = 0;
    char *part = str;

    while(zaehler < n)
    {
        part = strstr(part+1, such);
        
        if(!part)
            break;
    
        zaehler++;
    }

    return &part[0];

    /*int position = 0;
    int zaehler = 0;
    int finden = 0;
    size_t such_len = strlen(such);

    while(str[position] != '\0')
    {
        if(str[position] == such[0] && finden == 0 && such_len > 0)
        {
            finden = 1;
        }

        if(str[position] == such[finden] && finden > 0 && finden < such_len)
        {
            finden++;
        }

        if(str[position] == such[such_len-1] && finden > 0 && finden == such_len)
        {
            zaehler++;
            finden = 0;

            if(zaehler == n)
            {
                return &str[position-such_len+1];
            }
        }

        position++;
    }

    return NULL;*/
}