                        // ESPERANZA MACARENA PLAZA MARTINEZ
                        // Nº de matricula: br0427

#include <stdio.h>
#include <stdlib.h>

//Prototipos
int potenciaFuncion(int, int);
void printBinary(int);
void pulsar();
void scan(int *, int *);

/*
En el main, lo unico que se necesita es un bucle do while para ver si se quiere modificar la base y el exponente,
después se hace un bucle for que recorra el numero del exponente incluido, en el cual se llaman a las funciones creadas, 
y en vez de poner el exponente en el parametro de las funciones, se pone i ya que si se pone el exponente
directamente en los resultados saldria solamente la última potencia.
*/

int main () {
    int base, exponente;
    char opcion;

    do {
        scan(&base, &exponente);
        printf ("Desea modificar la base y el exponente (S/N): ");
        scanf ("%c", &opcion);
        fflush(stdin);
    } while(opcion != 'N' && opcion != 'n');

    for(int i = 0; i <= exponente; i++){
        printf ("%d^%d = %d\n", base, i, potenciaFuncion(base, i));
        printBinary(potenciaFuncion(base, i));
        pulsar();
    }

    return 0;
}

//Desarrollo de funciones

/*
Para la funcion de potencia, lo que se necesita una variavle que sea 1 (ya que si es 0, siempre va a dar 0),
y se crea un bucle for para que multiplique las veces que se han pasado por parametro como exponente,
y se multiplica la variable potencia con la base que se ha pasado por parámetro
*/

int potenciaFuncion(int base, int exponente){
    int potencia = 1;

    for (int i = 1; i <= exponente; i++) {
        potencia *= base;
    }
    return potencia;
}

/*
Para imprimir el binario de la potencia, se hace un bucle while de forma que la potencia sea mayor que 0.
Despues se comprueba con un if si el modulo de la potencia entre 2 es 1, se imprime un 1, sino se imprime un 0.
y después se divide la potencia entre 2 y se incrementa el contador de los bits.
*/

void printBinary(int potencia){
    int count = 0;

    while (potencia > 0) {
        if(potencia % 2 == 1){
            printf("bit %d: 1\n", count);
        } else{
            printf ("bit %d: 0\n", count);
        }
        potencia /= 2;
        count++;
    }
    count = 0;
}

/*
Para esta función lo único que se necesita es la función getchar() que sirve para leer cualquier caracter
*/

void pulsar(){
    printf("\nDesea coninuar?\n");
    fflush(stdin);
    getchar();
}

/*
Esta función es para leer por teclado los valores que se quieran introducir, para ello es necesario el uso
de punteros. En este caso, se hacen dos bucles do while para que estén dentro del rango requerido.
Y para escanear el valor se necesita la función scanf, pero con la diferencia que no se pone & debido a que
no se quiere acceder ni modificar la dirección de memoria, pero para hacer los rangos se pone * ya que
se quiere comparar el valor introducido por teclado con el contenido que se quiere dar para el rango.
*/

void scan(int * base, int * exponente){
    do {
        printf ("Escriba la base [2-10]: ");
        fflush(stdin);
        scanf ("%d", base);
    } while(*base < 2 || *base > 10);
    do {
        printf ("Escriba el exponente [0-10]: ");
        fflush(stdin);
        scanf("%d", exponente);
    } while(*exponente < 0 || *exponente > 10);
}




