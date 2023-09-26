#include "listaDoble.h"

nodo2* inicLista2(){
    return NULL;
}

nodo2* crearNodo2(stAlumno dato){
    nodo2* nuevo = (nodo2*) malloc(sizeof(nodo2));
    nuevo->dato = dato;
    nuevo->ante = NULL;
    nuevo->sig = NULL;
    return nuevo;
}

nodo2* agregarAlPrincipio2(nodo2* lista, stAlumno dato){
    return agregarAlPpio2(lista,crearNodo2(dato));
}

nodo2* agregarAlPpio2(nodo2* lista, nodo2* nuevo){
    nuevo->sig = lista;
    if(lista){
        lista->ante=nuevo;
    }
    return nuevo;
}

void muestraNodo2(nodo2* nodo){
    mostrarAlumno(nodo->dato);
}

void muestraLista2(nodo2* lista){
    nodo2* aux = lista;
    while(aux){
        muestraNodo2(aux);
        aux = aux->sig;
    }
}

nodo2* buscarUltimoDoble(nodo2* lista){
    if(lista){
        while(lista->sig){
            lista = lista->sig;
        }
    }
    return lista;
}

nodo2* agregarAlFInal2(nodo2* lista, stAlumno dato){
    return agregarAlFInal2Bis(lista,crearNodo2(dato));
}

nodo2* agregarAlFInal2Bis(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        nodo2* ultimo = buscarUltimoDoble(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }
    return lista;
}

nodo2* agregarEnOrdenDoblePorDni(nodo2* lista, stAlumno dato){
    return agregarEnOrden2PorDni(lista,crearNodo2(dato));
}
nodo2* agregarEnOrden2PorDni(nodo2* lista, nodo2* nuevo){
    if(!lista){
        lista = nuevo;
    }else{
        if(atoi(lista->dato.dni)>=atoi(nuevo->dato.dni)){
            nuevo->sig = lista;
            lista->ante = nuevo;
        }else{
            nodo2* aux = lista->sig;
            nodo2* ante = lista;
            while(aux && atoi(aux->dato.dni)<atoi(nuevo->dato.dni)){
                ante = aux;
                aux = aux->sig;
            }
            nuevo->sig = aux;
            nuevo->ante = ante;
            ante->sig = nuevo;
            if(aux){
                aux->ante = nuevo;
            }
        }
    }
    return lista;
}

stAlumno verPrimerDoble(nodo2* lista){
    return lista->dato;
}

nodo2* borrarPrimerNodoDoble(nodo2* lista){
    if(lista){
        nodo2* aBorrar = lista;
        lista = lista->sig;
        free(aBorrar);
        if(lista){
            lista->ante = NULL;
        }
    }
    return lista;
}
