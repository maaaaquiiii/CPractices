#include <stdio.h>
#include <stdlib.h>

int main () {
    float precio;
    float resultado;

    printf("Introduzca un precio en euros: ");
    scanf("%f€", &precio);

    if(precio > 10 && precio < 100) {
        resultado = precio - precio * 0.1;
        printf("Como el precio introducido es mayor que 10€, el precio total es de %.2f€", resultado);
    }
    else if (precio > 100) {
        resultado = precio - precio * 0.25;
        printf("Como el precio introducido es mayor que 100€, el precio total es de %.2f€", resultado);
    }
    else {
        printf("Como el precio introducido es menor que 10€ no se aplica ningun descuento, por lo que el precio total es de %.2f€", precio);
    }
}