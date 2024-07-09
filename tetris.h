#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include <windows.h>
#include <time.h>
#include <conio.h>
#include "cola.h"
#include "lista.h"
#include "colores.h"

#define MARCO_SUP_IZQ_X 35
#define MARCO_SUP_IZQ_Y 2
#define TABLERO_SUP_IZQ_Y 3

#define SIN_PUNTAJES 0

typedef struct{
    int pos;
    int puntos;
    char nombre[15];
}tPuntaje;

typedef struct{
    int id;
    unsigned mapa[4][4];
    int posx;
    int posy;
}tPieza;

int menu(HANDLE consola);
void mostrarCursor(HANDLE consola,WORD estado);
void generarPieza(tPieza *pieza);
void jugar(HANDLE consola);
void dibujarMarco(HANDLE consola);
unsigned colocarPieza(tPieza *pieza,unsigned tablero[20][10]);
void mostrarPieza(HANDLE consola,tPieza *pieza);
void obtenerEstadoTeclas(SHORT currentState[4],SHORT previousState[4],tPieza *pieza,unsigned tablero[20][10],unsigned *detencion);
void borrarPieza(HANDLE consola,tPieza *pieza,unsigned tablero[20][10]);
unsigned colision(tPieza *pieza,unsigned tablero[20][10],unsigned tipo);
void esLineaCompleta(HANDLE consola,unsigned tablero[20][10],int *puntos);
void eliminarFila(HANDLE consola,unsigned tablero[20][10],unsigned fila);
int finDeJuego(unsigned tablero[20][10]);
void bajar(tPieza *pieza, unsigned tablero[20][10]);
void girarHorario(tPieza *pieza,unsigned tablero[20][10]);
void mostrarCola(HANDLE consola,tCola *piezas);
void mostrarPuntos(HANDLE consola,int puntos);
int mostrarPuntajes(HANDLE consola,tLista *lista,COORD coords);
int cargarPuntuacion(HANDLE consola,tLista *lista,int puntos);
int cmpPuntos(const void *a,const void *b);
void trocearNombre(char *linea,tPuntaje *puntaje);
void simularTecla(WORD tecla);
void recorrer(tLista *lista,void mostrarHighscores(HANDLE consola,void *elemento,COORD coords),HANDLE consola,COORD coords);

void imprimirLetraLineaDos(HANDLE consola,COORD coords,char matriz[8][9],int filas,int columnas);
void cortinaGameOver(HANDLE consola);
int cargarLetra(char *ruta,char matriz[8][9]);
void _cargarLetra(char *linea,char matriz[8][9],int fila);

int cargarPieza(char *ruta,tPieza *pieza);
void _cargarPieza(char *linea,tPieza *pieza,int fila);

void establecerColorPieza(HANDLE consola,tPieza *pieza);

void mostrarVelocidad(HANDLE consola,int velocidad);
void acolarPiezas(tCola *piezas,tPieza *pieza);

//ELIMINAR DESPUES
void borrarTablero(HANDLE consola,unsigned tablero[20][10]);
void mostrarTablero(HANDLE consola,unsigned tablero[20][10]);

#endif // TETRIS_H_INCLUDED
