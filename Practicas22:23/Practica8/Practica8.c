#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>
#define maxChars 64
#define B 4

//Prototipos

//Practica 7

void resetear(char []); 
// se resetea el array

void binarioEntera(int, char []);  
// un int se convierte a binario (se almacena en el array)

void binarioFraccionaria(float , char []); 
// un float se convierte a binario (se almacena en el array)

void insertarFinal(char [],char );
// se inserta un char al final del array, desplazando el resto a la izquierda

void printBinario(char []);
// se printa el array con los char del numero binario

int bitsBlanco(char []);
// chars en blanco en el array

int posicionPuntoDecimal (char []);
// posicion en el array de ‘.’

//Practica 8

int longitud(int);  
// función recursiva

float randomReal(); 
// devuelve un número real, calculado aleatoriamente

void realBinario(float ,char []);
// convierte un numero real en base decimal a base binaria, printando el binario

float numeroReal(char []);
// devuelve en base 10 el numero real correspondiente a un binario con parte entera y fraccionaria


int main(){
    char binary[maxChars];
    char numReal[maxChars];
    float real = 0.0;
    float realAux = 0.0;

    srand(time(NULL));

    for(int i = 0; i < B; i++){
        resetear(binary);
        resetear(numReal);
        real = randomReal();
        printf("\nNumero random: %.3f\n", real);
        printf("Numero real %.3f convertido a binario:\n", real);
        realBinario(real, binary);
        printf("\nNumero real recalculado:\n%.3f\n\n", real);
        realAux = numeroReal(numReal);
    }

    return 0;
}

//Definicion de funciones
//Practica 7

void resetear(char binary[]){
    for (int i = 0; i < maxChars; i++){
        binary[i] = ' ';
    }
}

void binarioEntera(int num, char binary[]){
    int i = maxChars - 1;

    while (num > 0){
        if(10 * (((float) num / 2) - (num / 2)) >= 5){
            binary[i--] = '1';
        } else{
            binary[i--] = '0';
        }
        num /= 2;
    }   
}

void binarioFraccionaria(float decimal, char binary[]){
    insertarFinal(binary, '.');
    while(decimal != 0.0){
        if((int) (decimal * 2) != 0){
            insertarFinal(binary, '1');
        } else{
            insertarFinal(binary, '0');
        }
        decimal = decimal * 2 - ((int) (decimal * 2)); 
    }
}

void insertarFinal(char cad[], char car){
	for (int i = 0; i < maxChars - 1; i++){
		cad[i] = cad[i + 1];
	}
	cad[maxChars - 1] = car;
}

void printBinario(char binary[]){
    for(int i = 0; i <= maxChars; i++){
        if(binary[i] != ' '){
            printf("%c", binary[i]);
        }
    }
}

int bitsBlanco(char cad[]){
    int count = 0;
    
    for(int i = 0; i < maxChars; i++){
        if(cad[i] == ' '){
            count++;
        }
    }
    return count;
}

int posicionPuntoDecimal (char cadena[]){
    int posicion = 0;

    for(int i = 0; i < maxChars; i++){
        if(cadena[i] == '.'){
            posicion = i;
        }
    }

    return posicion;
}

//Practica 8

float randomReal(){
    float real = 0.0;
    int parteDecimal = 0;
    int parteEntera = 0;

    srand(time(NULL));
    parteEntera = rand() % 999; //Se genera la parte entera aleatoriamente
    parteDecimal = rand() % 999; //Se genera la parte decimal aleatoriamente
    real = parteEntera + (parteDecimal / pow(10, longitud(parteDecimal)));
    /*
    El numero real se genera sumando la parte entera mas la parte decimal dividiendo el numero, generado por rand(), entre 10 elevado a la longitud del numero
    */

    return real;
}

int longitud(int num){
    if(num == 0){
        return 0; //Si el numero es 0 devuelve 0
    } else{
        return 1 + longitud(num / 10); //Si el numero no es igual a 0 devuelve la suma de 1 mas la funcion con el parametro num dividido entre 10
    }
}

void realBinario(float real,char bitsBinario[]){
    int parteEntera = (int) real;
    float decimal = real - parteEntera;
    
    if(real < 0){
        parteEntera *= -1;  //Si el numero es negativo, multiplica las dos partes por -1
        binarioEntera(parteEntera, bitsBinario); //Convierte la parte entera a binario
        decimal *= -1;
        binarioFraccionaria(decimal, bitsBinario); //Convierte la parte fraccionaria a binario
    } else {
        binarioEntera(parteEntera, bitsBinario);
        binarioFraccionaria(decimal, bitsBinario);
    }
    printBinario(bitsBinario);
}

/*
La función utiliza la posición del punto decimal para dividir el número binario 
en la parte entera y fraccionaria. Utiliza el primer bucle para calcular la parte entera
del número y el segundo bucle para calcular la parte fraccionaria. 
Finalmente, devuelve el número de punto flotante resultante.
*/

float numeroReal(char binary[]){
    int i, j, t, p;
    float num = 0.0;
    //Parte entera
    for(i = t = bitsBlanco(binary), j = 0; i < (p = posicionPuntoDecimal(binary)); i++, j++){ 
        if(binary[i] == '1'){ //Si hay un 1 en la cadena, se suma al numero la potenci ade la posicion elevado a 2
            num += pow(2, ((p - t) - 1) - j);
        }
    }

    //parte fraccionaria
    for(p = -1, i = (posicionPuntoDecimal(binary) + 1); i < maxChars; i++, p--){
        if(binary[i] == '1'){ //si hay un 1 en la posicion de la cadena, se suma al numero la potencia de p elevado a 2
            num += pow(2, p);
        }
    }
    return num;
}






