//
// Created by Ciro on 24/8/2023.
//

#ifndef EDYA_HASHING_HASH_H
#define EDYA_HASHING_HASH_H
typedef struct tabla{
    int capacidad;
    int tamanio;
    char ** tabla;
}TablaHashing;

TablaHashing * newTablaHashing(int capacidad);
void imprimir(TablaHashing *tabla);
int hash(const char * entrada, TablaHashing * tabla);
int completa(TablaHashing * tabla);
void agregarEntrada(TablaHashing * tabla, char * entrada);
void redispersionLineal(TablaHashing * tabla, char * entrada, int posicion);
int existe(TablaHashing *tabla, char *entrada);
#endif //EDYA_HASHING_HASH_H
