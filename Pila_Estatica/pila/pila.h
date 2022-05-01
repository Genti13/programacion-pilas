#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <string.h>

#define TAM_PILA 320
#define MINIMO(X,Y) (X>Y) ? (Y) : (X)

typedef struct
{
    char pila[TAM_PILA];
    unsigned int tope;
} tPila;
typedef struct
{
    char nombre[20];
    unsigned int edad;
} tAlumno;

void crearPila(tPila *);
int pilaLlena(tPila *, unsigned int);
int pilaVacia(tPila *);
int ponerEnPila(tPila *, const void *, unsigned int);
int verTope(tPila *, void *, unsigned int);
int sacarDePila(tPila *, void *, unsigned int);
void vaciarPila(tPila *);

#endif // PILA_H_INCLUDED
