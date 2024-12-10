                        // ESPERANZA MACARENA PLAZA MARTINEZ
                        // Nº de matricula: br0427

#include <stdio.h>
#include <stdlib.h>
#define N 8

//STRUCTS
typedef struct{
    int hora;
    int minuto;
    int segundo;
} HORA;

typedef struct{
    float real;
    float imaginaria;
    HORA tiempo;
} COMPLEJO;

typedef struct{
    int total;
    COMPLEJO arrayComplejo[N];  
} ListaComplejos;


//Prototipos de funciones
void printHORA(HORA);
void scanHORA(HORA *);
void scanCOMP (COMPLEJO *);
void printCOMP(COMPLEJO);
void printMenu();
void cualquierTecla(); 
// espera que se pulse cualquier tecla, sin hacer echo
void inicializarLista(ListaComplejos *);
void addComplejo(ListaComplejos *, COMPLEJO);
void eliminarCOMPLEJO(ListaComplejos *); 
// elimina el ultimo complejo añadido a la lista
void printListaCOMPLEJOS(ListaComplejos);

int main() {
    int seleccion = 0;
    COMPLEJO complejo;
    ListaComplejos lista;

    inicializarLista(&lista);
    do {
        printMenu();
        printf("Escoge opcion: ");
        fflush(stdin);
        scanf("%d", &seleccion);
        switch(seleccion){
            case 1:
                printf("\nAdd numero complejo:\n");
                addComplejo(&lista, complejo);
                printf("\nNumero complejo insertado\n");
                cualquierTecla();
                break;
            case 2:
                printf("\n2. Eliminar el ultimo numero\n");
                eliminarCOMPLEJO(&lista);
                printf("\nNumero cmplejo eliminado\n");
                cualquierTecla();
                break;
            case 3:
                printf("\n3. Listar numeros complejos\n\n");
                printListaCOMPLEJOS(lista);
                cualquierTecla();
                break;
            case 0:
                return 0;
            default:
                printf("Opcion incorrecta, vuelva a introducir opcion\n");
        }
    }while(seleccion != 4);

    return 0;
}

//Definicion de funciones
void printHORA(HORA time){
    printf("%.2d:%.2d:%.2d\n", time.hora, time.minuto, time.segundo);
}

void scanHORA(HORA * time){
    printf("Hora de la posicion (hh:mm:ss): \n");
    fflush(stdin);
    scanf("%d:%d:%d", (&time -> hora), (&time -> minuto), (&time -> segundo));
}

void scanCOMP (COMPLEJO *complejo){
    printf("Parte real: ");
    fflush(stdin);
    scanf("%f", &complejo -> real);
    printf("Parte imaginaria: ");
    fflush(stdin);
    scanf("%f", &complejo -> imaginaria);
    scanHORA(&complejo -> tiempo);
}

void printCOMP(COMPLEJO complejo){
    printf("Posicion de un movil (numero complejo)\n");
    printf("Complejo: %.2f%.2fi\n", complejo.real, complejo.imaginaria);
    printHORA(complejo.tiempo);
}
void printMenu(){
    printf("0. Terminar\n");
    printf("1. Add numero complejo\n");
    printf("2. Eliminar el ultimo numero complejo\n");
    printf("3. Listar numeros complejos\n");
}

void cualquierTecla(){
    printf("PULSE cualquier tecla\n");
    fflush(stdin);
    getchar();
}

void inicializarLista(ListaComplejos * lista){
    lista -> total = 0;
}

void addComplejo(ListaComplejos *lista, COMPLEJO complejo){
    if(lista -> total >= N){ //Comprueba que la lista no este completa
        printf("La lista esta completa");
    } else {
        scanCOMP(&complejo); //Actualiza los valores de la estructura complejo
        lista -> arrayComplejo[lista -> total] = complejo; //Se agrega la estructura complejo al array de la estructura lista
        lista -> total++; //Se actualiza el total de la lista
    }
}

void eliminarCOMPLEJO(ListaComplejos * lista){
    if(lista -> total == 0){ //Comprueba que la lista no este vacía
        printf("La lista esta vacia");
    } else {
        lista -> total--; //Se resta un elemento del total
    }
}

void printListaCOMPLEJOS(ListaComplejos lista){
    for(int i = 0; i < lista.total; i++) { //Recorre el array para imprimir cada elemento
        printCOMP(lista.arrayComplejo[i]);
        printf("\n");
    }
}





