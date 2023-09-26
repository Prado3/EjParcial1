#include <stdio.h>
#include <stdlib.h>
#define ARCHI_ALUMNO "alumno.dat"
#include "alumno.h"
#include "lista.h"

int main()
{
    nodo* lista = inicLista();
    lista = archivo2Lista(ARCHI_ALUMNO,lista);
    //mostrarLista(lista);
    int total=0;
    total  = sumarEdadesRecursivaCondiciones(lista);
    //printf("\n %d",total);
    nodo* menor = inicLista();
    menor = buscaMenorRecursiva(lista);
    //mostrarAlumno(menor->dato);
    nodo* aux = inicLista();
    aux = copiarPersonasEmpiecenConLetra(lista,"p");
    //mostrarLista(aux);
    int edadTotal = contarMayoresAUnaEdad(lista,0);
    int edadCond = contarMayoresAUnaEdad(lista, 18);
    float promedio = ((float)edadCond/(float)edadTotal)*100;
    printf("\n el promedio es de %2.f porciento", promedio);

    return 0;
}
