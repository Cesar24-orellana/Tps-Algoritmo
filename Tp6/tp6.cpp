#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"

int main(){
    printf("- - - - - - - - INICIO DEL PROGRAMA - - - - - -\n");
    printf("1. Crear una fila vacia F\n");
    Fila F = FilaVacia();
    printf("2. Es F una fila vacia?\n");
    if(esFilaVacia(F)){
        printf("Es una fila vacia\n");
    }else{
        printf("No es fila vacia\n");
    }
    mostrar(F);
    getchar();
    printf("2. Agregar el dato (1) a la fila\n");
    F = enfila(F, 1);
    printf("3. En el frente se encuentra el dato: %d\n", frente(F));
    printf("Y en el final se encuentra el dato: %d", final(F));
    mostrar(F);
    getchar();
    printf("4. Cargo los datos (2, 3, 4, 4, 5, 1, 7)\n");
    F = enfila(F, 2);
    F = enfila(F, 3);
    F = enfila(F, 4);
    F = enfila(F, 4);
    F = enfila(F, 5);
    F = enfila(F, 1);
    F = enfila(F, 7);
    printf("5. En el frente se encuentra el dato: %d\n", frente(F));
    printf("Y en el final se encuentra el dato: %d\n", final(F));
    printf("6. Longitud de la fila: %d\n", F.longitud);
    mostrar(F);
    F = extraer_N_esimo(F, 2, FilaVacia());
    if (pertenece(F, 4))
    {
        printf("Si pertenece\n");
    }else{
        printf("No pertenece\n");
    }
    mostrar(F);
    F = singular(F);
    mostrar(F);
    printf("Longitud de F: %d\n", F.longitud);
    getchar();
    printf("Liberar Memoria\n");
    while (!esFilaVacia(F))
    {
        F = defila(F);
    }
    printf("");
    printf("- - - - - - - - FIN DEL PROGRAMA - - - - - -");
    return 0;
}