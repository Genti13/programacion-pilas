#include <stdio.h>
#include <stdlib.h>

#include "pila/pila.h"

int main()
{
    tPila pila;
    tAlumno alumno;

    crearPila(&pila);

    if(!pilaLlena(&pila, sizeof(tAlumno)))
    {
        strcpy(alumno.nombre, "Juan Carlos");
        alumno.edad = 24;
        ponerEnPila(&pila, &alumno, sizeof(tAlumno));

    }

    if(!pilaLlena(&pila, sizeof(tAlumno)))
    {
        strcpy(alumno.nombre, "Mariela");
        alumno.edad = 56;
        ponerEnPila(&pila, &alumno, sizeof(tAlumno));

    }

    verTope(&pila,&alumno,sizeof(tAlumno));
    printf("4.Alumno: %s - %u\n", alumno.nombre, alumno.edad);

    sacarDePila(&pila, &alumno, sizeof(alumno));
    printf("5.Alumno: %s - %u\n", alumno.nombre, alumno.edad);

    verTope(&pila,&alumno,sizeof(tAlumno));
    printf("6.Alumno: %s - %u\n", alumno.nombre, alumno.edad);


    return 0;
}
