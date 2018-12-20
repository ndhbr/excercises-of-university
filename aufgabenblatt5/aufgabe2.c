#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE *file;
	int primeCount = 0;
	int x = 2, i = 2;

	file = fopen("test_file.txt", "w");

	while(primeCount < 100)
	{
		for(i = 2; i <= x; i++)
		{
			if((x % i) == 0 && x != i)
				break;
			
			if(x == i)
			{
				fprintf(file, "%d\n", x);
				primeCount++;
			}
		}

		x++;
	}

	fclose(file);
	return 0;
}
