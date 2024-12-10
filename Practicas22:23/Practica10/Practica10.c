/*
ESPERANZA MACARENA PLAZA MARTINEZ
NUMERO DE MATRICULA: BR0427
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 20
#define N 11

//Prototipos
void rellenar(char mat[M][N]);
void imprimir (char mat[M][N]);
int comparar(char mat1[N], char mat2[N]);
void masAntigua(char mat[M][N]);

int main(){

    char matriculas[M][N];

    //Genera una semilla aleatoria
    srand(time(NULL));

    rellenar(matriculas);
    imprimir(matriculas);
    printf("\n\n\n");
    masAntigua(matriculas);


}

void rellenar(char mat[M][N]){
    for(int i = 0; i < M; i++){
        mat[i][0] = 'E';
        mat[i][1] = '-';
        for(int j = 0; j < N; j++){
            if(j > 1 && j < 6){
                mat[i][j] = rand() % ('9' - '0') + '0';
            }
            else if(j > 6 && j < 10){
                mat[i][j] = rand() % ('Z' - 'A') + 'A';
            } 
        mat[i][6] = '-';
        mat[i][10] = '\0';
        }
    }
}


void imprimir(char mat[M][N]){
    for(int i = 0; i < M; i++){
        printf("%s\n", mat[i]);
    }
}


int comparar(char matricula1[N], char matricula2[N]){
    int n = strcmp(matricula1 + 7, matricula2 + 7);
    
    return n ? n : strncmp(matricula1 + 2, matricula2 + 2, 4);
}

void masAntigua(char matriz[M][N]){
    char matriculaAux = matriz[0]; 

    for(int i = 1; i < M; i++){
        if(comparar(matriz[i], matriculaAux) < 0){
            matriculaAux = matriz[i];
        }
    printf("\nLa matricula mas antigua es: %c\n", matriculaAux);
    }
}



