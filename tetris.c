#include "tetris.h"

void mostrarPuntajesMenu(HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;
    tLista puntajes;

    GetConsoleScreenBufferInfo(consola,&ventana);

    coords.X = ventana.dwSize.X / 2 - 10;
    coords.Y = 3;

    crearLista(&puntajes);
    mostrarPuntajes(consola,&puntajes,coords);

    coords.X = ventana.dwSize.X / 2 - 22;
    coords.Y = 20;
    SetConsoleCursorPosition(consola,coords);
    system("pause");
}

int menu(HANDLE consola){
    int opcionMenu;
    COORD coords;
    char matriz[8][9];
    CONSOLE_SCREEN_BUFFER_INFO ventana;

    GetConsoleScreenBufferInfo(consola,&ventana);
    do{
        coords.X = (ventana.dwSize.X / 2 - 31);
        coords.Y = 3;
        system("cls");

        mostrarCursor(consola,TRUE);

        //IMPRESION DE LA PRIMERA LÍNEA DEL TÍTULO
        SetConsoleCursorPosition(consola,coords);
        SetConsoleTextAttribute(consola,FG_BLANCO);
        printf("==========================================================");
        //IMPRESIÓN DE LETRAS POR LÍNEA
        coords.Y++;
        cargarLetra("Letras/t.txt",matriz);
        SetConsoleTextAttribute(consola,FG_ROJO);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        coords.X+=11;
        cargarLetra("Letras/e.txt",matriz);
        SetConsoleTextAttribute(consola,FG_CELESTE);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        coords.X+=11;
        cargarLetra("Letras/t.txt",matriz);
        SetConsoleTextAttribute(consola,FG_VIOLETA);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        coords.X+=11;
        cargarLetra("Letras/r.txt",matriz);
        SetConsoleTextAttribute(consola,FG_AMARILLO);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        coords.X+=11;
        cargarLetra("Letras/i.txt",matriz);
        SetConsoleTextAttribute(consola,FG_VERDE);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        coords.X+=5;
        cargarLetra("Letras/s.txt",matriz);
        SetConsoleTextAttribute(consola,FG_AZUL);
        imprimirLetraLineaDos(consola,coords,matriz,8,9);

        //IMPRESIÓN DE LA ÚTLIMA LÍNEA DEL TÍTULO
        coords.Y+=8;
        coords.X = (ventana.dwSize.X / 2 - 31);
        SetConsoleCursorPosition(consola,coords);
        SetConsoleTextAttribute(consola,FG_BLANCO);
        printf("==========================================================");

        coords.Y+=2;
        coords.X = (ventana.dwSize.X / 2 - 4);
        SetConsoleCursorPosition(consola,coords);
        printf("1.Jugar");

        coords.Y++;
        coords.X = (ventana.dwSize.X / 2 - 7);
        SetConsoleCursorPosition(consola,coords);
        printf("2.Ver Puntajes");

        coords.Y++;
        coords.X = (ventana.dwSize.X / 2 - 4);
        SetConsoleCursorPosition(consola,coords);
        printf("3.Salir");

        coords.Y+=3;
        coords.X = (ventana.dwSize.X / 2 - 4);
        SetConsoleCursorPosition(consola,coords);
        printf("Opcion: ");
        scanf("%d",&opcionMenu);
    }while(opcionMenu<1||opcionMenu>3);

    return opcionMenu;
}

void cortinaGameOver(HANDLE consola){
    COORD coords;
    char matriz[8][9];
    CONSOLE_SCREEN_BUFFER_INFO ventana;

    GetConsoleScreenBufferInfo(consola,&ventana);

    system("cls");
    coords.X = (ventana.dwSize.X / 2 - 44);
    coords.Y = 3;
    mostrarCursor(consola,TRUE);
    //IMPRESION DE LA PRIMERA LÍNEA DEL TÍTULO
    SetConsoleCursorPosition(consola,coords);
    SetConsoleTextAttribute(consola,FG_BLANCO);
    printf("========================================================================================\n\n");
    //IMPRESIÓN DE LETRAS POR LÍNEA
    coords.Y++;
    cargarLetra("Letras/g.txt",matriz);
    SetConsoleTextAttribute(consola,FG_ROJO);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/a.txt",matriz);
    SetConsoleTextAttribute(consola,FG_CELESTE);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/m.txt",matriz);
    SetConsoleTextAttribute(consola,FG_VIOLETA);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/e.txt",matriz);
    SetConsoleTextAttribute(consola,FG_AMARILLO);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=13;
    cargarLetra("Letras/o.txt",matriz);
    SetConsoleTextAttribute(consola,FG_VERDE);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/v.txt",matriz);
    SetConsoleTextAttribute(consola,FG_AZUL);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/e.txt",matriz);
    SetConsoleTextAttribute(consola,FG_ROJO);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);

    coords.X+=11;
    cargarLetra("Letras/r.txt",matriz);
    SetConsoleTextAttribute(consola,FG_CELESTE);
    imprimirLetraLineaDos(consola,coords,matriz,8,9);
    //IMPRESIÓN DE LA ÚTLIMA LÍNEA DEL TÍTULO
    coords.Y+=8;
    coords.X=(ventana.dwSize.X / 2 - 44);;
    SetConsoleCursorPosition(consola,coords);
    SetConsoleTextAttribute(consola,FG_BLANCO);
    printf("========================================================================================\n\n");

    coords.Y=15;
    coords.X=(ventana.dwSize.X / 2 - 20);
    SetConsoleCursorPosition(consola,coords);
}

void _cargarLetra(char *linea,char matriz[8][9],int fila){
    int j=0;
    for(j=0;j<9;j++){
        matriz[fila][j]=*linea;
        linea++;
    }
}

int cargarLetra(char *ruta,char matriz[8][9]){
    FILE *df;
    char linea[11];
    int i=0;
    df = fopen(ruta,"rt");
    if(!df){
        return SIN_MEM;
    }

    while(fgets(linea,11,df) && i<8){
        _cargarLetra(linea,matriz,i);
        i++;
    }

    fclose(df);

    return 1;
}

void imprimirLetraLineaDos(HANDLE consola,COORD coords,char matriz[8][9],int filas,int columnas){
    COORD inicio;
    inicio.X = coords.X;
    int i;
    int j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            SetConsoleCursorPosition(consola,coords);
            printf("%c",matriz[i][j]);
            coords.X++;
        }
        coords.X = inicio.X;
        coords.Y++;
    }
}

void mostrarCursor(HANDLE consola,WORD estado){
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 20;
   info.bVisible = estado;
   SetConsoleCursorInfo(consola, &info);
}

void _cargarPieza(char *linea,tPieza *pieza,int fila){
    int j=0;

    for(j=0;j<4;j++){
        if(*linea == 'a'){
            pieza->mapa[fila][j] = 254;
        }
        if(*linea == ' '){
            pieza->mapa[fila][j] = 32;
        }
        linea++;
    }
}

int cargarPieza(char *ruta,tPieza *pieza){
    FILE *df;
    int i=0;
    char linea[6]={0};

    df = fopen(ruta,"rt");
    if(!df){
        return SIN_MEM;
    }

    while(fgets(linea,6,df) && i<4){
        _cargarPieza(linea,pieza,i);
        i++;
    }

    fclose(df);

    return 1;
}

void generarPieza(tPieza *pieza){
    int id = rand() % 7;

    pieza->id = id;
    pieza->posx = 4;
    pieza->posy = 0;
    switch(id){
        case 0:
            cargarPieza("Piezas/0.txt",pieza);
            break;
        case 1:
            cargarPieza("Piezas/1.txt",pieza);
            break;
        case 2:
            cargarPieza("Piezas/2.txt",pieza);
            break;
        case 3:
            cargarPieza("Piezas/3.txt",pieza);
            break;
        case 4:
            cargarPieza("Piezas/4.txt",pieza);
            break;
        case 5:
            cargarPieza("Piezas/5.txt",pieza);
            break;
        case 6:
            cargarPieza("Piezas/6.txt",pieza);
            break;
    }
}

void acolarPiezas(tCola *piezas,tPieza *pieza){
    generarPieza(pieza);
    acolar(piezas,pieza,sizeof(tPieza));
}

void mostrarVelocidad(HANDLE consola,int velocidad){
    COORD coords;
    coords.X = 75;
    coords.Y = 10;
    SetConsoleCursorPosition(consola,coords);
    SetConsoleTextAttribute(consola,FG_BLANCO);
    printf("Velocidad: %2d",velocidad);
}

void jugar(HANDLE consola){
    tCola piezas; //Cola que contiene las próximas piezas a colocar en el juego
    tLista puntajes; //Contiene los 10 mejores puntajes del juego
    tPieza pieza;
    unsigned tablero[20][10] = {0};
    unsigned gameOver=1; //Variable de Fin de Juego
    unsigned detencion=0; //Variable de detención de pieza
    unsigned movimiento=1; //Variable de control de movimientos cuando la pieza está en el piso
    unsigned aux = 0; //Variable de control de movimientos cuando la pieza está en el piso
    int velocidad = 10; //Variable que controla la velocidad con la que bajan las piezas
    int minutos = 0; //Variable de control del paso del tiempo
    int puntos = 0;
    SHORT currentState[4];
    SHORT previousState[4] = {0};
    COORD coords;

    //Condfiguración de la semilla para la generación de números aleatorios
    srand(time(NULL));

    //Creamos la cola de piezas, generamos dos piezas para dicha cola y generamos la pieza actual
    crearCola(&piezas);
    acolarPiezas(&piezas,&pieza);
    generarPieza(&pieza);

    //Creamos la lista de puntuaciónes
    crearLista(&puntajes);

    system("cls");
    dibujarMarco(consola);
    coords.X = 25;
    coords.Y = 6;
    mostrarPuntajes(consola,&puntajes,coords);
    mostrarCola(consola,&piezas);
    mostrarVelocidad(consola,velocidad);

    while(gameOver!=0){
        borrarPieza(consola,&pieza,tablero);

        //Compueba movimiento por parte del usuario
        if(kbhit()){
            obtenerEstadoTeclas(currentState,previousState,&pieza,tablero,&detencion);
        }

        // Este if comprueba que el usuario no esté moviendo la pieza para moverla una posición hacia abajo
        // el usuario pueda seguir moviendose y la pieza no siga cayendo
        if(minutos % velocidad == 0 && detencion != 1){
                pieza.posy++;
        }

        detencion=colocarPieza(&pieza,tablero); //Si detencion es 1, la pieza no puede moverse más
        mostrarPieza(consola,&pieza);
        mostrarPuntos(consola,puntos);

        //Esta estructura es la que le permite al usuario seguir moviendose a pesar de
        //haber tocado le fondo del tablero u otra pieza
        if(detencion == 1){
            movimiento = 1;
            aux++;
            if(aux == 30){
                movimiento = 0;
                aux = 0;
            }
        }

        //Momento de dejar la pieza en su lugar y cambiar de pieza
        if(detencion==1 && movimiento == 0){
            generarPieza(&pieza);
            acolar(&piezas,&pieza,sizeof(tPieza));
            desacolar(&piezas,&pieza,sizeof(tPieza));
            mostrarCola(consola,&piezas);
            //Comprueba si hay una línea completada por bloques
            esLineaCompleta(consola,tablero,&puntos);
            if(finDeJuego(tablero)){
                gameOver = 0;
            }
            detencion=0;
        }

        minutos++;
        if(minutos == 1500){ //1500 minutos es un minuto de la vida real
            minutos = 0;
            if(velocidad > 1){
                velocidad--;
                mostrarVelocidad(consola,velocidad);
            }
        }
        Sleep(40);
    }

    //Fin del Juego
    cortinaGameOver(consola);
    cargarPuntuacion(consola,&puntajes,puntos);
    vaciarCola(&piezas);
    vaciarLista(&puntajes);
}

int cmpPuntos(const void *a,const void *b){
    return ((tPuntaje*)a)->puntos - ((tPuntaje*)b)->puntos;
}

void simularTecla(WORD tecla){
    // Preparar la estructura de entrada
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0; // No se usa para eventos de teclado
    input.ki.time = 0; // Dejar que el sistema determine el tiempo
    input.ki.dwExtraInfo = 0; // No se usa

    // Simular presión de tecla
    input.ki.wVk = tecla; // Código de la tecla virtual
    input.ki.dwFlags = 0; // Presión de tecla
    SendInput(1, &input, sizeof(INPUT));

    // Simular liberación de tecla
    input.ki.dwFlags = KEYEVENTF_KEYUP; // Liberación de tecla
    SendInput(1, &input, sizeof(INPUT));
}

int esTopDiez(tLista *lista,int puntos){
    tPuntaje puntaje;
    puntaje.puntos = puntos;
    while(*lista){
        if(cmpPuntos(&puntaje,(*lista)->elemento) > 0){
            return 1;
        }
        lista = &(*lista)->sig;
    }

    return 0;
}

int cargarPuntuacion(HANDLE consola,tLista *lista,int puntos){
    FILE *df;
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;
    tPuntaje puntaje;
    char basura[100];
    int i=1;
    int j=0;

    GetConsoleScreenBufferInfo(consola,&ventana);
    coords.X = (ventana.dwSize.X / 2 - 18);;
    coords.Y = 15;

    //Está en top 10?
    if(esTopDiez(lista,puntos) || listaVacia(lista)){
        //Elimina todo lo que quede en el buffer de entrada
        mostrarCursor(consola,TRUE);
        SetConsoleTextAttribute(consola,FG_NEGRO);
        SetConsoleCursorPosition(consola,coords);
        simularTecla(VK_END);
        simularTecla(VK_RETURN);
        fgets(basura,100,stdin);

        //Ingreso del nombre
        SetConsoleTextAttribute(consola,FG_BLANCO);
        SetConsoleCursorPosition(consola,coords);
        printf("Su puntuacion esta dentro del top 10");
        coords.Y+=2;
        do{
            SetConsoleCursorPosition(consola,coords);
            printf("Ingrese su nombre: ");
            fgets(basura,100,stdin);
        }while(strlen(basura)>14);

        strcpy(puntaje.nombre,basura);

        while(puntaje.nombre[j] != '\n'){
            j++;
        }
        puntaje.nombre[j] = '\0';

        puntaje.puntos = puntos;
        insertarOrdenado(lista,&puntaje,sizeof(tPuntaje),cmpPuntos);

        df = fopen("highscores.txt","wt");
        if(!df){
            return SIN_MEM;
        }

        while(!listaVacia(lista) && i<=10){
            sacarDeLista(lista,&puntaje,sizeof(tPuntaje));
            puntaje.pos = i;
            fprintf(df,"%d: %d %s\n",puntaje.pos,puntaje.puntos,puntaje.nombre);
            i++;
        }

        fclose(df);
    }else{
        SetConsoleTextAttribute(consola,FG_BLANCO);
        system("pause");
    }

    return 1;
}

void recorrer(tLista *lista,void mostrarHighscores(HANDLE consola,void *elemento,COORD coords),HANDLE consola,COORD coords){
    SetConsoleCursorPosition(consola,coords);
    printf("Puntajes");
    coords.Y+=2;
    while(*lista){
        mostrarHighscores(consola,(*lista)->elemento,coords);
        coords.Y++;
        lista = &(*lista)->sig;
    }
}

void mostrarHighscores(HANDLE consola,void *elemento,COORD coords){
    SetConsoleCursorPosition(consola,coords);
    printf("%d: %d %s",((tPuntaje*)elemento)->pos,((tPuntaje*)elemento)->puntos,((tPuntaje*)elemento)->nombre);
}

void trocearNombre(char *linea,tPuntaje *puntaje){
    char *aux;
    while(*linea != ' '){
        linea++;
    }
    linea++;
    while(*linea != ' '){
        linea++;
    }
    linea++;
    aux = linea;
    while(*aux != '\n'){
        aux++;
    }
    *aux = '\0';
    strcpy(puntaje->nombre,linea);
}

int mostrarPuntajes(HANDLE consola,tLista *lista,COORD coords){
    FILE *df;
    tPuntaje puntaje;
    char linea[30] = {""};

    df = fopen("highscores.txt","rt");
    if(!df){
        return SIN_PUNTAJES;
    }

    while(fgets(linea,30,df)){
        sscanf(linea,"%d: %d",&puntaje.pos,&puntaje.puntos);
        trocearNombre(linea,&puntaje);
        insertarNodoAlFinal(lista,&puntaje,sizeof(tPuntaje));;
    }

    fclose(df);

    recorrer(lista,mostrarHighscores,consola,coords);

    return 1;
}

void mostrarPuntos(HANDLE consola,int puntos){
    COORD coords;
    coords.X = 25;
    coords.Y = 2;

    SetConsoleCursorPosition(consola,coords);
    SetConsoleTextAttribute(consola,FG_BLANCO);
    printf("Puntos: %4d",puntos);
}

void establecerColorPieza(HANDLE consola,tPieza *pieza){
    switch(pieza->id){
        case 0:
            SetConsoleTextAttribute(consola,FG_CELESTE);
            break;
        case 1:
        case 2:
            SetConsoleTextAttribute(consola,FG_AMARILLO);
            break;
        case 3:
            SetConsoleTextAttribute(consola,FG_ROJO);
            break;
        case 4:
            SetConsoleTextAttribute(consola,FG_VERDE);
            break;
        case 5:
            SetConsoleTextAttribute(consola,FG_VIOLETA);
            break;
        case 6:
            SetConsoleTextAttribute(consola,FG_AZUL);
            break;
    }
}

void mostrarCola(HANDLE consola,tCola *piezas){
    COORD coords;
    tPieza pieza;
    int i;
    int j;
    coords.X = 75;
    coords.Y = 2;

    SetConsoleCursorPosition(consola,coords);
    SetConsoleTextAttribute(consola,FG_BLANCO);
    printf("Siguiente Pieza");
    coords.Y++;
    coords.X = 80;

    verTope(piezas,&pieza,sizeof(tPieza));
    establecerColorPieza(consola,&pieza);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            SetConsoleCursorPosition(consola,coords);
            if(pieza.mapa[i][j]==254){
                printf("%c ",254);
            }else{
                printf("  ");
            }
            coords.X+=2;
        }
        coords.X = 80;
        coords.Y++;
    }
}

void girarHorario(tPieza *pieza,unsigned tablero[20][10]){
    unsigned aux [4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    unsigned aux2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    unsigned valido=1;
    unsigned valido2=1;
    int i;
    int j;
    int ultimo;
    int limite;

    //Igualo auxiliares a la pieza
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            aux[i][j]  = pieza->mapa[i][j];
            aux2[i][j] = pieza->mapa[i][j];
        }
    }

    if(pieza->id == 0 || pieza->id == 6){
        limite = 4;
    }else{
        limite = 3;
    }

    //Roto de forma horaria
    for(i=0;i<limite;i++){
        for(j=0;j<limite;j++){
            aux2[i][j]=aux[limite-1-j][i];
        }
    }

    //Comprueba colision con el borde derecho y colisión con otras piezas ya colocadas
    for(i=0;i<4;i++){
        ultimo=-1;
        for(j=0;j<4;j++){
            if(aux2[i][j]==254){
                ultimo=j;
                if(tablero[pieza->posy+i][pieza->posx+j]!=0){
                    return;
                }
            }
        }
        if(pieza->posx+ultimo+1>=10 && ultimo!=-1){
            return;
        }
    }

    for(i=0;i<4;i++){   //Comprueba colision con el borde izquierdo
        ultimo=5;
        for(j=3;j>-1;j--){
            if(aux2[i][j]==254){
                ultimo=j;
            }
        }
        if(pieza->posx+ultimo-1<=-1 && ultimo!=5){
            return;
        }
    }

    if(valido==1 && valido2==1){
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                pieza->mapa[i][j]=aux2[i][j];
            }
        }
    }
}

void bajar(tPieza *pieza, unsigned tablero[20][10]){
    int i;
    int j;
    int ultimo;

    while(1){
        for(j=0;j<4;j++){
            ultimo=-1;
            for(i=0;i<4;i++){
                if(pieza->mapa[i][j]==254){
                    ultimo=i;
                }
            }
            if(ultimo!=-1){
                if(tablero[pieza->posy+ultimo+1][pieza->posx+j]!=0){
                    return;
                }
            }
            if(pieza->posy+ultimo==19){
                return;
            }
        }
        pieza->posy++;
    }
}

int finDeJuego(unsigned tablero[20][10]){
    int i;
    for(i=0;i<10;i++){
        if(tablero[3][i]!=0){
            return 1;
        }
    }
    return 0;
}

void eliminarFila(HANDLE consola,unsigned tablero[20][10],unsigned fila){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;

    GetConsoleScreenBufferInfo(consola,&ventana);
    coords.X = ventana.dwSize.X / 2 - 11;
    coords.Y = TABLERO_SUP_IZQ_Y;
    int i;
    int j;

    coords.Y+=fila;
    for(i=fila;i>0;i--){
        //Guardo fila en la siguiente
        for(j=0;j<10;j++){
            SetConsoleCursorPosition(consola,coords);
            switch(tablero[i-1][j]){
                case 0:
                    printf("  ");
                    break;
                case 1:
                    SetConsoleTextAttribute(consola,FG_CELESTE);
                    printf("%c ",254);
                    break;
                case 2:
                    SetConsoleTextAttribute(consola,FG_AMARILLO);
                    printf("%c ",254);
                    break;
                case 3:
                    SetConsoleTextAttribute(consola,FG_ROJO);
                    printf("%c ",254);
                    break;
                case 4:
                    SetConsoleTextAttribute(consola,FG_VERDE);
                    printf("%c ",254);
                    break;
                case 5:
                    SetConsoleTextAttribute(consola,FG_VIOLETA);
                    printf("%c ",254);
                    break;
                case 6:
                    SetConsoleTextAttribute(consola,FG_AZUL);
                    printf("%c ",254);
                    break;
            }
            tablero[i][j]=tablero[i-1][j];
            coords.X+=2;
        }
        coords.X = ventana.dwSize.X / 2 - 11;;
        coords.Y--;
    }
    for(int i=0;i<10;i++){
        tablero[0][i]=0;
    }
}

void esLineaCompleta(HANDLE consola,unsigned tablero[20][10],int *puntos){
    int i;
    int j;
    unsigned contador = 0;

    for(i=0;i<20;i++){
        contador=0;
        for(j=0;j<10;j++){
            if(tablero[i][j]!=0){
                contador++;
            }
        }
        if(contador==10){
            eliminarFila(consola,tablero,i);
            *puntos += 10;
        }
    }
}

void mostrarTablero(HANDLE consola,unsigned tablero[20][10]){
    COORD coords;
    int i;
    int j;
    coords.X = 60;
    coords.Y = 3;
    for(i=0;i<20;i++){
        for(j=0;j<10;j++){
            SetConsoleCursorPosition(consola,coords);
            printf("%c",tablero[i][j]);
            coords.X++;
        }
        coords.X = 60;
        coords.Y++;
    }
}

void borrarTablero(HANDLE consola,unsigned tablero[20][10]){
    COORD coords;
    int i;
    int j;
    coords.X = 60;
    coords.Y = 3;
    for(i=0;i<20;i++){
        for(j=0;j<10;j++){
            SetConsoleCursorPosition(consola,coords);
            printf(" ");
            coords.X++;
        }
        coords.X = 60;
        coords.Y++;
    }
}

void dibujarMarco(HANDLE consola){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;

    GetConsoleScreenBufferInfo(consola,&ventana);

    coords.X = ventana.dwSize.X / 2 - 11 - 1;
    coords.Y = MARCO_SUP_IZQ_Y;

    //MARCO PARTE SUPERIOR
    SetConsoleCursorPosition(consola,coords);
    printf("%c",201);
    for(int i=0;i<20;i++){
        printf("%c",205);
    }
    printf("%c",187);

    //Impresion de la matriz
    coords.Y++;
    for(int f=0;f<20;f++){
        SetConsoleCursorPosition(consola,coords);
        printf("%c",186);
        for(int c=0;c<9;c++){
            printf("  ");
        }
        printf(" ");
        printf(" %c",186);
        coords.Y++;
    }

    //MARCO FINAL
    SetConsoleCursorPosition(consola,coords);
    printf("%c",200);
    for(int i=0;i<20;i++){
        printf("%c",205);
    }
    printf("%c",188);
}

unsigned colocarPieza(tPieza *pieza,unsigned tablero[20][10]){
    int ultimo;
    int i;
    int j;
    //SISTEMA DE COLOCACION DE PIEZAS Y DE COLISIONES
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(pieza->mapa[i][j]==254){
                //GUARDA EN EL TABLERO UN NÚMERO QUE REPRESENTA EL COLOR DE LA PIEZA
                switch(pieza->id){
                    case 0:
                        tablero[pieza->posy+i][pieza->posx+j]=1; //CELESTE
                        break;
                    case 1:
                    case 2:
                        tablero[pieza->posy+i][pieza->posx+j]=2; //AMARILLO
                        break;
                    case 3:
                        tablero[pieza->posy+i][pieza->posx+j]=3; //ROJO
                        break;
                    case 4:
                        tablero[pieza->posy+i][pieza->posx+j]=4; //VERDE
                        break;
                    case 5:
                        tablero[pieza->posy+i][pieza->posx+j]=5; //VIOLETA
                        break;
                    case 6:
                        tablero[pieza->posy+i][pieza->posx+j]=6; //AZUL
                        break;
                }
            }
        }
    }
    //COLISION CON EL PISO Y CON OTRAS PIEZAS
    for(j=0;j<4;j++){
        ultimo=-1;
        for(i=0;i<4;i++){
            if(pieza->mapa[i][j]==254){
                ultimo=i;
            }
        }
        if(ultimo!=-1){
            if(tablero[pieza->posy+ultimo+1][pieza->posx+j]!=0){
                //detencion = 1;
                return 1;
            }
        }
        if(pieza->posy+ultimo==19){
            //detencion=1;
            return 1;
        }
    }

    //return detencion;
    return 0;
}

void mostrarPieza(HANDLE consola,tPieza *pieza){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;
    unsigned tableroSupIzqX;
    int i;
    int j;

    GetConsoleScreenBufferInfo(consola,&ventana);
    tableroSupIzqX = ventana.dwSize.X / 2 - 11;

    coords.Y = TABLERO_SUP_IZQ_Y + (pieza->posy);
    coords.X = tableroSupIzqX + (pieza->posx*2);

    establecerColorPieza(consola,pieza);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(pieza->mapa[i][j]==254){
                SetConsoleCursorPosition(consola,coords);
                printf("%c ",254);
            }
            coords.X+=2;
        }
        coords.X = tableroSupIzqX + pieza->posx*2;
        coords.Y++;
    }
}

void borrarPieza(HANDLE consola,tPieza *pieza,unsigned tablero[20][10]){
    COORD coords;
    CONSOLE_SCREEN_BUFFER_INFO ventana;
    unsigned tableroSupIzqX;
    int i;
    int j;

    GetConsoleScreenBufferInfo(consola,&ventana);
    tableroSupIzqX = ventana.dwSize.X / 2 - 11;

    coords.Y = TABLERO_SUP_IZQ_Y + (pieza->posy);
    coords.X = tableroSupIzqX + (pieza->posx*2);

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(pieza->mapa[i][j]==254){
                SetConsoleCursorPosition(consola,coords);
                printf("  ");
            }
            coords.X+=2;
        }
        coords.X = tableroSupIzqX + pieza->posx*2;
        coords.Y++;
    }

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(pieza->mapa[i][j] == 254){
                tablero[pieza->posy+i][pieza->posx+j]=0;
            }
        }
    }
}

void obtenerEstadoTeclas(SHORT currentState[4],SHORT previousState[4],tPieza *pieza,unsigned tablero[20][10],unsigned *detencion){
    currentState[0] = GetAsyncKeyState(VK_RIGHT) & 0x8000;
    currentState[1] = GetAsyncKeyState(VK_DOWN) & 0x8000;
    currentState[2] = GetAsyncKeyState(VK_LEFT) & 0x8000;
    currentState[3] = GetAsyncKeyState(VK_SPACE) & 0x8000;
    fflush(stdin);

    if(currentState[0]!=0 && previousState[0]==0){
        if(colision(pieza,tablero,1)){
            pieza->posx++;
        }
    }
    //Control de flecha abajo
    if(currentState[1]!=0 && previousState[1]==0){
        bajar(pieza,tablero);
        *detencion = 1;
    }
    //Control de flecha Izquierda
    if(currentState[2]!=0 && previousState[2]==0){
        if(colision(pieza,tablero,2)){
            pieza->posx--;
        }
    }
    //Control de Espacio
    if(currentState[3]!=0 && previousState[3]==0){
        girarHorario(pieza,tablero);
    }


    previousState[0] = currentState[0];
    previousState[1] = currentState[1];
    previousState[2] = currentState[2];
    previousState[3] = currentState[3];
}

unsigned colision(tPieza *pieza,unsigned tablero[20][10],unsigned tipo){
    unsigned valido=1;
    int ultimo;
    int i;
    int j;

    for(i=0;i<4;i++){
        ultimo=-1;
        //COMPRUEBA COLISIONES DESDE LADO DERECHO Y CHOQUE CON PARED DERECHA
        if(tipo==1){
            for(j=0;j<4;j++){
                if(pieza->mapa[i][j]==254){
                    ultimo=j;
                }
            }
            if(ultimo!=-1){
                //Comprueba colisión con pared derecha
                if(pieza->posx+ultimo+1>=10){
                    //valido=0;
                    return 0;
                }

                //Comprueba colisión con pieza a la derecha
                if(tablero[pieza->posy+i][pieza->posx+ultimo+1]!=0){
                    //valido=0;
                    return 0;
                }
            }
        }
        //COMPRUEBA COLISIONES DESDE EL LADO IZQUIERDO Y CHOQUE CON PARED IZQUIERDA
        ultimo=5;
        if(tipo==2){
            for(j=3;j>-1;j--){
                if(pieza->mapa[i][j]==254){
                    ultimo=j;
                }
            }
            if(ultimo!=5){
                if(pieza->posx+ultimo-1<=-1){
                    //valido=0;
                    return 0;
                }

                //Comprueba colisión con pieza a la izquierda
                if(tablero[pieza->posy+i][pieza->posx+ultimo-1]!=0){
                    //valido=0;
                    return 0;
                }
            }
        }
    }

    return valido;
}
