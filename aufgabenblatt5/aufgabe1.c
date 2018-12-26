#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *file;

	file = fopen("hello.txt", "w");

	fprintf(file, "Hello World\n");

	fclose(file);

	return 0;
}
