/*
Implementar una lista simplemente enlazada que permita almacenar valores de tipo entero. La lista deberá tener las siguientes operaciones:
Añadir un elemento al final de la lista.
Eliminar un elemento de la lista en una posición dada.
Obtener el elemento de la lista en una posición dada.
Obtener el tamaño de la lista.
Imprimir todos los elementos de la lista.

La lista simplemente enlazada deberá estar implementada utilizando una estructura Nodo, que tendrá dos atributos: un valor entero y un puntero al siguiente nodo.Para la implementación de las operaciones de la lista, se recomienda utilizar punteros a nodo.

*/

#include <stdio.h>
#include <stdlib.h>
struct Nodo {
    int dato;
    struct Nodo *sig;
};
void add(struct Nodo **cab, int dato)
{
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    if (*cab == NULL)
    {
        *cab = nuevo;
    }
    else
    {
        struct Nodo *aux = *cab;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}