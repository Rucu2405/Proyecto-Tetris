#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Jugador
{
public:
    Jugador();

    void ingresarNombre(sf::RenderWindow &_window,int puntaje,bool &irAmenu);
    void Mostrar();
    char getNombre();
    int getPuntaje();


    char nombreJugadorAguardar[7];
    int _puntaje;



private:
sf::RectangleShape textBoxNombre;
    std::string nombreJugadorIngresando;

    sf::Texture fondoIngresarNombreTexture;
    sf::Sprite fondoIngresarNombreSprite;

    sf::Font fuente;
     sf::Font fuenteGameOver;
    sf::Text mensajeNombre;
    sf::Text mensajePuntos;
    sf::Text mensajeGameOver;
    sf::Text mensajeVolverAmenu;

    sf::Text nombreUsuarioPorPantalla;
    sf::Text puntosPorPantalla;
};


