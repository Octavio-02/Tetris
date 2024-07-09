#include "tetris.h"

int main(){
    HANDLE consola;
    consola = GetStdHandle(STD_OUTPUT_HANDLE);
    int opcionMenu;

    do{
        opcionMenu=menu(consola);
        fflush(stdin);
        if(opcionMenu == 1){
            mostrarCursor(consola,FALSE);
            //Desactivamos la posibilidad de seleccionar el texto de la consola
            //Ya que puede detener la ejecucuión del programa
            SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS);
            jugar(consola);
        }
        if(opcionMenu == 2){
            system("cls");
            mostrarPuntajesMenu(consola);
        }
    }while(opcionMenu != 3);

    return 0;
}
