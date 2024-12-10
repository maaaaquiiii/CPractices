#include "tipos.h" 
#include <stdio.h> 
#include <stdlib.h>

int aleatorio(int inf, int sup) {
    int aux = inf; if(inf > sup) {
        inf = sup; sup = aux;
    }
    return (rand()%(sup-inf+1)+inf); 
}

void rellenarID(char id[11]) {
    int i;
    id[0]='2';
    id[1]='8';
    for(i=2; i<8; i++) {
        id[i]=aleatorio('0','9'); 
        id[8]=aleatorio('A','Z'); id[9]='\0';
    }
}

void rellenarNum(int num[6]) {
    int i;
    for(i=0; i<6; i++){ 
        num[i]= aleatorio(1,49); 
        for(i=1; i<6; i++) 
            if(num[i] = num[i-1]) 
                num[i] = aleatorio(1,49);
    }
}

void hacerApuesta(Apuesta *apuesta) {
    rellenarID(apuesta->id);
    rellenarNum(apuesta->digitos); 
}

void hacerFApuesta(char *fnom, int boleto) {
    int i;
    FILE* f_in;
    Apuesta apuesta;
    if(!(f_in = fopen(fnom,"wb")))
        printf("Error de fichero.");
    for(i=0; i< boleto; i++) {
        hacerApuesta(&apuest); 
        fwrite(&apuesta, sizeof(Apuesta),1,f_in); 
    }
    fclose(f_in);
}