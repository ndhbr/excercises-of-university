#include <stdio.h>
#include <stdlib.h>

int* add(int* a, int* b) {
    //int* result = (int*)calloc(1, sizeof(int));
    int* result = (int*)malloc(sizeof(int));
    *result = *a + *b;
    return result;
}

int main(int argc, char* argv[]) {
    int a = 28;
    int x = 9;
    int *b = &a;
    int **c = &b;
    int ***d = &c;

    printf("%d\n", ***d);

    int* e = add(&a, &x);
    printf("%d\n", *e);

    free(e);
    return 0;
}