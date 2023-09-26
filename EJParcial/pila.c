#include "pila.h"

void inicPila(Pila* pila){
    (*pila) = inicLista();
}

void apilar(Pila* pila, stAlumno dato){
    (*pila) = agregarAlFInal2Bis(*pila,crearNodo(dato));
}

stAlumno tope(Pila* pila){
    return verPrimeroLista(*pila);
}

stAlumno desapilar(Pila* pila){
    stAlumno alumno = verPrimeroLista(*pila);
    (*pila) = borrarPrimerNodo(*pila);
    return alumno;
}

void mostrarPila(Pila* pila){
    mostrarLista(*pila);
}

int pilaVacia(Pila* pila){
    return ((*pila)==NULL);
}
