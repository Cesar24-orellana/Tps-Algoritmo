#include <stdio.h>
#include <stdlib.h>

typedef char Item;
const Item Indefinido = '@';

typedef struct Nodo
{
    Item Dato;
    struct Nodo *siguiente;
}Nodo;

typedef struct
{
    int cantidad;
    Item Raiz;
    Nodo *Izq;
    Nodo *Dere;
}AB;

//      Constructora y test

AB ABVacio(){
    AB nuevo;
    nuevo.cantidad = 0;
    nuevo.Izq = NULL;
    nuevo.Dere = NULL;
    nuevo.Raiz = ' ';
    return nuevo;
}

bool esABVacio(AB ab){
    return (ab.Dere == NULL && ab.Izq == NULL);
}

AB armarAB(Nodo izq, Item x, Nodo der){     // NO ME GUSTA NADAAAAAA 😓
    AB nuevo;
    nuevo.cantidad++;
    nuevo.Dere = &der;
    nuevo.Izq = &izq;
    nuevo.Raiz = x;
    return nuevo;
}