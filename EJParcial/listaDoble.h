#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _nodo2{
    stAlumno dato;
    struct _nodo2* ante;
    struct _nodo2* sig;
}nodo2;

nodo2* inicLista2();
nodo2* crearNodo2(stAlumno dato);
nodo2* agregarAlPrincipio2(nodo2* lista, stAlumno dato);
nodo2* agregarAlPpio2(nodo2* lista, nodo2* nuevo);
void muestraNodo2(nodo2* nodo);
void muestraLista2(nodo2* lista);
nodo2* buscarUltimoDoble(nodo2* lista);
nodo2* agregarAlFInal2(nodo2* lista, stAlumno dato);
nodo2* agregarAlFInal2Bis(nodo2* lista, nodo2* nuevo);
nodo2* agregarEnOrdenDoblePorDni(nodo2* lista, stAlumno dato);
nodo2* agregarEnOrden2PorDni(nodo2* lista, nodo2* nuevo);
stAlumno verPrimerDoble(nodo2* lista);
nodo2* borrarPrimerNodoDoble(nodo2* lista);



#endif // LISTADOBLE_H_INCLUDED
