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
    while (!esFilaVacia(G))
    {
        enfila(&F, frente(G));
        G = defila(G);
    }
    return F;
}

Fila extraer_N_esimo(Fila F, int n, Fila G){
    if(esFilaVacia(F) || n > F.cantidad) return F;
    if (n != 0)
    {
        enfila(&G, frente(F));
        return extraer_N_esimo(defila(F), n-1, G);
    }else
    {
        Concatenar(G, defila(F));
        return G;
    }
}

Item final(Fila F){
    return F.final->dato;
}

Fila defilarN(Fila F, int n){
    if(esFilaVacia(F)) return FilaVacia();
    if (n = 0)
    {
        return F;
    }else
    {
        defilarN(defila(F),n-1);
    }
}

bool pertenece(Fila F, Item dato){}