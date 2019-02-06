#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    char buf[11];

    f = fopen("test.txt", "r");

    //fprintf(f, "Hallo Welt.\n");

    //int len = fread(buf, sizeof(char), 10, f);
    fgets(buf, 10, f);
    fseek(f, 13, SEEK_SET);

    printf("Buf: %s\n", buf);

    fclose(f);
    return 0;
}