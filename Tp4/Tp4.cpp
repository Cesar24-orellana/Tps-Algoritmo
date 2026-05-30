#include <stdio.h>
#include <stdlib.h>

#include "Lista.h";

int main(){
    printf("Creamos un baul vacio\n");
    Baul B = BaulVacio(10);
    printf("baaul con una capacida maxima de %d objetos\n", Capacidad(B));
    if(EstaVacio(B)){
        printf("El baul esta vacio\n");
    }else{
        printf("El baul no esta vacio\n");
    }

    Agregar(&B, 'a');
    printf("Ultimo objeto agregado: %c\n", Ultimo(B));
    printf("Primer objeto agregado: %c\n", Primero(B));
    printf("Capacidad disponible: %d\n", Disponible(B));
    printf("Agregando los objetos (b,c,d,e,f) al baul\n");
    Agregar(&B,'b');
    Agregar(&B,'c');
    Agregar(&B,'d');
    Agregar(&B,'e');
    Agregar(&B,'f');
    printf("Espacio ocupado: %d\n", Ocupado(B));
    printf("Ultimo objeto agregado: %c\n", Ultimo(B));
    printf("Primer objeto agregado: %c\n", Primero(B));
    printf("Quito el ultimo objeto agregado\n");
    QuitarUltimo(&B);
    printf("Espacio ocupado: %d\n", Ocupado(B));
    printf("Ultimo objeto agregado: %c\n", Ultimo(B));
    printf("Busco si el objeto c esta en el baul\n");
    if(Contiene(B, 'c')){
        printf("Lo contiene\n");
    }else{
        printf("No lo contiene\n");
    }
    printf("Creo un segundo baul\n");
    Baul B2 = BaulVacio(15);
    printf("Capacidad del 2do baul: %d\n", Capacidad(B2));
    printf("Agrego el objeto (z) al 2do baul\n");
    Agregar(&B2, 'z');
    printf("Primero objeto del 2do baul: %c\n", Primero(B2));
    printf("Ultimo objeto del 2do baul: %c\n", Ultimo(B2));
    printf("Espacio ocupado del 2do baul: %d\n", Ocupado(B2));
    printf("Mover los objetos del 1er baul al 2do baul\n");
    getchar();
    printf("Cantidad de objetos movidos: %d\n", moverObjetos(&B, &B2));
    printf("Espacio ocupado del 2do baul: %d\n", Ocupado(B2));
    printf("Ultimo objeto del 2do baul: %c\n", Ultimo(B2));

    printf("Libero la memoria\n");
    Vaciar(&B);
    Vaciar(&B2);
    printf("- - - - - FIN DEL PROGRAMA BAUL - - - - -");
    getchar();
    
}