#include <stdio.h>
#include <stdlib.h>

#include "Pila.h"

int main(){
    printf("- - - - - - Inicio del programa - - - - - - - \n");
    printf("1. Inicializo una pila\n");
    Pila P = pilaVacia();
    printf("2. La pila esta vacia?");
    if (esPilaVacia(P))
    {
        printf("La pila esta vacia\n");
    }else{
        printf("La pila no esta vacia\n");
    }
    printf("3. La pila vacia contiene el dato: %c\n", top(P));
    printf("4. Agrego el dato (a) a la pila\n");
    P = push(P, 'a');
    printf("En el tope de la pila se encuentra el dato: %c\n", top(P));
    printf("5. Agregao los siguientes datos a la pila (b, c, d, e, e, f, g)\n");
    P = push(P, 'b');
    P = push(P, 'c');
    P = push(P, 'd');
    P = push(P, 'e');
    P = push(P, 'e');
    P = push(P, 'f');
    P = push(P, 'g');
    printf("En el tope de la pila se encuentra el dato: %c\n", top(P));
    
    getchar();
    printf("- - - - Liberar la memorio - - - -\n");
    while (!esPilaVacia(P))
    {
        P = pop(P);
    }

    return 0;
}