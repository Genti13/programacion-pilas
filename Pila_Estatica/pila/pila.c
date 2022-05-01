#include "pila.h"

void crearPila(tPila * p)
{
    p->tope = TAM_PILA;
}

///Que el espacio disponible sea suficiente para el tamano de lo que quiero grabar
int pilaLlena(tPila * p, unsigned int cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned int);
}

int pilaVacia(tPila * p)
{
    return p->tope == TAM_PILA;
}

///Moverme para atras la cantidad ed bytes del dato & copiar esos bytes.
///Moverme para atras la cantida de bytes del tamano de bytes & copiar eso bytes.
int ponerEnPila(tPila * p, const void * d, unsigned int cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned int))
    {
        return 0;
    }

    p->tope -= cantBytes;
    memcpy(p->pila + p ->tope, d, cantBytes);
    p->tope -= sizeof(unsigned int);
    memcpy(p->pila + p ->tope, &cantBytes, sizeof(unsigned int));

    return 1;
}

int verTope(tPila * p, void * d, unsigned int cantBytes)
{
    unsigned int tamInfo;

    if(p->tope == TAM_PILA)
    {
        return 0;
    }

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned int));
    memcpy(d, p->pila + p->tope + sizeof(unsigned int), MINIMO(cantBytes, tamInfo));
    return 1;
}
int sacarDePila(tPila * p, void * d, unsigned int cantBytes)
{
    unsigned int tamInfo;

    if(p->tope == TAM_PILA)
    {
        return 0;
    }

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned int));
    p->tope += sizeof(unsigned int);
    memcpy(d, p->pila + p->tope + sizeof(unsigned int), MINIMO(cantBytes, tamInfo));
    p->tope += tamInfo;
    return 1;

}
void vaciarPila(tPila * p)
{
    p->tope = TAM_PILA;
}
