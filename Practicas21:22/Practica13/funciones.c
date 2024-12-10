#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "rotar.h"

void rellenar(char  mat[M][N]) {
    int i= 0;
    int j = 0;

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = randomNum('A', 'Z');
        }
    }
}

void imprimir(char mat[M][N]) {
    int i = 0;
    int j = 0;

    printf("\n");
    for (i = 0; i < M; i++){
        for (j = 0; j < N; j++) {
            printf(" %c ", mat[i][j]);
        }
        printf("\n");
    }
}

void rotar(char mat[M][N]) {
    int i = 0;
    int j = 0;

    for (i = 0; i < M; i++) {
        for(j= 0; j < N; j++) {
            mat[i][j] = ( (mat[i][j] & 3) << 6 ) | (mat[i][j] >> 2);
        }
    }
}

void desrotar (char mat[M][N]) {
    int i = 0;
    int j = 0;

    for (i=0; i<M; i++) {
        for(j=0; j<N; j++) {
            mat[i][j] = ((mat[i][j] & 192) >> 6 ) | (mat[i][j] << 2);
        }
    }
}


void matToFile(char mat[M][N], FILE* fichOut) {
    int i = 0;

    for (i = 0; i < M; i++){
        fputs(mat[i], fichOut);
    }

}

int randomNum(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

