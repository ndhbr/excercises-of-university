#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc == 4) {
		int kredit = 100000;
		int typ = atoi(argv[1]);
		double zinsSatz = atof(argv[2]);
		double maxMonatRate = atoi(argv[3]);

		kredit += kredit * (zinsSatz/100);

		if(typ == 1) {
			double anzahlMonate = kredit / maxMonatRate;
			printf("Anzahl Monate: %lf\n", anzahlMonate);
		} else if(typ == 0) {
			double anzahlJahre = kredit / maxMonatRate / 12;
			printf("Anzahl Jahre: %lf\n", anzahlJahre);
		} else {
			return 1;
		}
	}

	return 0;
}
