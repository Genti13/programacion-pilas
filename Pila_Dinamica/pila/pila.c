#include "pila.h"

void crearPila(tPila * p)
{
    *p = NULL;

}

int pilaLlena(tPila * p, unsigned int cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void * info = malloc(sizeof(cantBytes));

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int pilaVacia(tPila * p)
{
    return *p == NULL;
}

int ponerEnPila(tPila * p, const void * d, unsigned int cantBytes)
{
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));

    if(nue==NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p=nue;

    return 1;
}

int verTope(tPila * p, void * d, unsigned int cantBytes)
{
    if(!*p)
    {
        return 0;
    }

    memcpy(d, (*p)->info, MINIMO(cantBytes, (*p)->tamInfo));
    return 1;
}
int sacarDePila(tPila * p, void * d, unsigned int cantBytes)
{
    tNodo * aux = *p;

    if(!aux)
    {
        return 0;
    }

    *p = aux->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));

    free(aux->info);
    free(aux);

    return 1;

}
void vaciarPila(tPila * p)
{
    tNodo * aux;

    while(*p)
    {
        aux = *p;
        *p = aux->sig;

        free(aux->info);
        free(aux);
    }
}
