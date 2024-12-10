                        // ESPERANZA MACARENA PLAZA MARTINEZ
                        // Nº de matricula: br0427

#include <stdio.h>
#include <stdlib.h>
#define maximoChars 64

//Prototipos
void binarioEntera(int, char []);  
// un int se convierte a binario (se almacena en el array)

void binarioFraccionaria(float , char []); 
// un float se convierte a binario (se almacena en el array)

void resetear(char []); 
// se resetea el array

void ponerPosicion (char [],int , char );
// se coloca un char en la posicion int del array

int bitsBlanco(char []);
// chars en blanco en el array

void insertarFinal(char [],char );
// se inserta un char al final del array, desplazando el resto a la izquierda

void printBinario(char []);
// se printa el array con los char del numero binario


int main() {
    int entero = 0;
    float decimal = 0.0;
    char binary[maximoChars] = {0};

    resetear(binary);
    printf("Escriba la parte entera de un numero: "); 
    fflush(stdin);
    scanf("%d", &entero);
    binarioEntera(entero, binary);
    printBinario(binary);
    printf("\nEscriba la parte decimal de un numero: "); 
    fflush(stdin);
    scanf("%f", &decimal);
    binarioFraccionaria(decimal, binary);
    printBinario(binary);

    return 0;
}

//Definicion de funciones
/*
En esta función lo que se quieres es pasar la parte entera de un numero a binario y guardar el resultado
a un array de caracteres, por lo que se crea una variable i (para rellenar dicho array), la cual se iguala
a maximoChars - 1 debido a que si el indice del array empieza por 0 hasta 63 (ya que es un array de 64)
por lo que se va a empezar a rellenar por la posición 63.
Luego se hace un bucle while para que se haga de manera iterativa hasta que el num sea mayor que 0,
y dentro de ese while, se comprueba que si el total de multiplicar 10 por la parte decimal del numero 
dividido entre dos menos el numero entre dos es mayor o igual que 5, se le añade un 1 al array, sino es
así se rellena el array con un 0. Y para que el numero vaya disminuyendo se divide entre dos 
*/
void binarioEntera(int num, char binary[]){
    int i = maximoChars - 1;

    while(num > 0){
        if(10 * (((float) num / 2) - (num / 2)) >= 5){
            binary[i--] = '1';
        } else{
            binary[i--] = '0';
        }
        num /= 2;
    }   
}

/*
En esta funcion, se va a necesitar la función insertarFinal para seguir rellenando el array por detrás.
Primero se inserta el punto, para indicar la parte decimal del numero, despúes se crea un bucle while para
hacerlo de forma repetitiva hasta que el decimal no sea 0.0, despues se comprueba con un if que si la parte
entera del decimal multiplicado por es no es cero, se inserta al final del array un 1, sino se inserta un 0,
y el decimal se multiplica por dos y se resta la parte entera.
*/

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

/*
Se pone todo el array vacío, para ello se crea un bucle for para recorrer dicho array y vaciarlo
*/

void resetear(char binary[]){
    for(int i = 0; i < maximoChars; i++){
        binary[i] = ' ';
    }
}


/*
Se lee por parametro el caracter que se quiere meter y la posición donde se quiere guardar, para ello
se busca la posición dentro del array y se coloca el char
*/

void ponerPosicion (char binary[],int pos, char car){
    binary[pos] = car;
}

/*
En esta función se quiere contar los espacion en blanco del array, para ello se ncesita un contador,
y se recorre el array en busca de si hay espacios en blanco se le añade al contador y como la función es
int, se devuelve el contador
*/

int bitsBlanco(char cad[]){
    int count = 0;
    
    for(int i = 0; i < maximoChars; i++){
        if(cad[i] == ' '){
            count++;
        }
    }
    return count;
}

/*
Para insertar al final de un array, se mepieza a recorrer y el contenido que esta en la posición de i pasa
a ser la anterior, debido a que se desplaza a la izquierda. Y cuando  esta en el ultimo elemento se añade 
el caracter
*/

void insertarFinal(char cad[], char car){
    for(int i = 0; i < maximoChars - bitsBlanco(cad) ; ){
        ponerPosicion(cad, i, car);
        cad[i++] = car;
    }
}

// Imprime el array en orden ascendente y solo imprime los caracteres que no sean vacío

void printBinario(char binary[]){
    for(int i = 0; i <= maximoChars; i++){
        if(binary[i] != ' '){
            printf("%c", binary[i]);
        }
    }
}

