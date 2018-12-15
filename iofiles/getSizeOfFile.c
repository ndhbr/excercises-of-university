#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

struct stat statistics;

int main(int argc, char* argv[])
{
	char *filename = "test";

	if(stat(filename, &statistics))
	{
		printf("Fehler bei stat aufgetreten\n");
		return 2;
	}

	printf("Die Datei hat %lld Bytes\n", statistics.st_size);

	return 1;
}
