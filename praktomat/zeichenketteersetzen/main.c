#include <stdio.h>
#include <string.h>

char *suche(char *str, char *such, unsigned int n)
{
    int position = 0;
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

    return NULL;
}