#include <stdlib.h>
#include <stdio.h>

typedef int item;

const item indefinido = 0;

typedef struct
{
    struct nodo *L;
    int cantidad;
} Lista;

struct nodo
{
    item dato;
    struct nodo *Siguiente;
};
typedef struct nodo *NLista;

bool esListaVacia(Lista H)
{                         // O(1)
    return (H.L == NULL); // O(1)
}

item primerElemento(Lista H)
{ // O(1)
    if (esListaVacia(H))
        return indefinido; // condición O(1)
    return H.L->dato;      // O(1)
}

Lista borrar(Lista H) {
    // 1. Verificación de seguridad
    if (H.L == nullptr || H.cantidad == 0) { 
        return H; 
    }

    // 2. Proceso de borrado
    struct nodo *N_Aux = H.L; // Guardamos el nodo a borrar
    H.L = H.L->Siguiente;     // El inicio ahora es el segundo nodo
    H.cantidad--;             // Restamos al contador
    
    delete N_Aux;             // Liberamos memoria
    
    return H;                 // Único punto de salida garantizado
}

// Lista borrar(Lista H){                  // -- O(1)
//     if(esListaVacia(H) || H.cantidad == 0) return H;     // condición O(1)

//     Lista ListAux = H;                  // O(1)
//     struct nodo *N_Aux = ListAux.L;     // O(1)
//     ListAux.L = ListAux.L->Siguiente;       // O(1)
//     ListAux.cantidad--;   //O(1)
//     delete N_Aux;                      // O(1)
//     return ListAux;                     // O(1)
// }

Lista crearLista()
{                          // O(1)
    Lista newLista;        // O(1)
    newLista.cantidad = 0; // O(1)
    newLista.L = NULL;     // O(1)
    return newLista;       // O(1)
}

Lista insertar(Lista H, item dato)
{ // O(1)
    Lista cabecera = H;
    struct nodo *newNodo = new (struct nodo);  // O(1)
    newNodo->dato = dato;                      // O(1)
    newNodo->Siguiente = cabecera.L;           // O(1)
    cabecera.L = newNodo;                      // O(1)
    cabecera.cantidad = cabecera.cantidad + 1; // O(1)
    return cabecera;                           // O(1)
}

// - - - - - - - - - - - - - -

void escribirInversa(int num)
{
    if (num < 10)
        printf("%d", num);
    else
    {
        printf("%d", (num % 10));
        escribirInversa(num / 10);
    }
}

int mayorIterativo(int num)
{
    int mayor = 0;
    while (num > 0)
    {
        if ((num % 10) > mayor)
        {
            mayor = num % 10;
        }
        num = num / 10;
    }
    return mayor;
}

int mayorRecursivo(int num, int mayor)
{
    if (num < 10)
    {
        if (num > mayor)
            return num;
        return mayor;
    }
    else
    {
        if ((num % 10) > mayor)
        {
            mayor = num % 10;
        }
        return mayorRecursivo((num / 10), mayor);
    }
}

bool palabraPalindrome(char cadena[], int inicio, int fin)
{
    if (fin <= inicio)
    {
        return true;
    }
    else
    {
        if (cadena[inicio] == cadena[fin])
        {
            return palabraPalindrome(cadena, inicio + 1, fin - 1);
        }
        else
        {
            return false;
        }
    }
}

bool orden(int vector[], int indice, int fin)
{
    if (indice == fin)
    {
        return true;
    }
    else
    {
        if (vector[indice] <= vector[indice + 1])
        {
            return orden(vector, indice + 1, fin);
        }
        else
        {
            return false;
        }
    }
}

bool perteneceR(Lista H, item dato)
{
    if (esListaVacia(H))
    {
        return false;
    }
    else
    {
        if (H.L->dato == dato)
        {
            return true;
        }
        else
        {
            return perteneceR(borrar(H), dato);
        }
    }
}

item posicionK(Lista H, int posicion, int cantidad)
{
    if (!esListaVacia(H) && cantidad == posicion)
    {
        return (primerElemento(H));
    }
    else
    {
        return posicionK(borrar(H), posicion, cantidad + 1);
    }
}

bool esteContenido(Lista L1, Lista L2)
{
    if (esListaVacia(L1))
    {
        return true;
    }
    else
    {
        if (perteneceR(L2, L1.L->dato))
        {
            return esteContenido(borrar(L1), L2);
        } else{
            return false;
        }
    }
}

bool buscarPar(int V[], int izq, int der, int x, int y){
    if(izq >= der || V == NULL){
        return false;
    }else {
        int medio = (izq+der)/2;
        if (V[medio] == x)
        {
            if (V[medio + 1] == y)
            {
                return true;
            } else{
                return buscarPar(V, medio + 1, der, x ,y);
            }
        } else{
            if (V[medio] > x)
            {
                return buscarPar(V, izq, medio - 1, x, y);
            } else {
                return buscarPar(V, medio + 1, der, x, y);
            }
            
        }
        
    }
}