#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc == 4) {
		double ergebnis;

		switch(argv[2][0]) {
			default:
			case '+':
				ergebnis = atoi(argv[1]) + atoi(argv[3]);
				break;
			case '-':
				ergebnis = atoi(argv[1]) - atoi(argv[3]);
				break;
			case '*':
				ergebnis = atoi(argv[1]) * atoi(argv[3]);
				break;
			case '/':
				ergebnis = atoi(argv[1]) / atoi(argv[3]);
				break;
		}

		printf("Das Ergebnis lautet: %lf\n", ergebnis);
		return 0;
	} else {
		printf("Keine Rechnung angegeben.\n");
		return 1;
	}
}
