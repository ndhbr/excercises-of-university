#include <stdio.h>

int main(int argc, char *argv[]) {
	int summe = 0, eingabe = 0;

	while(scanf("%d", &eingabe)) {
		summe += eingabe;

		printf("Neue Summe: %d\n", summe);
	}
}
