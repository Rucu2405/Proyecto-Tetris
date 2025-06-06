#include "Tablero.h"
#include "Colores.h"

#include <iostream>

Tablero::Tablero()
{
    _numColumnas = pos.columnasTableroX;   // Ancho de la grilla widht
    _numFilas = pos.filasTableroY;  // Alto de la grilla height
    _tamCelda =sf::Vector2f((float)pos.tamCelda,(float)pos.tamCelda); // Tama�o de cada celda (en p�xeles
    Colores color;
    iniciarTablero();
    colores = color.getColores();
    _texture.loadFromFile("medios\\fondos\\tableros\\celda.png");
    //constructor

}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::iniciarTablero()
{
    ///Crea el tablero con 0
    for(int filas=0; filas<_numFilas; filas++)
    {
        for(int columnas=0; columnas<_numColumnas; columnas++)
        {
            tableroJuego[filas][columnas]=0;
        }
    }
}

void Tablero::mostrarTablero()
{
    ///muestra el tablero con 0 por consola
    for(int filas=0; filas<_numFilas; filas++)
    {
        for(int columnas=0; columnas<_numColumnas; columnas++)
        {
            std::cout<<tableroJuego[filas][columnas]<<" ";
        }
        std::cout<<std::endl;
    }
}

void Tablero::dibujarTablero(sf::RenderWindow &window,sf::Sprite &fondoDibujo)
{
    window.draw(fondoDibujo);
    for(int filas=0; filas<_numFilas; filas++)
    {
        for(int columnas=0; columnas<_numColumnas; columnas++)
        {
            int valorCelda = tableroJuego[filas][columnas];
            sf::RectangleShape bloqueRect(_tamCelda);
            bloqueRect.setPosition(pos.mitadVentanaX+(columnas*_tamCelda.x),pos.mitadVentanaY+(filas*_tamCelda.y));
            bloqueRect.setFillColor(colores[valorCelda]);
            bloqueRect.setOutlineColor(sf::Color::Black);
            bloqueRect.setTexture(&_texture);
            bloqueRect.setOutlineThickness(1);
            window.draw(bloqueRect);
        }
    }
}

/*void Tablero::fijarBloqueAlTablero()
{/// fijamos la forma en el tablero que se esta viendo por pantalla

    ///matriz que tiene los valores de la forma que se est� jugando
    vector<vector<int>> bloqueEnTablero=bloque.formasTetris[bloque._idBloque];

    for(int filas=0; filas<4; filas++)
    {
        for(int columnas=0; columnas<4; columnas++)
        {
            if (bloqueEnTablero[filas][columnas] != 0)
            {
                // Asigna el valor del bloque al tablero en la posici�n correspondiente
                tableroJuego[(bloque._posicionBloqueY + filas)*30][(bloque._posicionBloqueX + columnas)*30] = bloqueEnTablero[filas][columnas];
            }
        }
    }
}*/


void Tablero::verificarLineaCompletaEnTablero(int &puntajeAcumulado,int &filasAcumuladas)
{
    int filaAnterior=_numFilas-1;
    int lineasCompletas=0;
    for(int filaActual=_numFilas-1; filaActual>=0; filaActual--)///filas de abajo hacia arriba ( 18-1 filas hasta fila 0inclusive)
    {
        int lugarOcupado=0;
        for(int columna=0; columna<_numColumnas; columna++)
        {
            if(tableroJuego[filaActual][columna]!=0)///recorremos las columnas buscando las que estan ocupadas
            {
                lugarOcupado++;
            }
        }
        ///despues de recorrer las columnas verifico cuantos lugares estan ocupados == 10 linea llena, <10 incompleta
        if(lugarOcupado < 10)
        {
            ///fila incompleta
            for(int lugarColumna=0; lugarColumna<10; lugarColumna++)
            {
                tableroJuego[filaAnterior][lugarColumna] = tableroJuego[filaActual][lugarColumna];
            }
            filaAnterior--;
        }
        else
        {
            lineasCompletas++;
            efecto.sonidoLineaCompleta();
          }
    }

    if(lineasCompletas==4)
    {
        puntajeAcumulado+=800;

    }
    else if(lineasCompletas==3)
    {
        puntajeAcumulado+=400;

    }
    else
    {
        puntajeAcumulado+=lineasCompletas*100;


    }

    filasAcumuladas+=lineasCompletas;

}

bool Tablero::gameOver()
{
    for(int columna=0; columna<_numColumnas; columna++)
    {
        if(tableroJuego[0][columna]>0)
        {
            return true;
        }
    }
    return false;
}
