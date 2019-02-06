#include <stdio.h>

void fillWithPrimes(int* buffer, int len) {
    int i, j, counter = 2;

    buffer[0] = 1;
    buffer[1] = 2;
    
    for(i = 3; i < len; i++) {
        if(counter < len) {
            for(j = 2; j < i; j++) {
                if(i % j == 0) {
                    break;
                }
            }

            printf("i: %d, j: %d\n", i, j);

            if(i % (j-1) != 0) {
                buffer[counter] = i;
                counter++;
            }
        }
    }
}
