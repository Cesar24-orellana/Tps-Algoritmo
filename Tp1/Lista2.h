#include <stdio.h>
#include <stdlib.h>

typedef char item;
const item indefinido = '@';

struct Nodo{
    item dato;
    struct Nodo * siguiente;
};

typedef struct
{
    int cantidad;
    Nodo *L;
}Lista;

// typedef struct nodo *PLista;

void crearLista(Lista *H){
    H->cantidad = 0;
    H->L = NULL;
}

void mostrar(Lista H){
    Nodo *aux = H.L;
    while (aux != NULL)
    {
        printf("%c\n", aux->dato);
        aux = aux->siguiente;
    }
}

bool esListaVacia(Lista H){
    if(H.cantidad == 0 && H.L == NULL) return true;
    return false;
}

int longitud(Lista H){
    return H.cantidad;
}

item primerElemento(Lista H){
    if(esListaVacia(H)) return indefinido;
    return H.L->dato;
}

void insertar(Lista *H, item dato){
    Nodo * nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = H->L;
    H->L = nuevo;
    H->cantidad++;
}

void borrar(Lista *H){
    if (H->L != NULL)
    {
        Nodo *borrar = H->L;
        H->L = H->L->siguiente;
        H->cantidad--;
        delete(borrar);
    }
}

bool pertenece(Lista H, item dato){
    Nodo *aux = H.L;
    while (aux!=NULL)
    {
        if (aux->dato == dato)
        {
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}

void insertarFinal(Lista *H, item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    if (esListaVacia(*H))
    {
        Nodo *aux1 = H->L;
        Nodo *aux2;
        while (aux1 != NULL)
        {
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }
        aux2->siguiente = nuevo;
    }
    
}

item posicionK(Lista *H, int num){
    int contador = 1;
    while (!esListaVacia(*H) || contador < num)
    {
        borrar(H);
        contador++;
    }
    return primerElemento(*H);
    
}
