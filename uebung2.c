#include <stdio.h>

int main() {
	int laenge, breite;

	printf("Länge: ");
	scanf("%d", &laenge);

	printf("Breite: ");
	scanf("%d", &breite);

	printf("------\nFläche: %d\n", (laenge*breite));

	return 0;
}
