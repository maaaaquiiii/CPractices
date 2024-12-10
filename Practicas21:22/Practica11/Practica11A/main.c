#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    FILE_ERROR
} F_ERROR;

typedef struct {
    char id[11];
    unsigned n[6];
} APUESTA;

int randomNum(int, int);
void crearID(char [11]);
void crearNum(int [6]);
void crearApuesta(APUESTA*);
void crearFapuestas(const char *, unsigned);

int main(void) {
    char fichName[20];
    int bets;


    srand(time(NULL));
    printf("\nDonde quieres guardar las apuestas?:");
    gets(fichName);

    printf("\nCuantas apuestas quieres generar?:");
    scanf("%d", &bets);
    fflush(stdin);
    

    printf("\nEl tamaño del archivo va a ser %.9fmb Seguir? (S/N): ", (sizeof(APUESTA)/1000000.f));
    if (toupper(getchar()) != 'S') {
        return 1;
    }

    crearFapuestas(fichName, bets);
    return 0;
}


/*
Genera un numero aleatoriamente
*/
int randomNum(int num1, int num2) {
    return (rand() % (num2 - num1 + 1) + num1);
}

//Se crea el identificador a paritr de una cadena de caracteres, en la que se va añadiendo lo que se necesita en la posicion necesaria

void crearID(char id[11]) {
    int i;
    id[0] = '2';
    id[1] = '8';
    for(i = 2; i < 10; i++) {
        id[i] = randomNum('0', '9');
    }
    id[10] = randomNum('A', 'Z');
    id[11] = '\0';
}

//Se genera la combinacion ganadora para la loteria, a partir de una matriz

void crearNum(int num[6]) {
    int i = 0;
    int j = 0;
    
    for (i = 0; i < 6; ) {
        num[i] = randomNum(1, 49);
        for (j = 0; j < i && num[j] != num[i]; j++) {
            if (j == i) {
            i++;   
            }
        }
    }
}

//Se crea la apuesta a partir del in¡dentiifcador y del numero

void crearApuesta(APUESTA* ap) {
    crearID(ap -> id);
    crearNum(ap -> n);
}

//Para crear las apuestas se abre un fichero para escribir en el las apuestas jugadas

void crearFapuestas(const char * fichName, unsigned ap){
    int i;
    FILE* fichIn;
    APUESTA
    if(!(fichIn = fopen(fichName, "wb"))) {
        printf("Error en la apertura de fichero");
        return 0;
    }
    else {
        for(i = 0; i < ap; i++) {
            crearApuesta(&ap);
            fwrite(&ap, sizeof(APUESTA), 1, fichIn);
        }
    }
    fclose(fichIn);
}

