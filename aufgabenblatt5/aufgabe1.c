#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *file;

	file = fopen("test_file.txt", "w");

	fprintf(file, "Hello World\n");

	fclose(file);

	return 0;
}
