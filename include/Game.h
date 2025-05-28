#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Menu.h"
#include "musicaSonidos.h"
#include "ArchivoTetris.h"
#include "Jugador.h"
#include "Posicion.h"
#include "Tablero.h"
#include "Bloques.h"


class Game
{
private:
    sf::RenderWindow _window;
    Menu menu;
    musicaSonidos musicaPartida;
    musicaSonidos musicaMenu;
    musicaSonidos musicaFinGameOver;
    musicaSonidos efectosMenu;
    ArchivoTetris archivo;
    Jugador jugador;
    Posicion pos;
    Tablero tablero;
    Bloques bloque;
    Bloques bloqueNuevo;
    sf::Texture fondoTablero;
    sf::Sprite fondoTableroSprite;
    sf::Clock clock;
    bool primerInicio = true;
    bool irAmenu=true;
    bool puntajesVistos=false;
    bool partidaIniciada=false;
    bool irApuntos =false;
    bool gameOver=false;
    float velocidadDeCaida;


///funciones privadas
    void procesarEventosMenu();
    void procesarEventosPartida();
    void render();
    void reiniciarVariables();
    void reloj();
    void movimientoBloqueAutomatico(bool partidaIniciada);
    void pantallaFinDePartida();
    void velocidadPorPuntaje(int puntajeAcumulado);
    void obtenerJugadoresDeArchivo(bool puntajesVistos,Jugador *vector);
    void puntajePantalla();


public:
    Jugador *jugadoresPuntajes;
    Game();
    void run();
    int puntajeAcumulado=0;
    int filasAcumuladas=0;
};


