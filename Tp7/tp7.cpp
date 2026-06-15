#include <stdio.h>
#include <stdlib.h>

#include "AB.h"

int main(){
    printf("- - - - - INICIO DEL PROGRAMA ADT(AB - - - - -\n");
    AB izq = ABVacio();
    AB der = ABVacio();
    AB T = armarAB(izq, 'x', der);
    if(esABVacio(T)){
        printf("Arbol vacio\n");
    } else{
        printf("Arbol no esta vacio\n");
    }
    printf("Raiz de ab: %c\n",Raiz(T));
    AB I = armarAB(ABVacio(), 'i', T);
    printf("Raiz de ab: %c\n",Raiz(I));
    AB D = armarAB(ABVacio(), 'd', ABVacio());
    printf("Raiz de ab: %c\n",Raiz(D));
    T = armarAB(I, 'z', D);
    printf("Raiz de ab: %c\n",Raiz(T));
    if(pertenece(T, 'd')){
        printf("Si pertenece\n");
    } else{
        printf("No pertenece\n");
    }
    printf("Altura de ab: %d\n", Altura(T));
    printf("- - - - - FIN DEL PROGRAMA - - - - -");
    getchar();
    return 0;
}