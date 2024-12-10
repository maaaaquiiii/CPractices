/*
PRACTICA REALIZADA POR ESPERANZA MACARENA PLAZA MARTINEZ
NUMERO DE MATRICULA: BR0427
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 11
#define M 40

//Prototipos
int aleatorio(int inf, int sup);
void rellenar(char mat[M][N]);
void imprimir (char mat[M][N]);
int comparar(char *mat1, char *mat2);
void masAntigua(char mat[M][N]);

int main(){

    char matriculas[M][N];
    srand(time(NULL));

    rellenar(matriculas);
    imprimir(matriculas);
    printf("\n\n\n");
    masAntigua(matriculas);


}

int aleatorio(int inf, int sup){
    int aux = inf;
    if (inf > sup){  
        inf = sup;
        sup = aux;
    }
    return (rand() % (sup - inf + 1) + inf);
}

void rellenar(char mat[M][N]){
    int i = 0;
    int j = 0;

    for(i = 0; i < M; i++){
        mat[i][0] = 'E';
        mat[i][1] = '-';
        for(j = 0; j < N; j++){
            if(j > 1 && j < 6){
                mat[i][j] = aleatorio('0', '9');
            }
        mat[i][6] = '-';
            else if(j > 6 && j < 10){
                mat[i][j] = aleatorio('A', 'Z');
            } 
        mat[i][10] = '\0';
        }
    }
}

void imprimir(char mat[M][N]){
    int i = 0;
    int j = 0;

    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

int comparar(char *matricula_1, char *matricula_2){

    int comparation = 0;

    comparation = strcmp(matricula_1 + 7, matricula_2 + 7);
    if(comparation == 0){
        comparation = strncmp(matricula_1 + 2, matricula_2 + 2, 4);
    }
    return comparation;
}

void masAntigua(char matriz[M][N]){

    int i = 0;
    char antiguo[M + 1];
    char matricula[M + 1];

    for(i = 0; i < M; i++){
        matricula[i] = 0;
    }

    strncpy(antiguo,matriz[0], M);
    for(i = 1; i < N; i++){
        strncpy(matricula, matriz[i], M);
        if(comparar(matricula, antiguo) == -1){
            strncpy(antiguo, matricula, M);
        }
    }

    printf("La matricula mas antigua es %s",antiguo);
}

/*
int comparar(char *mat1, char *mat2){
    int comparation = 0;

    comparation = strcmp(mat1 + 7, mat2 + 7);
    if(comparation == 0){
        comparation = strcmp(mat1 + 2, mat2 + 2);
    }

    return comparation;
}

char masAntigua(char mat[M][N]){
    int i = 0;
    char matAntigua[N];
    char matriz[N];

    strncpy(matAntigua, mat[0],N);
    for(i = 0; i < M; i++){
        strncpy(matriz, mat[i],N);
        if(comparar(matriz, mat[i] == -1)){
            strncpy(matAntigua, mat, N);
        }
    }
    printf("La matricula mas antigua es: %s", matAntigua);
}
*/


