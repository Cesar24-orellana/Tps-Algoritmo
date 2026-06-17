#include <stdio.h>
#include <stdlib.h>

typedef char Item;
const Item Indefinido = '@';

typedef struct Nodo
{
    Item Raiz;
    struct Nodo *Izq;
    struct Nodo *Der;
}Nodo;

typedef struct Nodo * AB;

//      Constructora y test

AB Liberar(AB ab){
    delete(ab);
    return NULL;
}

AB ABVacio(){
    return NULL;
}

bool esABVacio(AB ab){
    return ab == NULL;
}

AB armarAB(AB izq, Item x, AB der){
    Nodo *nuevo = new Nodo;
    nuevo->Raiz = x;
    nuevo->Izq = izq;
    nuevo->Der = der;
    return nuevo;
}

AB Izquierdo(AB ab){
    if(esABVacio(ab)) return NULL;
    return ab->Izq;
}

Item Raiz(AB ab){
    if(esABVacio(ab)) return Indefinido;
    return ab->Raiz;
}

AB Derecha(AB ab){
    if(esABVacio(ab)) return NULL;
    return ab->Der;
}

bool pertenece(AB ab, Item x){
    if(esABVacio(ab)) return false;
    if(x == Raiz(ab)) return true;
    return pertenece(Izquierdo(ab), x) || pertenece(Derecha(ab), x);
}

bool Iguales(AB ab1, AB ab2){
    if(esABVacio(ab1) && esABVacio(ab2)) return true;
    if(Raiz(ab1) == Raiz(ab2)) return Iguales(Izquierdo(ab1), Izquierdo(ab2)) && Iguales(Derecha(ab1), Derecha(ab2));
    return false;
}

bool EsABHoja(AB t){
    if(esABVacio(t)) return false;
    return esABVacio(Izquierdo(t)) && esABVacio(Derecha(t));
}

AB PodarHojas(AB ab){
    if(esABVacio(ab)) return ABVacio();
    if(EsABHoja(ab)) return Liberar(ab);
    return armarAB(PodarHojas(Izquierdo(ab)), Raiz(ab), PodarHojas(Derecha(ab)));
}

int Altura(AB t){
    if(esABVacio(t) || EsABHoja(t)) return 0;
    return 1 +  __max(Altura(Izquierdo(t)), Altura(Derecha(t)));
}

bool esBalanceado(AB ab){
    if(esABVacio(ab)) return true;
    if(abs(Altura(ab) - Altura(ab)) >= 1) return false;
    return (esBalanceado(Izquierdo(ab)) && esBalanceado(Derecha(ab)));
}

bool estaLLeno(AB ab){
    if(esABVacio(ab) || EsABHoja(ab)) return true;
    if(!EsABHoja(ab)) return (estaLLeno(Izquierdo(ab)) && estaLLeno(Derecha(ab)));
    return false;
}

AB liberarAB(AB T){
    if(esABVacio(T)) return ABVacio();
    if(EsABHoja(T)) return Liberar(T);
    liberarAB(Izquierdo(T));
    liberarAB(Derecha(T));
    return Liberar(T);
}