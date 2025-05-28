#pragma once
#include <SFML/Audio.hpp>

class musicaSonidos
{
public:
    musicaSonidos();
    sf::Music musicaPartida;
    sf::Music musicaMenu;
    sf::Music musicaFinGameOver;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    void fondoPartida();
     void fondoMenu();
     void fondoGameOver();
     void navegarOpcion();
     void seleccionarOpcion();
     void volverAtras();
    void soundFijarBloque();
    void sonidoLineaCompleta();
    void soundGiro();




};


