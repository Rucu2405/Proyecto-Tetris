#pragma once
#include <SFML/Graphics.hpp>
#include "Posicion.h"
#include "ArchivoTetris.h"
class Menu
{
public:
    Menu();

    sf::Texture fondoMenuTexture;
    sf::Sprite fondoMenuSprite;
    sf::Texture fondoPuntuacionTexture;
    sf::Sprite fondoPuntuacionSprite;
    sf::RectangleShape recuadroProxBloque;
    ArchivoTetris jugadorEnArchivo;
    int opcionElegidaMenu;
    void drawMenu(sf::RenderWindow &window);
    void menuArriba();
    void menuAbajo();
    void interfazPartida(sf::RenderWindow &window,int &puntos,int &filas);
    void interfazPuntuaciones(sf::RenderWindow &window,Jugador *jugadoresPuntajes,int cantidadRegistros);
    int getOpcionElegida();

    sf::Color colorSeleccionado = sf::Color(170, 0,10);

    sf::Color colorLibre = sf::Color::White;
    sf::Font fuenteMenu;
    sf::Font fuentePartida;
    sf::Font fuentePuntos;
    sf::Text menu[3];
    sf::Text interfazGame[4];
    sf::Text interfazPuntos[11];
    Posicion pos;

    sf::Text textNombre;
    sf::Text textPuntos;

};


