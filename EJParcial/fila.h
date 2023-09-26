#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "listaDoble.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    nodo2* inicio;
    nodo2* fin;
}Fila;

void inicFila(Fila* fila);
void agregarAFila(Fila* fila, stAlumno alumno);
stAlumno verPrimeroFila(Fila* fila);
stAlumno extrarFila(Fila* fila);
int filaVacia(Fila* fila);
void muestraFila(Fila* fila);



#endif // FILA_H_INCLUDED
