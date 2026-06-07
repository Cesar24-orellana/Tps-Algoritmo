#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

int main(){
    printf("- - - - - - - - INICIO DEL PROGRAMA - - - - - -");
    printf("1. Crear una fila vacia F\n");
    Fila F = FilaVacia();
    printf("2. Es F una fila vacia?\n");
    if(esFilaVacia(F)){
        printf("Es una fila vacia\n");
    }else{
        printf("No es fila vacia\n");
    }
    printf("- - - - - - - - FIN DEL PROGRAMA - - - - - -");
    return 0;
}