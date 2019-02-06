void astreiheAusgeben(int mitte, int breite) {
    int i;

    for(i = 0; i < (mitte - (breite/2)); i++) {
        printf(" ");
    }

    for(i = 0; i < breite; i++) {
        printf("*");
    }

    printf("\n");
}

void stumpfAusgeben(int mitte) {
    int i;
    
    for(i = 0; i < (mitte-2); i++) {
        printf(" ");
    }

    printf("| | |\n");
}