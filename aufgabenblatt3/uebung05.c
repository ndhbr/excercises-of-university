#include <stdio.h>
#include <stdlib.h>

double my_sqrt(int);
double my_pow(int, int);

int main(int argc, char *argv[]) {
    printf("2^-3: %lf\n", my_pow(2, -3));
    printf("1^3: %lf\n", my_pow(1, 3));
    printf("5^2: %lf\n", my_pow(5, 2));
    printf("3^3: %lf\n", my_pow(3, 4));
    printf("3^-3: %lf\n", my_pow(3, -3));

    return 0;
}

double my_sqrt(int number) {
    return number;
}

double my_pow(int number, int exponent) {
    int i, negative = 0;
    double result = number;

    if(exponent == 0)
        return 1.0;

    if(exponent < 0) {
        negative = 1;
        exponent = -exponent;
    }

    for(i = 1; i < exponent; i++) {
        result *= number;
    }

    if(negative)
        result = 1 / result;

    return result;
}