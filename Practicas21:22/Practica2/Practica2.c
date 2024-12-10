#include <stdio.h>

int main()
{
    int px1, py1, px2, py2, length, high;
    int aux1, aux2;
    //Opcional
    int pox1, poy1, pox2, poy2;

    /*
    Se pide dos puntos que esten dentro de la pantalla y mientras que las coordenadas del segundo punto sean menores que las del primero se volveran a pedir
    */
    do{
        printf("Introduce las coordenadas de un punto: ");
        scanf("%d, %d", &px1, &py1);
        do{
            printf("Introduce las coordenadas del segundo punto: ");
            scanf("%d, %d", &px2, &py2);
        } while(px2 < px1 || py2 < py1);

        //Sacamos la longitud y la altura a partir de la segunda coordenada menos la primera

        high = py2- py1; 
        length = px2 - px1;

        //para el area de un rectangulo se multiplica la baase por la altura

        printf("\nEl area del cuadrilatero es: %d", high * length);

        if(length == high) //Si la base es igual a la altura entonces nos encontramos ante y cuadrado
        {
            printf("\nLa figura se trata de un cuadrado\n");
        }
    }while((px1 < 0 || py1 < 0 || px1 > 24 || py1 > 79) || (px2 < 0 ||py2 < 0 || px2 > 24 || py2 > 79));

    //Opcional
    //Se vuelven a pedir otros dos puntos
    printf("\nIntroduce las coordenadas de otro punto: ");
    scanf("%d, %d", &pox1, &poy1);
    printf("Introduce las coordenadas del segundo punto: ");
    scanf("%d, %d", &pox2, &poy2);
    
    //Si el las coordenadas del primer punto es mayor que la del punto original y las del segundo punto son menores que el punto original esta dentro del primer rectangulo

    if((px1 <= pox1 && py1 <= poy1) && (px2 >= pox2 && py2 >= poy2)){
        printf("El segundo rectangulo esta dentro del primero");
    }
    else{
        printf("El segundo rectangulo no esta dentro del primero");
    }
}