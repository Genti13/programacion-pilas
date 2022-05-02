#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) (X) > (Y) ? (Y) : (X)

typedef struct
{
    char nombre[20];
    unsigned int edad;

}tAlumno;

typedef struct sNodo
{
    void * info;
    unsigned tamInfo;
    struct sNodo * sig;
} tNodo;

typedef tNodo * tPila;

void crearPila(tPila *);
int pilaLlena(tPila *, unsigned int);
int pilaVacia(tPila *);
int ponerEnPila(tPila *, const void *, unsigned int);
int verTope(tPila *, void *, unsigned int);
int sacarDePila(tPila *, void *, unsigned int);
void vaciarPila(tPila *);


#endif // PILA_H_INCLUDED
