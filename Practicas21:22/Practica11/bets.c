#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char id[9+1];
    //unsigned n[6];
} APUESTA;

APUESTA crearID() {
    APUESTA bets;
    int i;

    bets.id[0] = '2';
    bets.id[1] = '8';
    for(i = 2; i < 8; i++) {
        bets.id[i] = rand() % 10 + '0';
    }
    bets.id[9] = rand () % 26 + 'A';
    bets.id[10] = '\0';

    return bets;
}

int main(void) {
    srand(time(NULL));
    printf("%s\n", crearID().id);

    return 0;
}

