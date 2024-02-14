/*
Ejercicio 1
Desarrolle la función que recibe por parámetro una lista de números enteros desordenados entre 0 y 127. La función deberá eliminar todos los elementos repetidos en la lista. Nota: Se valora el uso de tablas de hashing para reducir la complejidad. Declaración:
void eliminarDuplicadosLista(Nodo **cab)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *prev;
} nodo;

typedef struct Nodo Nodo;
int presente[127] = {0};
void eliminarDuplicadosLista(nodo **cab)
{
    nodo *aux = *cab;
    while(aux->sig != NULL) {
        if (!presente[aux->dato])
            presente[aux->dato] = 1;
        else
        {
            aux->prev->sig = aux->sig;
            aux->sig->prev = aux->prev;
        }
        aux = aux->sig;
    }
}
struct Nodo *newNodo(int dato)
{
    struct Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->sig = NULL;
    nuevo->prev = NULL;
    return nuevo;
}

void insertarNodo(struct Nodo **cab, int dato)
{
    struct Nodo *nuevo = newNodo(dato);
    nuevo->sig = *cab;
    if (*cab != NULL)
        (*cab)->prev = nuevo;
    *cab = nuevo;
}
void printList(struct Nodo *n)
{
    while (n != NULL)
    {
        printf("%d ", n->dato);
        n = n->sig;
    }
    printf("\n");
}

int main() {
    struct Nodo *cab = NULL;
    insertarNodo(&cab, 1);
    insertarNodo(&cab, 2);
    insertarNodo(&cab, 32);
    insertarNodo(&cab, 18);
    insertarNodo(&cab, 78);
    insertarNodo(&cab, 90);
    insertarNodo(&cab, 32);
    insertarNodo(&cab, 18);
    insertarNodo(&cab, 78);
    insertarNodo(&cab, 90);
    insertarNodo(&cab, 32);
    printList(cab);
    eliminarDuplicadosLista(&cab);
    printList(cab);
    return 0;
}
