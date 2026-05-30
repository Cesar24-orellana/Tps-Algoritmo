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
    printf("Quito el ultimo objeto agregado");
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
    Baul B2 = BaulVacio(10);
    printf("Capacidad del 2do baul: %d\n", Capacidad(B2));

    printf("Libero la memoria\n");
    Vaciar(&B);
    printf("- - - - - FIN DEL PROGRAMA BAUL - - - - -");
    getchar();
    
}