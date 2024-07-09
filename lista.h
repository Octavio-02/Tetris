#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "cola.h"

#define SIN_ELEM 0

typedef struct sNodo{
    unsigned bytes;
    void *elemento;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;

int listaVacia(tLista *lista);
void crearLista(tLista *lista);
int insertarNodoAlFinal(tLista *lista,const void *elemento,unsigned bytes);
void vaciarLista(tLista *lista);
int sacarDeLista(tLista *lista,void *elemento,unsigned bytes);
int insertarOrdenado(tLista *lista,void *puntaje,unsigned bytes,int cmp(const void *a,const void *b));

#endif // LISTA_H_INCLUDED
