#include <stdio.h>
#include <stdlib.h>

typedef char Item;
const Item Indefinido = '@';

typedef struct Nodo
{
    Item dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct 
{
    int cantidad;
    Nodo *Tope;
}Pila;

// - - - - - Constructoras Primitivas - - - - - 

Pila pilaVacia(){
    Pila nuevaP;
    nuevaP.cantidad = 0;
    nuevaP.Tope = NULL;
    return nuevaP;
}

void push(Pila *P, Item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = P->Tope;
    P->Tope = nuevo;
    P->cantidad++;
}

// - - - - - - - - - - - - 

void pop(Pila *P){
    if(!esPilaVacia(*P)){
        Nodo *aux = P->Tope;
        P->Tope = aux->siguiente;
        P->cantidad--;
        delete(aux);
    }
}

Item top(Pila P){
    if(esPilaVacia(P)) return Indefinido;
    return P.Tope->dato;
}

bool esPilaVacia(Pila P){
    return P.Tope == NULL;
}

Item Fondo(Pila P){
    if(esPilaVacia(P)) return Indefinido;
    Nodo *aux = P.Tope;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    return aux->dato;
}

void popF(Pila *P){
    if (!esPilaVacia(*P))
    {
        Nodo *aux;
        Nodo *eliminar= P->Tope;
        while (eliminar->siguiente != NULL)
        {
            aux->siguiente;
            eliminar = eliminar->siguiente;
        }
        aux->siguiente = NULL;
        delete(eliminar);
    }
    
}

bool pertenece(Pila P, Item dato){
    if(esPilaVacia(P)) return false;
    Nodo *aux = P.Tope;
    while (aux != NULL && aux->dato != dato)
    {
        aux = aux->siguiente;
    }
    return aux != NULL;
}