#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"
#define LONGITUD(x) (sizeof(x) / sizeof((x)[0])) // longitud de un arreglo

int main()
{
    escribirInversa(12345);
    int mayorI = mayorIterativo(183249);
    printf("\n%d", mayorI);
    int mayorR = mayorRecursivo(51457964, 0);
    printf("\n%d", mayorR);
    char palabra[] = "ana";
    if (palabraPalindrome(palabra, 0, strlen(palabra)))
    {
        printf("\nEs palindrome");
    }
    else
    {
        printf("\nNo es palindrome");
    }

    int V[7] = {1, 2, 2, 3, 4, 4, 5};
    if (orden(V, 0, LONGITUD(V)))
    {
        printf("\nEsta Ordenado");
    }
    else
    {
        printf("\nNo esta ordenado");
    }

    Lista H = crearLista();
    for (int i = 0; i < 5; i++)
    {
        H = insertar(H, i + 1);
    }
    if (perteneceR(H, 3))
    {
        printf("\nSi pertenece");
    }
    else
    {
        printf("\nNo pertenece");
    }
    Lista H2 = crearLista();
    for (int i = 0; i < 5; i++)
    {
        H2 = insertar(H2, i + 1);
    }
    printf("\n%d", posicionK(H, 3, 0));

    Lista H3 = crearLista();
    for (int i = 0; i < 7; i++)
    {
        H3 = insertar(H3, i + 3);
        H = insertar(H, i + 1);
    }
    if (esteContenido(H,H3))
    {
        printf("\nEsta contenido");
    } else{
        printf("\nNo esta contenido");
    }


    if (buscarPar(V, 0, LONGITUD(V), 2, 3))
    {
        printf("\nEs continuo");
    } else{
        printf("\nNo es continuo");
    }
    
    return 0;
}
