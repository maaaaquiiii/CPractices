#include <stdio.h>

//prototipos
void scanBit(char*);
void scanNibble(char*, char*, char*, char*);
void rotarNibbleDcha(char*, char*, char*, char*);
void printNibble(char, char, char, char);

int main(int argc, char *argv []){ 

    char b3,b2,b1,b0;  // nibble
    char opcion;
    do{
        scanNibble(&b3,&b2,&b1,&b0);
        printf("\nnibble: "); 
        printNibble(b3,b2,b1,b0);
        rotarNibbleDcha(&b3,&b2,&b1,&b0);
        printf ("\nnibble rotado: "); 
        printNibble(b3,b2,b1,b0);

        printf ("\n\nROTAR OTRO NIBBLE (s/n) ? ");
        scanf("%c", &opcion);
        fflush(stdin);  
    } while (opcion=='s'||opcion=='S');

    return 0;
}

/*
Esta funcion lee por teclado un bit. Para ello usamos un bucle while con la condicion de que si ese bit es distinto a 1 o 0 se vuelva a repetir.
Escaneamos el bit, sin poner el & ya que estamos usando punteros y llamamos a la funcion fflush para borrar el scanf y no se sobreescriba
*/

void scanBit(char* b){
    while(*b !='1' && *b != '0'){
        printf("\tbit ? ");
        scanf("%c", b);
        fflush(stdin);
    }
}

/*
Esta funcion es para crear al nibble. Se llama las veces necesarias a la funcion de scanBit.
*/

void scanNibble(char* b0, char* b1, char* b2, char* b3){
    printf("bit 3 \n");
    scanBit(b3);
    printf("bit 2 \n");
    scanBit(b2);
    printf("bit 1 \n");
    scanBit(b1);
    printf("bit 0 \n");
    scanBit(b0);
    //scanBit("%c%c%c%c",b3,b2,b1,b0);
}

/*
Imprime el nibble a partir de scanNibble
*/

void printNibble(char b0, char b1, char b2, char b3){
    printf("%c%c%c%c", b3, b2, b1, b0);
}

/*
Esta funcion rota hacia la derecha el numero. Para ello creamos una vble de tipo char que sea auxliar, en la que le guardamos el valor de bit 0, el bit 0 pasa a tener el valor
del bit 1 y asi hasta que guardemos el el bit 3 en la auxiliar

*/

void rotarNibbleDcha(char* b0, char* b1, char* b2, char* b3){
    char aux;

    aux = *b0;
    *b0 = *b1;
    *b1 = *b2;
    *b2 = *b3;
    *b3 = aux;
}
