#include "Jugador.h"
#include <cstring>
Jugador::Jugador()
{
    _puntaje = 0;
    nombreJugadorAguardar[7]= {'\0'};



    textBoxNombre.setPosition(200,300);
    textBoxNombre.setFillColor(sf::Color(177, 182, 180,60));
    textBoxNombre.setSize(sf::Vector2f(350.f, 190.f));


    if (!fondoIngresarNombreTexture.loadFromFile("medios\\fondos\\pantalla\\nombre.png"))
    {
        std::cout<<"fondo NO encontrado";
    }
    // Crear un sprite para el fondo
    fondoIngresarNombreSprite.setTexture(fondoIngresarNombreTexture);

    if (!fuente.loadFromFile("medios\\fuentes\\puntos.ttf"))
    {
        std::cout<<"Fuente no encontrada"<<std::endl;
    }

    if (!fuenteGameOver.loadFromFile("medios\\fuentes\\gameover.ttf"))
    {
        std::cout<<"Fuente no encontrada"<<std::endl;
    }

    mensajeGameOver.setFont(fuenteGameOver);
    mensajeGameOver.setFillColor(sf::Color::White);
   mensajeGameOver.setString("GAME OVER");
    mensajeGameOver.setCharacterSize(100);
    mensajeGameOver.setPosition(120, 100);


    mensajeNombre.setFont(fuente);
    mensajeNombre.setFillColor(sf::Color(32, 183, 243));
    mensajeNombre.setString("Ingrese su Nombre");
    mensajeNombre.setPosition(210, 300);

    nombreUsuarioPorPantalla.setFont(fuente);
    nombreUsuarioPorPantalla.setFillColor(sf::Color::White);
    nombreUsuarioPorPantalla.setPosition(290, 350);

    mensajePuntos.setFont(fuente);
    mensajePuntos.setFillColor(sf::Color(32, 183, 243));
    mensajePuntos.setString("Puntos");
    mensajePuntos.setPosition(310, 410);

    puntosPorPantalla.setFont(fuente);
    puntosPorPantalla.setFillColor(sf::Color::White);
    puntosPorPantalla.setPosition(330, 450);


    mensajeVolverAmenu.setFont(fuente);
    mensajeVolverAmenu.setFillColor(sf::Color::White);
      mensajeVolverAmenu.setCharacterSize(20);
      mensajeVolverAmenu.setString("Presione -ENTER- \n\npara guardar");
    mensajeVolverAmenu.setPosition(550,520);

}

void Jugador::ingresarNombre(sf::RenderWindow &_window,int puntaje,bool &irAmenu)
{
    _puntaje=puntaje;
    puntosPorPantalla.setString(std::to_string (_puntaje));
    nombreJugadorIngresando = "";
    nombreUsuarioPorPantalla.setString(nombreJugadorIngresando);

    sf::Event evento;

    while (!irAmenu)  // Mantener en bucle hasta que el usuario confirme el nombre
    {
        while (_window.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                _window.close();
                return;
            }

            if (evento.type == sf::Event::TextEntered)
            {
                if ( (evento.text.unicode < 128 && nombreJugadorIngresando.size() < 7) || (evento.text.unicode == '\b'))///obtiene el caracter imprimible

                {

                    if (evento.text.unicode == '\b')  // '\b' es el código ASCII para BackSpace
                    {
                        if (!nombreJugadorIngresando.empty())
                        {
                            nombreJugadorIngresando.pop_back();
                            nombreUsuarioPorPantalla.setString(nombreJugadorIngresando);
                        }
                    }
                    else
                    {
                        nombreJugadorIngresando += static_cast<char>(evento.text.unicode);
                        nombreUsuarioPorPantalla.setString(nombreJugadorIngresando);
                    }
                }
            }

            if (evento.type == sf::Event::KeyPressed)
            {
                if (evento.key.code == sf::Keyboard::Return)
                {
                    const char *nombre = nombreJugadorIngresando.c_str();
                    strcpy(nombreJugadorAguardar,nombre);
                    return;
                }
            }

            _window.clear();
            _window.draw(fondoIngresarNombreSprite);
            _window.draw(mensajeGameOver);
            _window.draw(textBoxNombre);
            _window.draw(mensajeNombre);
            _window.draw(nombreUsuarioPorPantalla);
            _window.draw(mensajePuntos);
            _window.draw(puntosPorPantalla);
            _window.draw(mensajeVolverAmenu);
            _window.display();
        }
    }
}

void Jugador::Mostrar()  /// mostramos la info del jugador
{
    ///mostrar por pantalla;

    std::cout << "Jugador : \n" << nombreJugadorAguardar;
    std::cout << "\tPuntaje: " << _puntaje << std::endl;

}

char Jugador::getNombre()
{
    return nombreJugadorAguardar[7];
}
int Jugador::getPuntaje()
{
    return _puntaje;
}

