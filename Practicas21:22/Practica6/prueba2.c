/*
PRACTICA REALIZADA POR ESPERANZA MACARENA PLAZA MARTINEZ
NUMERO DE MATRICULA: BR0427
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5


//prototipos
int aleatorio(int inf, int sup);
void rellenar(int matrix[][N]);
void imprimir(int matrix[][N]);
void producto(int matrix[][N], int matrix2[][N]);
void triangularSuperior(int matrix[][N]);
void triangularInferior(int matrix[][N]);
void identidad(int matrix[][N]);
void burbuja(int a[N]);



int main(){
    int matriz[N][N];
    int matriz2[N][N];
    //opcional
    int array[N];

    srand(time(NULL));
    printf("\n\t\t\tImprimir primera matriz\n");
    rellenar(matriz);
    imprimir(matriz);
    printf("\n\n\n");
    printf("\t\t\tImprimir segunda matriz\n");
    rellenar(matriz2);
    imprimir(matriz2);
    printf("\n\n\n");
    printf("\t\t\tProducto de la primera matriz por la segunda\n");
    producto(matriz, matriz2);
    imprimir(matriz);
    printf("\n\n\n");
    printf("\t\t\tTriangular superior primera matriz\n");
   triangularSuperior(matriz);
    imprimir(matriz);
    printf("\n\n\n");
    printf("\t\t\tTriangular superior segunda matriz\n");
    triangularSuperior(matriz2);
    imprimir(matriz2);
    printf("\n\n\n");
    printf("\t\t\tProducto de la segunda matriz por la primera\n");
    producto(matriz2, matriz);
    imprimir(matriz2);
    printf("\n\n\n");
    printf("\t\t\tTriangular inferior de la primera matriz\n");
    triangularInferior(matriz);
    imprimir(matriz);
    printf("\n\n\n");
    printf("\t\t\tProducto de la segunda matriz por la primera\n");
    producto(matriz2, matriz);
    imprimir(matriz2);
    printf("\n\n\n");
    printf("\t\t\tSegunda matriz identidad\n");
    identidad(matriz2);
    imprimir(matriz2);
    printf("\n\n\n");
    printf("\t\t\tProducto de la primera matriz por la segunda\n");
    producto(matriz, matriz2);
    imprimir(matriz);

}


int aleatorio (int inf, int sup){
   int aux = inf;

   if (inf > sup){
       inf = sup;
       sup = aux;
   }
   return (rand() % (sup - inf + 1) + inf);
}

/*
Esta función se encarga de rellenar el array bidimensional con la función de aleatorio en el rango de [-20] y [20]
Se crean dos variables para ir recorriendo el array y rellenandolo
*/

void rellenar(int matrix[N][N]){
	int i, j;
	int randomNum = aleatorio(0, 10);

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			randomNum = aleatorio(0, 10);
			matrix[i][j] = randomNum;
		}
	}
}

/*
Esta función imprime la matriz
Se crean dos variables para recorrer la matriz y una para hacer espacios y que quede cuadrada la matriz con %*d -> de los espacios y la matriz
Al salir del bucle for de j haces un salto de linea
*/

void imprimir(int matrix[N][N]){
	int i, j;
	int espacios = 5;

	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%*d ", espacios, matrix[i][j]);
		}
		printf("\n");
	}
}

/*
Esta función se encarga de hacer el producto de dos matrices (fila * columna)
Se crean tres vbles para recorrer las dos matrices, se crea una matriz auxiliar en la que se mete los resultados (la i es la fila de la primera matriz, 
la j es la columna de la matriz y la k sirve para multiplicar cada fila por las columnas de las matrices)
*/

void producto(int matrix[N][N], int matrix2[N][N]){
	int i, j, k;
    int result[N][N];

	for(i = 0; i < N; i++ ){
    	for(j = 0; j < N; j++){
    		result[i][j] = 0;
    		for(k = 0; k < N; k++){
    			result[i][j] += matrix[i][k] * matrix2[k][j];
    		}
    	}
    }
    /*
    Se hace de nuevo los dos bucles for para rellenar la primera matriz pasada por parametro e igualarla a la matriz auxiliar
    */
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            matrix[i][j] = result[i][j];
        }
    }
    //imprimir(result);
}

/*
Esta función rellena de '0' en a partir de la diagonal principal hacia abajo
Se crean dos vbles para los bucles for y 
*/

void triangularSuperior(int matrix[][N]){
	int i, j = 0;

	for(i = 0; i < N; i++){
		for(j = 0; j < i; j++){
			matrix[i][j] = 0;
		}
	}
}


/*
Esta función tienes que conseguir la triangular inferior de una matriz
Se hacen dos bucles for para recorrer el array bidimensional
se crea una condicion en la que diga que si la j (columnas) es menor que la i (filas) o si son iguales genere la triangular inferior con numeros aleatorios sino que la rellene con 0
*/

void triangularInferior(int matrix[][N]){
	int i = 0;
    int j = 0;

    for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(j <= i)
                matrix[i][j] = aleatorio(-20, 20);
            else
                matrix[i][j] = 0;
		}
	}
    
}

/*
Esta función consiste en sacar la identidad de una matriz
Se crean dos bucles for para recorrer el array y lo rellenas con 1 en la diagonal principal
*/


void identidad(int matrix[][N]){
	int i , j;
    i = j = 0;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            matrix[i][j] = (i == j); //si i = j entonces matrix[i][j] imprimirá 1
            /*
            if(i == j){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
            */
        }
    }
}



