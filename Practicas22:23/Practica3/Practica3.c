/*
                        ESPERANZA MACARENA PLAZA MARTINEZ
                        Nº de matricula: br0427
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int count = 0;
    int num;
    float decimal = 0.0;

    do{
        printf("Parte entera del numero: ");
        fflush(stdin);
        scanf("%d", &num);
        
        //Parte entera
        while(num > 0) {
            if(10 * (((float) num / 2) - (num / 2)) >= 5){
                printf("bit %d = 1\n", count);
            } else {
                printf("bit %d = 0\n", count);
            }
            num /= 2;
            count++;
        }

        //parte decimal
        count = 0;
        printf("Parte decimal del numero: ");
        fflush(stdin);
        scanf("%f", &decimal);
        while(decimal != 0.0){
            if((int) (decimal * 2) != 0){
                printf("bit %d = 1\n", count);
            } else{
                printf("bit %d = 0\n", count);
            }
            decimal = decimal * 2 - ((int) (decimal * 2));
            count++; 
        }
    }while (num <= 0.0 && num >= 255.0);



    return 0;
}
