#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	if(argc == 2) {
		int radius = atoi(argv[1]);
		double flaeche = radius*radius*M_PI;

		printf("Deine Kreisfläche beträgt %lf Äpfel.\n", flaeche);
	} else {
		printf("Kein Radius gegeben.\n");
		return 1;
	}
}
