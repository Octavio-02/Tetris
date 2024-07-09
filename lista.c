#include "lista.h"

void crearLista(tLista *lista){
    *lista = NULL;
}


int insertarNodoAlFinal(tLista *lista,const void *elemento,unsigned bytes){
    tNodo *nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return SIN_MEM;
    }

    nue->elemento = malloc(bytes);
    if(!nue->elemento){
        free(nue);
        return SIN_MEM;
    }

    nue->bytes = bytes;
    memcpy(nue->elemento,elemento,bytes);

    while(*lista){
        lista = &(*lista)->sig;
    }

    nue->sig = *lista;
    *lista = nue;

    return 1;
}

int insertarOrdenado(tLista *lista,void *elemento,unsigned bytes,int cmp(const void *a,const void *b)){
    tNodo *nue;

    nue = malloc(sizeof(tNodo));
    if(!nue){
        return SIN_MEM;
    }

    nue->elemento = malloc(bytes);
    if(!nue->elemento){
        free(nue);
        return SIN_MEM;
    }

    nue->bytes = bytes;
    memcpy(nue->elemento,elemento,bytes);

    while(*lista && cmp(elemento,(*lista)->elemento) <= 0){
        lista = &(*lista)->sig;
    }

    nue->sig = *lista;
    *lista = nue;

    return 1;
}

int listaVacia(tLista *lista){
    return *lista == NULL;
}

void vaciarLista(tLista *lista){
    tNodo *elim;

    while(*lista){
        elim = *lista;
        *lista = elim->sig;
        free(elim->elemento);
        free(elim);
    }
}

int sacarDeLista(tLista *lista,void *elemento,unsigned bytes){
    tNodo *elim;
    if(listaVacia(lista)){
        return SIN_ELEM;
    }

    elim = *lista;
    memcpy(elemento,(*lista)->elemento,bytes);

    *lista = elim->sig;
    free(elim->elemento);
    free(elim);

    return 1;
}
