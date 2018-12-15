#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *f = NULL;
	char buf[8];
	f = fopen("test", "w");
	strcpy(buf, "Hallooo");

	fwrite(buf, 1, 8, f);

	fclose(f);
}
