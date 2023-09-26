#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "alumno.h"

typedef struct _nodo{
    stAlumno dato;
    struct _nodo* sig;
}nodo;

nodo* inicLista();
nodo* crearNodo(stAlumno alumno);
nodo* agregarEnOrdenPorApellido(nodo* lista, nodo* nuevo);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo);
nodo* archivo2ListaPorApellido(char nombreArchivo[], nodo* lista);
void mostrarLista(nodo* lista);
int sumaEdadesCondiciones(nodo* lista);
nodo* buscaMenorRecursivo(nodo* lista);
void copiarPersonasAOtraLista(char nombreArchivo[],nodo* lista, char l[]);
int contarMayorAUnaEdadLista(nodo* lista, int edadR);
int contarTotalLista(nodo* lista);
stCliente verPrimeroLista(nodo* lista);
nodo* borrarPrimerNodo(nodo* lista);

#endif // LISTA_H_INCLUDED
