/*
                        ESPERANZA MACARENA PLAZA MARTINEZ
                        Nº de matricula: br0427
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int num, count;

    printf("Escriba el numero entre 0 y 255 que quiera convertir a binario: ");
	scanf("%d", &num);
	if (num >= 0 && num <= 255){
        do {
            printf("bit %d: %d\n", count, num % 2);
            num /= 2;
			count++;
        } while (num > 0);
	} else {
		printf("EL numero no esta en el rango\n");
	}
	return 0;
}






















/*Usando mascaras y manejo de bits
#include <stdio.h>

int main() {	
	int n, c, k;
	
	printf("Ingresa el número decimal: ");
	scanf("%d", &n);
	
	printf("%d en binario es: ", n);
	
	for (c=7;c>=0;c--){
		k = n>>c;
		if (k&1){
			printf("1");
		}else {
			printf("0");
		}
	}	
	printf("\n");	
	return 0;
}
*/