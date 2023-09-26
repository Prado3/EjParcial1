#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdint.h>
#include <stdio.h>
#include "lista.h"

#define Pila nodo*

void inicPila(Pila* pila);
void apilar(Pila* pila, stAlumno dato);
stAlumno tope(Pila* pila);
stAlumno desapilar(Pila* pila);
void mostrarPila(Pila* pila);
int pilaVacia(Pila* pila);


#endif // PILA_H_INCLUDED
