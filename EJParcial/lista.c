#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "lista.h"
#include <string.h>

nodo* inicLista(){
    return NULL;
}

nodo* crearNodo(stAlumno alumno){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato = alumno;
    nuevo->sig = NULL;

    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

nodo* agregarEnOrdenPorApellido(nodo* lista, nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(strcmp(lista->dato.nombre,nuevo->dato.nombre)>0){
            lista = agregarAlPrincipio(lista,nuevo);
        }else{
            nodo* ante = lista;
            nodo* aux = lista->sig;
            while(aux && strcmp(aux->dato.nombre,nuevo->dato.nombre)<0){
                ante = aux;
                aux = aux->sig;
            }
            ante->sig = nuevo;
            nuevo->sig = aux;
        }
    }
    return lista;
}

nodo* archivo2ListaPorApellido(char nombreArchivo[], nodo* lista){
    stAlumno alumno;
    FILE* archi = fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            lista = agregarEnOrdenPorApellido(lista,crearNodo(alumno));
        }
        fclose(archi);
    }
    return lista;
}

void mostrarLista(nodo* lista){
    if(lista){
        mostrarAlumno(lista->dato);
        mostrarLista(lista->sig);
    }
}

int sumaEdadesCondiciones(nodo* lista){
    int total=0;
    if(lista){
        if(lista->dato.edad >= 18 && atoi(lista->dato.dni)%2 == 0){
            total = lista->dato.edad + sumaEdadesCondiciones(lista->sig);
        }else{
            total = sumaEdadesCondiciones(lista->sig);
        }
    }
    return total;
}

nodo* buscaMenorRecursivo(nodo* lista){
    nodo* menor=NULL;
    if(lista->sig){
        menor = buscaMenorRecursivo(lista->sig);
        if(menor->dato.edad > lista->dato.edad){
            menor = lista;
        }
    }else{
        menor=lista;
    }
    return menor;
}

void copiarPersonasAOtraLista(char nombreArchivo[],nodo* lista, char l[]){
    nodo* aux = lista;
    FILE* archi = fopen(nombreArchivo,"w+b");
    if(archi){
        while(aux){
            if(aux->dato.nombre[0]==l[0]){
                fwrite(&aux->dato,sizeof(stAlumno),1,archi);
            }
            aux = aux->sig;
        }
        fclose(archi);
    }
}

int contarMayorAUnaEdadLista(nodo* lista, int edadR){
    int total = 0;
    if(lista){
        if(lista->dato.edad>edadR){
            total = 1 + contarMayorAUnaEdadLista(lista->sig,edadR);
        }else{
            total = contarMayorAUnaEdadLista(lista->sig,edadR);
        }
    }
    return total;
}

int contarTotalLista(nodo* lista){
    int total=0;
    if(lista){
        total = 1 + contarTotalLista(lista->sig);
    }
    return total;
}
