#pragma once
#include "Jugador.h"

class ArchivoTetris
{
public:
    ArchivoTetris();

    Jugador jugador;

    bool grabarJugador(Jugador&jugador);
    Jugador leerUnJugador(int posicion);
    int CantidadRegistrosJugadores();
    void leerTodo(int cantidadRegistros, Jugador *vector);
};


