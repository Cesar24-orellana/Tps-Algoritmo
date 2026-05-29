#include <stdio.h>
#include <stdlib.h>

typedef char item;

typedef struct Nodo
{
    item dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct
{
    int capacidad;
    int capacidadMax;
    Nodo *L;
}Baul;
