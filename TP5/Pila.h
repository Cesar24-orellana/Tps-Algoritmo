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

Pila push(Pila P, Item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = P.Tope;
    P.Tope = nuevo;
    P.cantidad++;
    return P;
}

// - - - - - - - - - - - - 

bool esPilaVacia(Pila P){
    return P.Tope == NULL;
}

Pila pop(Pila P){
    if(!esPilaVacia(P)){
        Nodo *aux = P.Tope;
        P.Tope = aux->siguiente;
        P.cantidad--;
        delete(aux);
    }
    return P;
}

Item top(Pila P){
    if(esPilaVacia(P)) return Indefinido;
    return P.Tope->dato;
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

Pila popF(Pila P){
    if(esPilaVacia(P)) return pilaVacia();
    if(P.Tope->siguiente == NULL){
        return pop(P);
    }else {
        return push(popF(pop(P)), top(P));
    }
    // if (!esPilaVacia(*P))
    // {
    //     P->cantidad--;
    //     Nodo *aux;
    //     Nodo *eliminar= P->Tope;
    //     while (eliminar->siguiente != NULL)
    //     {
    //         aux->siguiente;
    //         eliminar = eliminar->siguiente;
    //     }
    //     aux->siguiente = NULL;
    //     delete(eliminar);
    // }
    
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

void Reemp(Pila *P, Item modificar, Item dato){
    if (!esPilaVacia(*P))
    {
        Nodo *aux = P->Tope;
        while (aux != NULL)
        {
            if (aux->dato == modificar)
            {
                aux->dato = dato;
            }
            aux = aux->siguiente;
        }
        
    }
    
}

Pila eliminarX(Pila P, Item dato){
    if(esPilaVacia(P)) return P;

    if (top(P) == dato)
    {
        return eliminarX(pop(P), dato);
    } else{
        return push(eliminarX(pop(P), dato), top(P));
    }
    
}