#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char id[11];
    unsigned n[6];
} APUESTA;


int randomNum(int, int);
void crearNum(unsigned[6]);
void premiar(int[6], const char*);
unsigned acertados(APUESTA, unsigned[6], unsigned[]);


int main(){
    APUESTA bets;
    FILE* fichBets;
    FILE* fichWinners;
    unsigned premiado[6];
    unsigned acc[6];
    char fichBetsName[20];
    char fichWinnersName[20];
    int i = 0;
    int j = 0;

    srand(time(NULL));

    printf("\nDe donde quieres leer las apuestas? :");
    gets(fichBetsName);

    printf("\nDonde quieres guardar los premiados? :");
    gets(fichWinnersName);

    if(!(fichBets = fopen(IN, "rb")))
        exit(1);

    if(!(fichWinners = fopen(OUT, "w")))
        exit(1);

    crear_num(premiado);

    fprintf(fichWinners, "La combinacion ganadora es: ");
    for (i=0; i<6; i++){
        fprintf(fichWinners, "%u ", premiado[i]);
    }
    fprintf(fichWinners, "\n");

    while (fread(&bets, sizeof(APUESTA), 1, fichBets)) {
        if ((j = acertados(bets, premiado, acc)) > 1){
            fprintf(fichWinners, "%s %u: ", bets.id, j);

            for (i = 0; i<6; i++) {
                fprintf(fichWinners, "%2u ", ap.n[i]);
            }
            fprintf(fichWinners, "| ");
            for (i = 0; i<j; i++) {
                fprintf(fichWinners, "%2u ", acc[i]);
            }
            fprintf(fichWinners, "\n");
        }
    }

    fclose(fichWinners);
    fclose(fichBets);
    return 0;
}

int randomNum(int num1, int num2){
    return (rand() % (num2 - num1 + 1) + num1);
}


void crear_num(unsigned num[6]){
    int i = 0;
    int j = 0;

    for (i = 0; i < 6; ) {
        num[i] = randomNum(1, 49);
        for (j = 0; j < i && num[j] != num[i]; j++){
            if (j == i) {
                i++;
            }
        }
    }
}

unsigned acertados(APUESTA bets, unsigned premiado[6], unsigned * acertados) {
    unsigned aciertos = 0;
    int i = 0;
    int j = 0;
    
    for (i = 0; i < 6; i++) {
        for(j = 0; j < 6 && bets.n[i] != premiado[j]; j++) {
            if (j < 6) {
                acertados[aciertos++] = bets.n[i];
            }
        }
    }
    return aciertos;
}
