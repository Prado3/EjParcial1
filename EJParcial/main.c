#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "lista.h"
#define ARCHI_ALUMNO "alumno.dat"
#define ARCHI2 "alumnoSeleccionado.dat"
#include <string.h>

void mostrarArchivo(char nombreArchivo[]);

int main()
{
    nodo* lista = inicLista();
    lista = archivo2ListaPorApellido(ARCHI_ALUMNO,lista);
    mostrarLista(lista);
    //int total=0;
    //total=sumaEdadesCondiciones(lista);
    //printf("\n la suma total es: %d", total);
    //nodo* menor=inicLista();
    //menor=buscaMenorRecursivo(lista);
    //mostrarAlumno(menor->dato);
    //char letra[] = "p";
    //copiarPersonasAOtraLista(ARCHI2,lista,letra);
    //mostrarArchivo(ARCHI2);
    int totalEdadMayores=0;
    int totalL = 0;
    float porcentaje=0;
    totalEdadMayores= contarMayorAUnaEdadLista(lista,18);
    totalL = contarTotalLista(lista);
    porcentaje = ((float)totalEdadMayores/(float)totalL)*100;
    printf("\n el pocentaje es de : %2.f porciento", porcentaje);

    return 0;
}

void mostrarArchivo(char nombreArchivo[]){
    stAlumno alumno;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            mostrarAlumno(alumno);
        }
        fclose(archi);
    }
}
