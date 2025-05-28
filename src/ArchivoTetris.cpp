#include "ArchivoTetris.h"

ArchivoTetris::ArchivoTetris()
{

}

bool ArchivoTetris::grabarJugador(Jugador &jugador)
{
    FILE *pFile;
    pFile = fopen("jugadores.dat", "ab"); /// agrega registros al archivo, si no existe lo crea
    if(pFile==nullptr)
    {
        return false;
    }
    int grabo = fwrite(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);
    return grabo; /// devuelve 1 o 0, dependiendo si lo grabo o no
}

Jugador ArchivoTetris::leerUnJugador(int posicion)
{
    Jugador jugador;
    FILE *pFile = fopen("jugadores.dat", "rb"); /// abre el archivo en modo lectura
    if(pFile==nullptr)
    {
        return jugador;
    }
    fseek(pFile,sizeof(Jugador)*posicion,SEEK_SET);
    if(fread(&jugador,sizeof(Jugador),1,pFile))
    {
        std::cout<<"Leido";
    }
    fclose(pFile);
    return jugador;
}

int ArchivoTetris::CantidadRegistrosJugadores()
{
    FILE *pFile = fopen("jugadores.dat", "rb"); /// abre el archivo en modo lectura
    if(pFile==nullptr)
    {
        return 0;
    }
    fseek(pFile, 0, SEEK_END);
    int cantidadRegistros = ftell(pFile) / sizeof(Jugador);
    fclose(pFile);
    return cantidadRegistros;
}


void ArchivoTetris::leerTodo(int cantidadRegistros, Jugador *vector)
{

    FILE *pFile = fopen("jugadores.dat", "rb"); /// abre el archivo en modo lectura
    if(pFile==NULL)
    {
        return;
    }

    for(int i=0; i<cantidadRegistros; i++)
    {
        fread(&vector[i],sizeof(Jugador),1,pFile);
    }
    fclose(pFile);

}
