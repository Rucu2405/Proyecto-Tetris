#include "sonidos.h"
#include <SFML/Audio.hpp>
#include "iostream"
sonidos::sonidos()
{

  if (!musicaFondo.openFromFile("medios\\fondos\\sonidos\\partida.mp3"))
    {
        std::cout<<"Musica NO encontrada";
    }

}

sonidos::~sonidos()
{
    //dtor
}
