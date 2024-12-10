#include <stdio.h>

//Practica 1, programa 1
/* REALIZADO POR: Esperanza Macarena Plaza Martínez
MATRICULA: br0427*/

#include<stdio.h>
int main(){
    //Declaracion de variables int num = 0;
    int resto = 0;
    int invertido = 0;
    int seg = 0;
    int min = 0;
    int hora = 0;


    //pedir numero por pantalla printf("Introduce un numero: "); scanf("%d", &num);
    //Formato hora seg = num % 60; min = num / 60; hora = min / 60;

    if(min > 60){
        min = min % 60;
    } 
    else{
        min = min; }
    if(hora > 23){
        hora = hora / 24;
    } 
    else{
        hora = hora; 
    }
    printf("%02u:%02u:%'2u\n", hora, min, seg);


    //Inverso

    resto = num % 10;
    invertido = invertido + resto; resto = num / 10;
    num = num / 10;
    resto = num % 10;    
    invertido = invertido * 10 + resto; printf("El numero es: %d\n", invertido); return 0;
}