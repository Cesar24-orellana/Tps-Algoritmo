#include <stdio.h>
#include <stdlib.h>

#include "Pila.h"

int main(){
    printf("- - - - - - Inicio del programa - - - - - - - \n");
    printf("1. Inicializo una pila\n");
    Pila P = pilaVacia();
    printf("2. La pila esta vacia?\n");
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
    printf("6. Eliminar el dato del tope de la pila\n");
    P = pop(P);
    printf("En el tope de la pila se encuentra el dato: %c\n", top(P));
    printf("7. El dato del fondo de la pila es: %c\n", Fondo(P));
    printf("8. Eliminar el dato del fondo\n");
    P = popF(P);
    printf("El dato del fondo de la pila es: %c\n", Fondo(P));
    printf("9. El dato (d) pertenece a la pila?\n");
    if (pertenece(P, 'd'))
    {
        printf("Si pertenece\n");
    }else{
        printf("No pertenece\n");
    }
    printf("10. Eliminar el dato (d) de la pila\n");
    P = eliminarX(P, 'd');
    printf("11. El dato (d) pertenece a la pila?\n");
    if (pertenece(P, 'd'))
    {
        printf("Si pertenece\n");
    }else{
        printf("No pertenece\n");
    }
    printf("11. El dato (e) pertenece a la pila?\n");
    if (pertenece(P, 'e'))
    {
        printf("Si pertenece\n");
    }else{
        printf("No pertenece\n");
    }
    printf("12. Modificar el/los datos (e) por el dato (z)\n");
    Reemp(&P,'e','z');
    printf("13. El dato (b) pertenece a la pila?\n");
    if (pertenece(P, 'b'))
    {
        printf("Si pertenece\n");
    }else{
        printf("No pertenece\n");
    }
    printf("14. Eliminar el dato (b) de la pila\n");
    P = eliminarX(P, 'b');
    printf("El dato del fondo de la pila es: %c", Fondo(P));
    printf("15. Eliminar el dato del fondo\n");
    P = popF(P);
    printf("El dato del fondo de la pila es: %c\n", Fondo(P));
    getchar();
    printf("- - - - Liberar la memorio - - - -\n");
    while (!esPilaVacia(P))
    {
        P = pop(P);
    }
    printf("- - - - - Fin del Programa - - - - -");
    return 0;
}