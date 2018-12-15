#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *f;
	char buf[16];

	f = fopen("test", "r");

	int len = fread(buf, sizeof(char), 16, f);

	printf("Gelesen (Laenge: %d): %s\n", len, buf); 

	return 0;
}
