#include "fila.h"

void inicFila(Fila* fila){
    fila->inicio = inicLista2();
    fila->fin = inicLista2();
}

void agregarAFila(Fila* fila, stAlumno alumno){
    nodo2* nuevo = crearNodo2(alumno);
    fila->fin =agregarAlFInal2Bis(fila,nuevo);
    if(!fila->inicio){
        fila->inicio = nuevo;
    }
    fila->fin = nuevo;
}

stAlumno verPrimeroFila(Fila* fila){
    return verPrimerDoble(fila);
}

stAlumno extrarFila(Fila* fila){
    stAlumno a = verPrimerDoble(fila);
    fila->inicio = borrarPrimerNodoDoble(fila->inicio);
    if(!fila->inicio){
        fila->inicio = inicLista2();
    }
    return a;
}
int filaVacia(Fila* fila){
    return (!fila->inicio);
}
void muestraFila(Fila* fila){
    muestraLista2(fila->inicio);
}
