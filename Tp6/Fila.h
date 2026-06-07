#include <stdio.h>
#include <stdlib.h>

typedef int Item;
const Item Indefinido = -9999;

typedef struct Nodo
{
    Item dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct
{
    int cantidad;
    Nodo *final;
    Nodo *frente;
}Fila;

// - - - - - - Constructores - - - - - -

Fila FilaVacia(){
    Fila nueva;
    nueva.cantidad = 0;
    nueva.final = NULL;
    nueva.frente = NULL;
    return nueva;
}

bool esFilaVacia(Fila F){
    return (F.final == NULL && F.frente == NULL);
}

void enfila(Fila *F, Item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    F->cantidad++;
    if(esFilaVacia(*F)){
        F->final = nuevo;
        F->frente = nuevo;
    } else
    {
        F->final->siguiente = nuevo;
    }
}

Item frente(Fila F){
    if(esFilaVacia(F)) return Indefinido;
    return F.frente->dato;
}

Fila defila(Fila F){
    if(esFilaVacia(F)) return FilaVacia();
    Nodo *eliminar = F.frente;
    if(F.frente == F.final) return FilaVacia();
    F.frente = F.frente->siguiente;
    F.cantidad--;
    delete(eliminar);
    return F;
}

Fila Concatenar(Fila F, Fila G){
    if(esFilaVacia(F)) return G;
    if(esFilaVacia(G)) return F;
    while (!esFilaVacia(F))
    {
        enfila(&G, frente(F));
        F = defila(F);
    }
    return G;
}

