#include "cola.h"

void crearCola(tCola *cola){
    cola->tamDisp = TAM;
    cola->pri = 0;
    cola->ult = 0;
}

int acolar(tCola *cola,const void *elemento,unsigned bytes){
    unsigned ini;
    unsigned fin;

    if(cola->tamDisp < sizeof(unsigned) + bytes){
        return SIN_MEM;
    }

    cola->tamDisp -= bytes + sizeof(unsigned);

    ini = MIN(TAM - cola->ult,sizeof(unsigned));
    if(ini != 0){
        memcpy(cola->cola + cola->ult,&bytes,ini);
    }
    fin = sizeof(unsigned)-ini;
    if(fin != 0){
        memcpy(cola->cola,((char*)&bytes)+ini,fin);
    }
    cola->ult = fin ? fin : cola->ult + ini;

    ini = MIN(TAM - cola->ult,bytes);
    if(ini != 0){
        memcpy(cola->cola + cola->ult,elemento,ini);
    }
    fin = bytes - ini;
    if(fin != 0){
        memcpy(cola->cola,((char*)elemento)+ini,fin);
    }

    cola->ult = fin ? fin : cola->ult + ini;

    return 1;
}

int desacolar(tCola *cola,void *elemento,unsigned bytes){
    unsigned ini;
    unsigned fin;
    unsigned tamAux;
    unsigned tamRecup;

    if(cola->tamDisp == TAM){
        return COLA_VACIA;
    }

    ini = MIN(TAM-cola->pri, sizeof(unsigned));
    if(ini != 0){
        memcpy(&tamAux,cola->cola + cola->pri,ini);
    }
    fin = sizeof(unsigned) - ini;
    if(fin != 0){
        memcpy(((char*)&tamAux)+ini,cola->cola,fin);
    }

    cola->pri = fin ? fin : cola->pri + ini;

    tamRecup = MIN(tamAux,bytes);
    ini = MIN(TAM - cola->pri,tamRecup);
    if(ini!=0){
        memcpy(elemento,cola->cola+cola->pri,ini);
    }
    fin = tamRecup - ini;
    if(fin!=0){
        memcpy(((char*)elemento)+ini,cola->cola,fin);
    }

    cola->pri = (cola->pri + tamAux) % TAM;
    cola->tamDisp += tamAux + sizeof(unsigned);

    return 1;
}

int verTope(tCola *cola,void *elemento,unsigned bytes){
    unsigned ini;
    unsigned fin;
    unsigned tamAux;
    unsigned tamRecup;
    unsigned prim;

    if(cola->tamDisp == TAM){
        return COLA_VACIA;
    }

    ini = MIN(TAM-cola->pri, sizeof(unsigned));
    if(ini != 0){
        memcpy(&tamAux,cola->cola + cola->pri,ini);
    }
    fin = sizeof(unsigned) - ini;
    if(fin != 0){
        memcpy(((char*)&tamAux)+ini,cola->cola,fin);
    }

    prim = fin ? fin : cola->pri + ini;

    tamRecup = MIN(tamAux,bytes);
    ini = MIN(TAM - prim,tamRecup);
    if(ini!=0){
        memcpy(elemento,cola->cola + prim,ini);
    }
    fin = tamRecup - ini;
    if(fin!=0){
        memcpy(((char*)elemento)+ini,cola->cola,fin);
    }

    return 1;
}

void vaciarCola(tCola *cola){
    cola->tamDisp = TAM;
    cola->pri = cola->ult;
}
