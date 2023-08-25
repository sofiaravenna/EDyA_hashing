//
// Created by Ciro on 24/8/2023.
//

#include <malloc.h>
#include <stdio.h>
#include "hash.h"

TablaHashing *newTablaHashing(int capacidad) {
    TablaHashing * aux = malloc(sizeof (TablaHashing));
    if(aux == NULL){
        printf("ERROR al asignar memoria.\n");
        exit (-1);
    }
    aux->capacidad=capacidad;
    aux->tamanio=0;
    aux->tabla= malloc(sizeof (char * )*capacidad);

    return aux;
}

void imprimir(TablaHashing *tabla) {
    printf("Tabla de hashing: \n");
    for (int i = 0; i < tabla->capacidad; ++i) {
        printf("%d -> %s\n",i,tabla->tabla[i]);
    }
}

int hash(const char *entrada, TablaHashing *tabla) {
    int suma=0;
    for (int i = 0; entrada[i] != '\0'; ++i) {
        suma+=entrada[i];
    }
    return suma%tabla->capacidad;
}

int completa(TablaHashing *tabla) {
    return tabla->capacidad == tabla->tamanio;
}

void agregarEntrada(TablaHashing *tabla, char *entrada) {
    if(completa(tabla)){
        printf("La tabla esta completa.");
        return;
    }
    int posicion = hash(entrada, tabla);
    if(tabla->tabla[posicion] == NULL){
        tabla->tabla[posicion]= entrada;
        tabla->tamanio ++;
    } else{
        redispersionLineal(tabla, entrada, posicion);
    }
}

void redispersionLineal(TablaHashing *tabla, char *entrada, int posicion) {
    if(completa(tabla)){
        printf("La tabla esta completa.");
        exit(-1);
    }
    for (int i = posicion; tabla->tabla[i] !=NULL ; ++i) {
        posicion++;
    }
    tabla->tabla[posicion]=entrada;
}

int existe(TablaHashing *tabla, char *entrada) {
    if(tabla->tamanio == 0){
        printf("La tabla esta vacia.");
        exit(-1);
    }
    int pos= hash(entrada,tabla);
    if(tabla->tabla[pos] == entrada){
        return pos;
    } else{
        for (int i = pos; tabla->tabla[i] != entrada ; ++i) {
            pos++;
        }
    }
    return pos;
}
