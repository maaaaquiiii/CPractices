#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define N 30
#define M 6

//prototipos
int aleatorio (int, int);
void imprimir (char *);
void rellenar (char *);
void eliminar (char *, char);
void compactar (char *);
void contadorCaracteres(char *letters, unsigned *count);


int main (){
   char letters[N];
   char letter = ' ';

   srand(time(NULL));
   rellenar(letters);
   imprimir(letters);
   printf("\n\n");

   while(letter < 'A' || letter > 'F'){
       printf("Introduzca una letra mayuscula: ");
       fflush(stdin);
       scanf("%c",&letter);
       printf("\n\n");
   }
   eliminar(letters,letter);
   imprimir(letters);
   compactar(letters);
   imprimir(letters);
   contadorCaracteres(letters, 0);
}

/*
Esta funcion genera una semilla aleatoria
Hay un condicional por si el primer número es mayor que el segundo. Para ello se necesita una vble auxiliar para q si el num inferior es mayor que el superior, el valor del inferior
se guarde en el superior, se iguala el superior ala vble auxiliar y la auxiliar se guarda en el inferior
*/


int aleatorio (int inf, int sup){
   int aux = inf;

   if (inf > sup){
       inf = sup;
       sup = aux;
       aux = inf;
   }
   return (rand()%(sup-inf+1)+inf);
}

/*
Esta funcion rellena el array con caracteres. Para ello se hace un bucle con una vble y rellenas el array con ls funcion de aleatorio con los parametros 'A' y 'F'
o sino puedes poner la funcion de aleatorio con los parametros de 0 y 5 + 'A' y se sumara a su valor ASCII (ej: 'A' = 65, 3 + 65 = 'D')
*/


void rellenar (char *letters){
   int i = 0;

   for(i = 0; i < N; i++){
       letters[i] = aleatorio(0, 5) + 'A';
   }
}

/*
Esta funcion imprime los valores del array con un bucle for de una variable
*/

void imprimir (char *letters){
   int i = 0;

   for(i = 0; i < N; i++){
       printf("%c ", letters[i]);
   }
   printf("\n");
}

/*
Esta funcion elimina del array pasado por parametro una letra tambien pasada por parametro. Se recorre el array con un bucle for de una vble y 
si en su recorrido encuentra la letra pasada por parametro la sustituye por un punto
*/

void eliminar(char *letters, char letraEl)
{
   int i = 0;

   for(i = 0; i < N; i++)
   {
       if(letters[i] == letraEl)
           letters[i] = '.';
   }
}

/*
Esta funcion agrupa los caracteres por un lado y los puntos por otro. Para ello, necesitaremos dos vbles para dos bucles for y un caracter auxiliar. 
Se recorre el array y si por el recorrido encuentra un punto lo guarda en la vble auxiliar y lo mete al final del array.
*/

void compactar(char *letters){
   int i, j;
   i = j = 0;
   char aux = ' ';

   for(i = 0; i < N; i++){
       for(j = i + 1; j < N; j++){
           if(letters[i] == '.'){
               aux = letters[i];
               letters[i] = letters[j];
               letters[j] = aux;
           }
       }
   }
}

void contadorCaracteres(char *letters, unsigned *count){
    int i = 0;

    for(i = 0; i < N; i++){
        if(letters[i] == 'A');
            count[0]++;
        if(letters[i] == 'B');
            count[1]++;
        if(letters[i] == 'C');
            count[2]++;
        if(letters[i] == 'D');
            count[3]++;
        if(letters[i] == 'E');
            count[4]++;
        if(letters[i] == 'F');
            count[5]++;
    }
    for(i = 0; i < M; i++){
        printf("%u", count[i]);
    }
}