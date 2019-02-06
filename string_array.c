#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char hans[5][23];
    
    strcpy(*hans + 23, "Hallo");
    printf("%s\n", hans[1]);

    return 0;
}