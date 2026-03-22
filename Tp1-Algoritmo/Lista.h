//#include <stdio.h>

typedef char item;

const item indefinido = '@';

struct nodo
{
    item dato;
    nodo *Siguiente;
};

typedef struct{
    struct nodo* L;
    int cantidad;
}Lista;

typedef struct nodo *NLista;

Lista crearLista(){
    Lista nodoLista;
    nodoLista.L = NULL;
    return nodoLista;
}

void mostrar(Lista H){
    while (H.L != NULL)
    {
        printf("%c", H.L->dato);
        H.L = H.L->Siguiente; 
    }
}

bool esListaVacia(Lista H){
    if(H.L == NULL) return true;
    return false;
}

int longitud(Lista H){
    int longitud = 0;
    while (H.L != NULL)
    {
        longitud++;
        H.L = H.L->Siguiente;
    }
    return longitud;
}

item primerElemento(Lista H){
    return H.L->dato;
}

Lista insertar(Lista H, char dato){
    nodo *newNodo = new nodo;
    newNodo->dato = dato;
    newNodo->Siguiente = H.L;
    H.L = newNodo;
    return H;
}
