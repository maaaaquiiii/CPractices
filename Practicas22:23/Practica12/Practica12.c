/*
ESPERANZA MACARENA PLAZA MARTINEZ
NUMERO DE MATRICULA: BR0427
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Prototipos de funciones

int contadorPalabras(FILE *);
/*Escribir una función que, pasándole como parámetro un fichero de texto ya abierto, 
devuelva el número de palabras conteniendo sólo caracteres alfabéticos que hay en el fichero*/
void lineaMasPalabras(FILE *);
/*Escribir una función que, pasándole como parámetro un fichero de texto ya abierto, 
imprima por pantalla la línea que más palabras tiene.*/
void sobreescribirFichero(FILE *, char *, char *);
/*Escribir una función que, pasándole como parámetro un fichero de texto ya abierto, 
el nombre de otro fichero de texto a generar y una cadena de caracteres, guarde en el segundo fichero, 
de nombre “salida.txt”,tex cada línea del primero quitándole los caracteres que aparecen 
en la tercera cadena pasada como parámetro. */

//Desarrollo del main

int main(int argc, char *argv[]){
    FILE *fichIn;
    char nameFich[25];
    char caracteresAEliminar[25];

    if ((fichIn = fopen("texto1.txt", "r")) == NULL){ 
        printf ("Error en la apertura\n");
        return 1;
    } else{
        printf("El numero de palabras del fichero es: %d\n", contadorPalabras(fichIn));
        rewind(fichIn);
        lineaMasPalabras(fichIn);
        printf("Escriba el nombre del fichero ddonde quiere sobreescribir:\n");
        gets(nameFich);
        printf("Escriba la cadena de caracteres a eliminar:\n");
        gets(caracteresAEliminar);
        sobreescribirFichero(fichIn, nameFich, caracteresAEliminar);
    }
    fclose(fichIn);
    return 0;
}

//Desarrollo de funciones

int contadorPalabras(FILE *fichIn){
    int count = 0;
    char palabra[15];

    while(fscanf(fichIn, "%s", palabra) != EOF ){ //Lee cada palabra del fichero
      if(isalpha(palabra[0])){ //determina di el primer caracter es una palabra del alfabeto
        count++; //Si se cumple la condicion, el contador incrementa
      }
    }
    return count;
}

void lineaMasPalabras(FILE * fichIn){
    char linea[160];
    char mayor[160];
    int palabrasActual;
    int palabrasMayor = 0;
    
    strcpy(linea, " ");
	strcpy(mayor, " ");
    while(fgets(linea, 160, fichIn) != NULL){  //Lee cada linea del fichero
        palabrasActual = 0;
        for(int i = 0; i <= strlen(linea); i++){ //recorre cada linea y cuenta el numero de palabras
            if (linea[i] == ' ') {
				while ((linea[++i] != ' ') && i <= strlen(linea)) {
					// Se busca el principio de la siguiete palabra
                    if (linea[i] != '\n') {
						palabrasActual++;
					}
				}
				
			}
        }
        /*
        Cada vez que encuenta un espacio en blanco, se busca el inicio de la siguiente palabra y se incrementa el contador
        */

        if(palabrasActual < palabrasMayor){ //Compara el numero de palabras de la linea actual con la linea con mas palabras
            palabrasActual = palabrasMayor; //Se actualiza el valor de la linea con mas palabras
            strcpy(mayor, linea); //Copia la linea con mas palabras a la linea actual
        }
    }
    printf("La linea mas larga es:\n%s\nY tiene: %d palabras\n", mayor, palabrasMayor); //Imprime la linea con mas palabras y el numero de palabras que tiene
}

void sobreescribirFichero(FILE * fichIn, char *nameFich, char *caracteresEliminados){
    FILE* fichOut;
    char linea[200]; 
    char lineaSinCadena[200]; 

    fichOut = fopen(nameFich, "w"); //Abre el fichero de salida
    while (fgets(linea, 160, fichIn) != NULL){ //Lee las luneas del fichero de entrada
        int j = 0;
        for(int i = 0; linea[i] != '\0'; ){ 
            if(strchr(caracteresEliminados, linea[i]) == NULL){ 
                strcpy(&linea[i], &linea[i + 1]); //Copia en otra cadena las lineas con los caracteres a eliminar
            } else {
                i++;
            }
        }

        lineaSinCadena[j] = '\0'; //Añade un espacio en blanco al final de cada linea
        fputs(lineaSinCadena, fichOut); //Escribe las lineas editadas en el fichero de salida
    }
    fclose(fichOut); //Cierra el fichero
}