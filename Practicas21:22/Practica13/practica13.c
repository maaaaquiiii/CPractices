#include <stdio.h>
#include <stdlib.h>
#include "rotar.h"

int main(int argc, char* argv[])
{
    FILE* fichOut;
    char mat[M][N];

    if (argc != 2) {
        printf("ERROR: Maximo dos argumentos");
        return 1;
    }

    if (!(fichOut = fopen(argv[1], "w"))) {
        printf("ERROR: No ha sido posible abrir/crear el fichero");
        return 2;
    }

    rellenar(mat);
    imprimir(mat);
    matToFile(mat, fichOut);
    rotar(mat);
    imprimir(mat);
    matToFile(mat, fichOut);
    desrotar(mat);
    imprimir(mat);
    matToFile(mat, fichOut);

    fclose(fichOut);

    return 0;
}
