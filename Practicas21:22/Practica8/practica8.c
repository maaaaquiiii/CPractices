#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200

struct Tfecha{
     int day;
     int month;
     int year;
};

struct Tcliente{
     char apellidos[41];
     struct Tfecha antiguedad;
     float ultimaCompra;
};

struct TlistaClientes{
     int numClientes;
     struct Tcliente arrayClientes[N];
};


//prototipos
void scanFecha(struct Tfecha * );
void printFecha (struct Tfecha );
void scanCliente (struct Tcliente * );
void printCliente (struct Tcliente );
void printListaClientes (struct TlistaClientes);
void inicializarLista (struct TlistaClientes *);
void anadirCliente (struct TlistaClientes *);
int longitudLista (struct TlistaClientes);
//practica 9
void copiarFechas(struct Tfecha * fecha1, struct Tfecha * fecha2);
void copiarClientes(struct Tcliente * cliente1, struct Tcliente * cliente2);
void insertarCliente(struct TlistaClientes * lista, int pos); 
void eliminarCliente(struct TlistaClientes * lista, int pos);
void vaciarListaClientes(struct TlistaClientes * lista);


int main(){

     struct Tcliente cliente1;
     struct Tcliente cliente2;
     struct TlistaClientes lista;
     char eleccion = ' ';

     inicializarLista (&lista);

     do{   
          anadirCliente(&lista);
          system("clear"); //system("clear") == system("cls");
          printf("\nDesea introducir un cliente mas? (y/n): ");
          fflush(stdin);
          scanf("%c", &eleccion);
          fflush(stdin);
     } while (eleccion=='y' || eleccion=='Y');

     printListaClientes (lista);
     //practica 9
     printf("Copia un cliente a otro\n");
     scanCliente(&cliente1);
     printf("\n");
     copiarClientes(&cliente1, &cliente2);
     printf("\n\n");
     printCliente(cliente2);
     printf("Inserta un cliente en una posicion determinada");
     insertarCliente(&lista, 2);
     printListaClientes(lista);
     printf("Elimina un cliente de una posicion\n");
     eliminarCliente(&lista, 2);
     printListaClientes(lista); 
     vaciarListaClientes(&lista);
     
}

//Desarrollo de funciones

/*
En esta funcion se tiene que escanear cada digito para que se guarde en la estructura fecha que se ha pasado en el argumento,
para ello solamente hay que meter el valor y guardarlo en la variable que corresponde, 
en el caso de día se guarda en la variable day que se ha creado previamente en la struct. .
*/
void scanFecha(struct Tfecha * fecha) {
     printf("Day: ");
     scanf("%d", &(fecha -> day));
     fflush(stdin);
     printf("Month: ");
     scanf("%d", &(fecha -> month));
     printf("Year: ");
     fflush(stdin);
     scanf("%d", &(fecha -> year));
     fflush(stdin);
}

/*
Para imprimir cualquier dato que se ha guardo en una struct 
solo hay que acceder llamando al a struct y la variable que se desea imprimir 

*/
void printFecha (struct Tfecha fecha) {
     printf("%.2d/%.2d/%d", fecha.day, fecha.month, fecha.year);
}


void scanCliente (struct Tcliente * cliente) {
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


void printCliente (struct Tcliente cliente) {
     printf("\nSurname: %s", cliente.apellidos);
     printf("\nDate: ");
     printFecha(cliente.antiguedad);
     printf("\nLast purchase %.2f€\n", cliente.ultimaCompra);
}

/*
Para imprimir un array struct se imprime como un array, es decir,
se crea una variable i para que en cada bucle imprima la información
de la struct
*/

void printListaClientes (struct TlistaClientes listaClientes) {
     int i = 0;

     for(i = 0; i < listaClientes.numClientes; i++){
         printCliente(listaClientes.arrayClientes[i]);
         printf("\n\n");
     }
}

/*
Para inicializar un array de structs solo hay que acceder al numero del array
e igualarla a 0
*/
void inicializarLista (struct TlistaClientes * listaClientes) {
     listaClientes -> numClientes = 0;
}

/*
Para añadir una nueva struct a un array de structs solo hay queacceder a la struct del array, 
para ello se necesita la funcion de escanear una nueva struct dentro del array,
se introducen los datos y se hace más grande el array de structs
*/

void anadirCliente (struct TlistaClientes * listaClientes){
     scanCliente(&(listaClientes -> arrayClientes[listaClientes -> numClientes]));
     listaClientes -> numClientes++;
}

int longitudLista(struct TlistaClientes listaClientes) {
     return listaClientes.numClientes;
}

//Practica 9

void copiarFechas(struct Tfecha * fecha1, struct Tfecha * fecha2) {
    fecha2 -> day = fecha1 -> day;
    fecha2 -> month = fecha1 -> month;
    fecha2 -> year = fecha1 -> year;
}



void copiarClientes (struct Tcliente * cliente1, struct Tcliente * cliente2) {
    strcpy(cliente2 -> apellidos, cliente1 -> apellidos);
    copiarFechas(&cliente1 -> antiguedad, &cliente2 -> antiguedad);
    cliente2 -> ultimaCompra = cliente1 -> ultimaCompra;
}



void insertarCliente(struct TlistaClientes * lista, int pos) {
     int i = 0;
     char apellidos[25 + 1];

     if(lista -> numClientes < N) {
          printf("\nEscriba el apellido: ");
          scanf("%s", apellidos);
          for(i = pos; i <= pos && strcmp(apellidos, lista -> arrayClientes[i].apellidos); i++){
               if(i < lista -> numClientes) {
                    scanCliente(&lista -> arrayClientes[i]);
                    lista -> numClientes++;
               }
               else {
               printf("\nEl cliente está en la lista");
               }
          }
     }
     else{
        printf("\nLa lista está llena");
     }

}


 void eliminarCliente(struct TlistaClientes *lista, int pos) {
     int i = 0;
     char apellidos[25 + 1];

     if(lista -> numClientes == 0){
          printf("La lista esta vacía");
     }
     else {
          printf("Escriba el apellido del cliente: \n");
          scanf("%s", apellidos);
          for(i = pos; i < lista -> numClientes && strcmp(apellidos, lista -> arrayClientes[i].apellidos); i++) {
               if(i < lista -> numClientes) {
                    lista -> arrayClientes[i] = lista -> arrayClientes[i - 1];
                    lista -> numClientes--;
               }
               else {
                    printf("Cliente no encontrado");
               }
          }
     }
     
}



void vaciarListaClientes(struct TlistaClientes * lista) {
     lista -> numClientes = 0;
}




