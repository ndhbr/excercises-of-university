#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc == 2) {
		int zahl = atoi(argv[1]);		

		printf("Zahl: %d\n", zahl);
	
		if(	(zahl%2 == 0 && zahl != 2) ||
			(zahl%3 == 0 && zahl != 3) ||
			(zahl%5 == 0 && zahl != 5) ||
			(zahl%7 == 0 && zahl != 7) ||
			(zahl%9 == 0 && zahl != 9)) {
			printf("Keine Primzahl.\n");
			return 1;
		} else {
			printf("Ist Primzahl.\n");
			return 0;
		}
	}

	printf("Keine Zahl gegeben.\n");
	return 1;
}
