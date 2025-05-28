#include "Colores.h"

Colores::Colores()
{
    //ctor
}

Colores::~Colores()
{
    //dtor
}

std::vector<sf::Color> Colores::getColores()
{
   const sf::Color c0=sf::Color(223, 222, 221,80);
   const sf::Color c1=sf::Color(199, 172, 249);
   const sf::Color c2=sf::Color(168, 234, 253);
  const  sf::Color c3=sf::Color(247, 175, 88);
   const sf::Color c4=sf::Color(235, 114, 114);
  const  sf::Color c5=sf::Color(218, 241, 254);
  const  sf::Color c6=sf::Color(247,96, 174);
  const  sf::Color c7=sf::Color(100, 227, 144);

    return{c0,c1,c2,c3,c4,c5,c6,c7};
}
