#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 300
#define SIN_MEM 0
#define COLA_VACIA 0

#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct{
    char cola[TAM];
    unsigned tamDisp;
    unsigned pri;
    unsigned ult;
}tCola;

void crearCola(tCola *cola);
int acolar(tCola *cola,const void *elemento,unsigned bytes);
int desacolar(tCola *cola,void *elemento,unsigned bytes);
int verTope(tCola *cola,void *elemento,unsigned bytes);
void vaciarCola(tCola *cola);

#endif // COLA_H_INCLUDED
