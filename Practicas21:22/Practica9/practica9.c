#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

struct Tdate{
    int day;
    int month;
    int year;
};

struct Tcliente{
    char apellidos[41];
    struct Tdate antiguedad;
    float ultimaCompra;
};

struct TlistaClientes{
    int numClientes;
    struct Tcliente arrayClientes[N];
};


// prototipos
void scanFecha(struct Tdate * fecha);
void printFecha(struct Tdate fecha);
void copiarFechas (struct Tdate * date1, struct Tdate * date2);
void copiarClientes (struct Tcliente * cliente1, struct Tcliente * cliente2);
void scanCliente (struct Tcliente * );
void printCliente (struct Tcliente );
void insertarCliente (struct TlistaClientes * lista, int pos); 
/*void eliminarCliente (struct TlistaClientes * lista, int pos);
void vaciarListaClientes (struct TlistaClientes * lista);*/

int main(){

    struct Tcliente cliente1;
    struct Tcliente cliente2;

    scanCliente(&cliente1);
    printCliente(cliente1);
    printf("\n");
    copiarClientes(&cliente1, &cliente2);
    printCliente(cliente2);
}



//desarrollo de funciones
void scanFecha(struct Tdate * date){
    printf("Day: ");
    scanf("%d", &(date -> day));
    fflush(stdin);
    printf("Month: ");
    scanf("%d", &(date -> month));
    printf("Year: ");
    fflush(stdin);
    scanf("%d", &(date -> year));
    fflush(stdin);
}


void printFecha (struct Tdate date){
    printf("%d/%d/%d", date.day, date.month, date.year);
}


void scanCliente (struct Tcliente * cliente){
    printf("Surname: ");
    fflush(stdin);
    scanf("%s", cliente -> apellidos);
    fflush(stdin);
    scanFecha(&(cliente -> antiguedad));
    printf("Last purchase :");
    fflush(stdin);
    scanf("%f", &(cliente -> ultimaCompra));
    fflush(stdin);
}


void printCliente (struct Tcliente cliente){
    printf("Surname: %s \n", cliente.apellidos);
    printf("Date: ");
    printFecha(cliente.antiguedad);
    printf("\nLast purchase %.2f", cliente.ultimaCompra);
}


void copiarFechas (struct Tdate * date1, struct Tdate * date2){
    date2 -> day = date1 -> day;
    date2 -> month = date1 -> month;
    date2 -> year = date1 -> year;
}



void copiarClientes (struct Tcliente * cliente1, struct Tcliente * cliente2){
    strcpy(cliente2 -> apellidos, cliente1 -> apellidos);
    copiarFechas(&cliente1 -> antiguedad, &cliente2 -> antiguedad);
    cliente2 -> ultimaCompra = cliente1 -> ultimaCompra;
}



void insertarCliente (struct TlistaClientes * lista, int pos){
    int i = 0;
    char c = ' ';

    while(c != 'Y' || c != 'y'){
        printf("Desea añadir cliente? (y/n): ");
        scanf("%c", &c);
        if(c == 'Y' || c == 'c'){
        }
    }
}
/*
void eliminarCliente (struct TlistaClientes *lista, int pos){

}

void vaciarListaClientes (struct TlistaClientes * lista){

}
*/