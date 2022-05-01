#include <stdio.h>
#include <stdlib.h>

#include "pila/pila.h"

int main()
{
    //1 04 41
    tPila pila;
    tAlumno alumno;

    crearPila(&pila);
    printf("1.Este es el tope: %u\n", pila.tope);

    if(!pilaLlena(&pila, sizeof(tAlumno)))
    {
        strcpy(alumno.nombre, "Juan Carlos");
        alumno.edad = 24;
        ponerEnPila(&pila, &alumno, sizeof(tAlumno));
        printf("2.Este es el tope: %u\n", pila.tope);
    }

    if(!pilaLlena(&pila, sizeof(tAlumno)))
    {
        strcpy(alumno.nombre, "Mariela");
        alumno.edad = 56;
        ponerEnPila(&pila, &alumno, sizeof(tAlumno));
        printf("3.Este es el tope: %u\n", pila.tope);
    }

    verTope(&pila,&alumno,sizeof(tAlumno));
    printf("4.Alumno: %s - %u\n", alumno.nombre, alumno.edad);

    sacarDePila(&pila, &alumno, sizeof(alumno));
    printf("5.Alumno: %s - %u\n", alumno.nombre, alumno.edad);

    verTope(&pila,&alumno,sizeof(tAlumno));
    printf("6.Alumno: %s - %u\n", alumno.nombre, alumno.edad);


    return 0;
}
