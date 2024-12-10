#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Desarrollo de estructuras
typedef struct Tnodo {
    int dato;
    struct Tnodo *siguiente;
} NODO;

typedef struct TlistaNodos {
    NODO *inicio;
} ListaNodo;


//prototipos
void iniciarLista(ListaNodo * listaNodos);
//Inicializa la lista
void insertarListaCircular (int pos, ListaNodo * listaNodos);
//crea un nodo, cuyo campo dato es un integer e inserta dicho nodo en una lista 

void recorrerListaCircular (ListaNodo * listaNodos);
// recorre una lista y printa el contenido del campo dato de cada nodo

//main
int main() {
    ListaNodo lista;
    int i = 0;

    iniciarLista(&lista);
    //Comprobacion si funciona
    for(i = 0; i < 10; i++){
        insertarListaCircular(i, &lista);
    }
    insertarListaCircular(1, &lista);
    recorrerListaCircular(&lista);
}


//Desarrollo de funciones
void iniciarLista(ListaNodo * listaNodos) {
    listaNodos -> inicio = NULL;
}


void insertarListaCircular (int pos, ListaNodo *listaNodos) {
    NODO * nuevo;

    nuevo = malloc(sizeof(struct Tnodo));
    (*nuevo).dato = pos;
    (*nuevo).siguiente = (* listaNodos).inicio;
    (*listaNodos).inicio = nuevo;
}


void recorrerListaCircular (ListaNodo * listaNodos){
    NODO * nodo;

    nodo = listaNodos -> inicio;
    if(nodo != NULL){
        do{
            printf ("%d ", nodo -> dato);
            nodo = nodo -> siguiente;  
        } while(nodo != listaNodos -> inicio);
    }
    printf ("NULL");
}