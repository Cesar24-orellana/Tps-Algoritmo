#include <stdio.h>
#include <stdlib.h>

typedef char item;
const item indefinido = '@';

typedef struct Nodo
{
    item dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct
{
    int ocupado;
    int capacidadMax;
    Nodo *objetos;
    Nodo *primero;
}Baul;

Baul BaulVacio(int capacidad){
    Baul baulVacio;
    baulVacio.capacidadMax = capacidad;
    baulVacio.ocupado = 0;
    baulVacio.objetos = NULL;
    baulVacio.primero = NULL;
    return baulVacio;
}

void Guardar(Baul *B, item dato){
    Nodo *nuevo = new Nodo;
    nuevo->dato = dato;
    nuevo->siguiente = B->objetos;
    B->objetos = nuevo;
    B->ocupado++;
    if(B->primero == NULL) B->primero = nuevo;
}

int Disponible(Baul B){
    return (B.capacidadMax - B.ocupado);
}

void Agregar(Baul *B,item dato){
    if(Disponible(*B)>0)  Guardar(B, dato);
}

int Capacidad(Baul B){
    return B.capacidadMax;
}

bool EstaVacio(Baul B){
    return B.objetos == NULL;
}

item Ultimo(Baul B){
    if(EstaVacio(B)) return indefinido;
    return B.objetos->dato;
}

item Primero(Baul B){
    if(EstaVacio(B)) return indefinido;
    return B.primero->dato;
}

void QuitarUltimo(Baul *B){
    if(!EstaVacio(*B)){
        Nodo *aux=B->objetos;
        if (B->objetos == B->primero) B->primero = NULL;
        B->objetos = aux->siguiente;
        B->ocupado--;
        delete(aux);
    }
}

void Vaciar(Baul *B){
    if (!EstaVacio(*B))
    {
        Nodo *aux = B->objetos;
        Nodo *borrar;
        B->primero = NULL;
        B->ocupado = 0;
        while(aux != NULL){
            borrar = aux;
            aux = aux->siguiente;
            delete(borrar);
        }
    }
    
}

bool Contiene(Baul B, item dato){
    if(EstaVacio(B)) return false;
    Nodo *aux = B.objetos;
    while (aux != NULL && aux->dato != dato)
    {
        aux = aux->siguiente;
    }
    return aux != NULL;
}

int Ocupado(Baul B){
    return B.ocupado;
}

int moverObjetos(Baul *salida, Baul *llegada){
    if(EstaVacio(*salida)) return 0;
    Nodo *auxSalida = salida->objetos;
    Nodo *auxLlegada = llegada->objetos;
    Nodo *mover = auxSalida;
    int cont = 0;                   // Contador

    if(EstaVacio(*llegada)){
        auxSalida = auxSalida->siguiente;
        mover->siguiente = NULL;
        auxLlegada = mover;
        llegada->primero = auxLlegada;
        cont++;
    }

    while (auxSalida != NULL)
    {
        cont++;
        mover = auxSalida;
        auxSalida = auxSalida->siguiente;
        mover->siguiente = auxLlegada;
        auxLlegada = mover;
    }

    llegada->objetos = auxLlegada;
    llegada->ocupado+=cont;
    
    salida->objetos = NULL;
    salida->primero = NULL;
    salida->ocupado = 0;
    
    return cont;
}