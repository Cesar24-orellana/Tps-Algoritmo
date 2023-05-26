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
    int longitud;
    Nodo *final;
    Nodo *frente;
}Fila;

// - - - - - - Constructores - - - - - -

Fila FilaVacia(){
    Fila nueva;
    nueva.longitud = 0;
    nueva.final = NULL;
    nueva.frente = NULL;
    return nueva;
}

bool esFilaVacia(Fila F){
    return (F.final == NULL && F.frente == NULL);
}

Fila enfila(Fila F, Item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    F.longitud++;
    if(esFilaVacia(F)){
        F.final = nuevo;
        F.frente = nuevo;
    } else
    {
        F.final->siguiente = nuevo;
        F.final = F.final->siguiente;
    }
    return F;
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
    F.longitud--;
    delete(eliminar);
    return F;
}

Fila Concatenar(Fila F, Fila G){
    if(esFilaVacia(F)) return G;
    if(esFilaVacia(G)) return F;
    F.final->siguiente = G.frente;
    F.final = G.final;
    F.longitud += G.longitud;
    G = FilaVacia();
    return F;
}

Fila extraer_N_esimo(Fila F, int n, Fila G){
    if(esFilaVacia(F) || n > F.longitud) return F;
    if (n != 0)
    {
        G = enfila(G, frente(F));
        return extraer_N_esimo(defila(F), n-1, G);
    }else
    {
        G = Concatenar(G, defila(F));
        F = FilaVacia();
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
        return defilarN(defila(F),n-1);
    }
}

bool pertenece(Fila F, Item dato){
    if(esFilaVacia(F)) return false;
    Nodo *aux = F.frente;
    while (aux != NULL && aux->dato != dato)
    {
        aux = aux->siguiente;
    }
    return aux != NULL;
}

Fila singular(Fila F){
    if(esFilaVacia(F)) return FilaVacia();
    Fila G = FilaVacia();
    Item x;
    while(!esFilaVacia(F)){
        x = frente(F);
        if(!pertenece(G, x)){
            G = enfila(G,x);
        }
        F = defila(F);
    }
    return G;
}

void mostrar(Fila F){
    Nodo *aux = F.frente;
    printf("[ ");
    while (aux != NULL)
    {
        printf("%d ",aux->dato);
        aux = aux->siguiente;
    }
    printf("]\n");
}