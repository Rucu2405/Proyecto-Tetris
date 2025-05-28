#include "musicaSonidos.h"
#include <iostream>

musicaSonidos::musicaSonidos()
{
    if (!musicaPartida.openFromFile("medios\\sonidos\\musica\\partida.ogg"))
    {
        std::cout<<"No esta la cancion"<<std::endl;
    }

    if (!musicaMenu.openFromFile("medios\\sonidos\\musica\\menu.wav"))
    {
        std::cout<<"No esta la cancion"<<std::endl;
    }

    if (!musicaFinGameOver.openFromFile("medios\\sonidos\\musica\\gameover.wav"))
    {
        std::cout<<"No esta la cancion"<<std::endl;
    }

    //ctor
}

void musicaSonidos::navegarOpcion()
{
    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\navegaropcion.wav"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);
}

void musicaSonidos::seleccionarOpcion()
{
    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\seleccionaropcion.wav"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);
}

void musicaSonidos::volverAtras()
{
    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\escape.wav"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);
}

void musicaSonidos::fondoPartida()
{
    musicaPartida.play();
    musicaPartida.setVolume(5);
    musicaPartida.setLoop(true);

}


void musicaSonidos::fondoMenu()
{

    musicaMenu.play();
    musicaMenu.setVolume(5);
    musicaMenu.setLoop(true);
}


void musicaSonidos::fondoGameOver()
{
    musicaFinGameOver.play();
    musicaFinGameOver.setVolume(5);

}

void musicaSonidos::soundFijarBloque()
{
    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\colisionBloque.ogg"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);
}
void musicaSonidos::sonidoLineaCompleta()
{

    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\linea.ogg"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);

}

void musicaSonidos::soundGiro()
{
    if (!buffer.loadFromFile("medios\\sonidos\\efectos\\giro.ogg"))
    {
        std::cout<<"No esta el sonido"<<std::endl;
    }
    sound.setBuffer(buffer);
    sound.play();
    sound.setVolume(50);
}
