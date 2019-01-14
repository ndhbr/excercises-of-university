#include <stdio.h>
#include <stdlib.h>

int* add(int* a, int* b)
{ 
    int* erg = (int*) malloc(sizeof(int));
    *erg = *a + *b;
    return erg;
}

int main(int argc, char* argv[])
{
    int a = 12, b = 13;
    int* erg = NULL;
    erg = add(&a, &b);
    
    printf("%d + %d = %d\n", a, b, *erg);
    
    free(erg);
    return 0;
}