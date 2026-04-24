#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"
#define LONGITUD(x) (sizeof(x)/sizeof((x)[0])) // longitud de un arreglo

int main(){
    escribirInversa(12345);
    int mayorI = mayorIterativo(183249);
    printf("\n%d", mayorI);
    int mayorR = mayorRecursivo(51457964, 0);
    printf("\n%d", mayorR);
    char palabra[] = "ana";
    if(palabraPalindrome(palabra, 0, strlen(palabra))){
        printf("\nEs palindrome");
    } else{
        printf("\nNo es palindrome");
    }

    int V[7] = {1,2,2,3,4,4,5};
    if(orden(V, 0, LONGITUD(V))){
        printf("\nEsta Ordenado");
    } else{
        printf("\nNo esta ordenado");
    }
    return 0;
}

