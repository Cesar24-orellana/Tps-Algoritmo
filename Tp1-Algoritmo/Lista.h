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
    Lista newLista;
    newLista.L = NULL;
    newLista.cantidad = 0;
    return newLista;
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
    if(esListaVacia(H)) return indefinido;
    return H.L->dato;
}

Lista insertar(Lista H, item dato){
    nodo *newNodo = new nodo;
    newNodo->dato = dato;
    newNodo->Siguiente = H.L;
    H.L = newNodo;
    H.cantidad = H.cantidad + 1;
    return H;
}

Lista borrar(Lista H){
    if(esListaVacia(H)) return H;
    Lista ListAux = H;
    struct nodo *N_Aux = ListAux.L; 
    ListAux.L = N_Aux->Siguiente;
    ListAux.cantidad == ListAux.cantidad - 1;
    delete(N_Aux);
    return ListAux;
}

bool pertenece(Lista H, item dato){
    nodo *Aux = H.L;
    if (Aux == NULL) return false;
    
    while(Aux->Siguiente != NULL && Aux->dato != dato){
        Aux = Aux->Siguiente;
    }
    return Aux->dato == dato;
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