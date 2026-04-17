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

Lista crearLista(){             // O(1)
    Lista newLista;         // O(1)
    newLista.L = NULL;      // O(1)
    newLista.cantidad = 0;  // O(1)
    return newLista;        // O(1)
}

void mostrar(Lista H){                  // O(n)
    while (H.L != NULL)             // *n IT (n = cant nodos) -> O(n)
    {
        printf("%c", H.L->dato);    // O(1)
        H.L = H.L->Siguiente;       // O(1)
    }
}

bool esListaVacia(Lista H){                 // O(1)
    if(H.L == NULL) return true;        // condición O(1)
    return false;                       // O(1)
}

int longitud(Lista H){                      // O(n)
    int longitud = 0;                   // O(1)
    while (H.L != NULL)         // *n IT (n cant Nodos) -> O(n)
    {
        longitud++;             // O(1)
        H.L = H.L->Siguiente;   // O(1)
    }
    return longitud;                    // O(1)
}

item primerElemento(Lista H){                       // O(1)
    if(esListaVacia(H)) return indefinido;      // condición O(1)
    return H.L->dato;                           // O(1)
}

Lista insertar(Lista H, item dato){         // O(!)
    nodo *newNodo = new nodo;       // O(1)
    newNodo->dato = dato;           // O(1)
    newNodo->Siguiente = H.L;       // O(1)
    H.L = newNodo;                  // O(1)
    H.cantidad = H.cantidad + 1;    // O(1)
    return H;                       // O(1)
}

Lista borrar(Lista H){                  // -- O(1)
    if(esListaVacia(H)) return H;     // condición O(1)
    Lista ListAux = H;                  // O(1)
    struct nodo *N_Aux = ListAux.L;     // O(1)
    ListAux.L = N_Aux->Siguiente;       // O(1)
    ListAux.cantidad == ListAux.cantidad - 1;   //O(1)
    delete(N_Aux);                      // O(1)
    return ListAux;                     // O(1)
}

bool pertenece(Lista H, item dato){                                 // O(n)
    nodo *Aux = H.L;                                    // O(1)
    if (Aux == NULL) return false;                      // condición O(1), O(1)
    
    while(Aux->Siguiente != NULL && Aux->dato != dato){ // *n IT , (n = Cant nodos) -> O(n) 
        Aux = Aux->Siguiente;                       // O(1)
    }
    return Aux->dato == dato;                       // O(1)
}

Lista insertarFinal(Lista H, item dato){
    Lista Cabecera = H;
    nodo *nuevoNodo = new nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->Siguiente = NULL;
    if (Cabecera.L == NULL)
    {
        Cabecera.L = nuevoNodo;
    } else {
        struct nodo *Aux = Cabecera.L;
        while (Aux->Siguiente != NULL)
        {
            Aux = Aux->Siguiente;
        }
        Aux->Siguiente = nuevoNodo;
    }
    Cabecera.cantidad++;
    return Cabecera;
}

char posicionK(Lista *H, int posicion){
    int contador = 0;
    while (!esListaVacia(*H) && contador < posicion)
    {
        *H = borrar(*H);
        contador++;
    }
    return primerElemento(*H);
}