#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Posicion.h"
#include "Colores.h"
#include "musicaSonidos.h"

using namespace std;

class Bloques
{
public:

    Bloques();
    int fijarBloques=1;
    vector<vector<vector<int>>> formasTetris;
    vector<vector<vector<int>>> formaSiguiente;
    musicaSonidos efecto;
    sf::RectangleShape celda;
    Posicion p;
    sf::Texture text;

    /// variables del bloque
    int _idBloque=0;
    int _idBloqueSiguiente =-1;
    int _posicionBloqueX;
    int _posicionBloqueY;

/// funciones del bloque
    void crearNuevoBloque();
    void dibujarBloque(sf::RenderWindow &window);
    void dibujarProximoBloque(sf::RenderWindow &window);
    void moverBloque(sf::Keyboard::Key key,bool partidaIniciada,int tableroJuego[18][10]);
    bool limitarBloqueEnTablero(int tableroJuego[18][10]);
    void rotarBloque(sf::Keyboard::Key key);
    void fijarBloqueEnTablero(int tableroJuego[18][10]);
void reiniciarBloque(sf::Keyboard::Key key);
private:
    int _randomColor;
    std::vector<sf::Color> color;
    Colores c;
};


