#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	if(argc == 3) {
		int kathete1 = atoi(argv[1]);
		int kathete2 = atoi(argv[2]); 

		double hypotenuse = sqrt(((kathete1*kathete1) + (kathete2*kathete2)));

		printf("Deine Hypotenuse ist %lf Äpfel lang.\n", hypotenuse);

		return 0;
	} else {
		printf("Du hast keine Kathetenlängen übergeben.\n");
		return 1;
	}
}
