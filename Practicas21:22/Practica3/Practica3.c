#include <stdio.h>

int main(){
    int num = 0;
    int i, j;
    i = j = 0;
    char character;

    //Creas un bucle do while para que al pedir el numero este em el rango de 0 y 10

    do{
        printf("Escriba un numero: ");
        scanf("%d", &num);
    } while(num < 0 || num > 10);

    //Se pide un caracter y en un array bidimensional se rellena con la serie de caracteres a partir del caracter pedido

    printf("Escriba un caracter: ");
    scanf("%c", &character);
    for(i = 0; i < num; i++){
        for(j = 0; j < num; j++){
            printf("%c", character);
        }
        printf("\n");
    }
}