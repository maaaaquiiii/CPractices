/*
                        ESPERANZA MACARENA PLAZA MARTINEZ
                        Nº de matricula: br0427
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int base, exponente, potencia, i, j, count = 0;
    char opcion = '\0', continuar;
        
    do {
        do {
            printf ("Escriba la base [2-10]: ");
            fflush(stdin);
            scanf ("%d", &base);
        } while(base < 2 || base > 10);
        do {
            printf ("Escriba el exponente [0-10]: ");
            fflush(stdin);
            scanf("%d", &exponente);
        } while(exponente < 0 || exponente > 10);
        printf ("Desea modificar la base y el exponente (S/N): ");
        fflush(stdin);
        scanf ("%c", &opcion);
    } while(opcion != 'N');

    //For para hacer las potencias

    for(i = 0; i <= exponente; i++) {
        potencia = 1;
        for (j = 1; j <= i; j++) {
            potencia *= base;
        }
        printf ("\n");
        printf ("%d^%d = %d\n", base, i, potencia);

        //Pasar a binario

        do {
            printf("bit %d: %d\n", count, potencia % 2);
            potencia /= 2;
            count++;
        } while (potencia > 0);
        count = 0;
        printf("Desea coninuar? ");
        getchar();
        fflush(stdin);
        printf ("\n");
    }

    return 0;
}