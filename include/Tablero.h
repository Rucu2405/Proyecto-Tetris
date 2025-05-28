#pragma once
#include <SFML/Graphics.hpp>
#include "Posicion.h"
#include "Bloques.h"
#include "musicaSonidos.h"
#include <vector>


class Tablero
{
private:
    int _numColumnas;
    int _numFilas;
    sf::Vector2f _tamCelda;
    sf::Texture _texture;


    //////////////////////////////////////////////////////////

    std::vector<sf::Color> colores;
musicaSonidos efecto;
    Posicion pos;
    Bloques bloque;



public:
    Tablero();
    virtual ~Tablero();
    int tableroJuego[18][10];

    /////////////////////////
    void iniciarTablero();
    void mostrarTablero();
    void fijarBloqueAlTablero();
   void verificarLineaCompletaEnTablero(int &puntajeAcumulado,int &filasAcumuladas);
   bool gameOver();
    void dibujarTablero(sf::RenderWindow &window, sf::Sprite &fondoDibujo);



};


