#include <stdio.h>

int main() {
	char name[8];
		
	printf("Wie ist dein Name?\n");
	scanf("%s", name); 

	printf("Hallo %s", name);

	return 0;
}
