#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "alumno.h"

typedef struct _nodo{
    stAlumno dato;
    struct _nodo* sig;
}nodo;

nodo* inicLista();
nodo* crearNodo(stAlumno alumno);
nodo* agregarEnOrdenPorNombre(nodo* lista,nodo* nuevo);
nodo* archivo2Lista(char nombreArchivo[], nodo* lista);
void mostrarLista(nodo* lista);
nodo* agregarAlPrincipio(nodo* lista,nodo* nuevo);
int sumarEdadesRecursivaCondiciones(nodo* lista);
nodo* buscaMenorRecursiva(nodo* lista);
nodo* copiarPersonasEmpiecenConLetra(nodo* lista, char letra[]);
int contarMayoresAUnaEdad(nodo* lista, int edad);

#endif // LISTA_H_INCLUDED
