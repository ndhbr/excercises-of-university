#include <stdio.h>

int main(void) {
    double result = 0.0;
    double basis = 0.0;
    double exponent = 0.0;

    printf("Basis: ");
	scanf("%lf", &basis);

    printf("Exponent: ");
    scanf("%lf", &exponent);

    if(exponent > 0)
    {
        result = basis;

        for(; exponent > 1; exponent--)
        {
            result *= basis;
        }
    }
    else if(exponent < 0)
    {
        result = basis;
        exponent = -exponent;

        for(; exponent > 1; exponent--)
        {
            result *= basis;
        }

        result = 1 / result;
    }
    else
    {
        result = 1.0;
    }

    printf("Ergebnis: %lf\n", result);
}