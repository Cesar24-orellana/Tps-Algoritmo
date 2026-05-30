#include <stdio.h>
#include <stdlib.h>

#include "Lista.h";

int main(){
    printf("Creamos un baul vacio\n");
    Baul B = BaulVacio(10);
    printf("baaul con una capacida maxima de %d objetos\n", Capacidad(B));
    
}