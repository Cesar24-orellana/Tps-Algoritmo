#include <stdlib.h>
#include <stdio.h>

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

bool orden(int vector[], int indice, int fin){
    if (indice == fin)
    {
        return true;
    } else{
        if (vector[indice] <= vector[indice+1])
        {
            return orden(vector, indice+1, fin);
        } else{
            return false;
        }
        
    }
    
}
