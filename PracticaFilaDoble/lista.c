#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
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

nodo* agregarAlPrincipio(nodo* lista,nodo* nuevo){
    nuevo->sig = lista;
    return nuevo;
}

nodo* agregarEnOrdenPorNombre(nodo* lista,nodo* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(strcmp(nuevo->dato.nombre,lista->dato.nombre)<0){
            lista = agregarAlPrincipio(lista,nuevo);
        }else{
            nodo* ante = lista;
            nodo* aux = lista->sig;
            while(aux && strcmp(nuevo->dato.nombre,aux->dato.nombre)>0){
                ante = aux;
                aux = aux->sig;
            }
            ante->sig = nuevo;
            nuevo->sig = aux;
        }
    }
    return lista;
}

nodo* archivo2Lista(char nombreArchivo[], nodo* lista){
    stAlumno alumno;
    FILE* archi = fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&alumno,sizeof(stAlumno),1,archi)>0){
            lista = agregarEnOrdenPorNombre(lista, crearNodo(alumno));
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

int sumarEdadesRecursivaCondiciones(nodo* lista){
    int total = 0;
    if(lista){
        if(atoi(lista->dato.dni)>=18 && atoi(lista->dato.dni)%2==0){
            total = lista->dato.edad + sumarEdadesRecursivaCondiciones(lista->sig);
        }else{
            total = sumarEdadesRecursivaCondiciones(lista->sig);
        }
    }
    return total;
}

nodo* buscaMenorRecursiva(nodo* lista){
    nodo* menor=NULL;
    if(lista->sig){
        menor = buscaMenorRecursiva(lista->sig);
        if(menor->dato.edad>lista->dato.edad){
            menor = lista;
        }
    }else{
        menor = lista;
    }
    return menor;
}

nodo* copiarPersonasEmpiecenConLetra(nodo* lista, char letra[]){
    nodo* aux = NULL;
    while(lista){
        if(letra[0]==lista->dato.nombre[0]){
            aux = agregarAlPrincipio(aux,crearNodo(lista->dato));
        }
        lista = lista->sig;
    }
    return aux;
}

int contarMayoresAUnaEdad(nodo* lista, int edad){
    int total = 0;
    if(lista){
        if(lista->dato.edad>edad){
            total = 1 + contarMayoresAUnaEdad(lista->sig,edad);
        }else{
            total = contarMayoresAUnaEdad(lista->sig,edad);
        }
    }
    return total;
}

