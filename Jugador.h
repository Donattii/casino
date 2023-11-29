#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include "Juego.h"

using namespace std;

// Clase para representar un jugador
class Jugador {
private:
    string nombre;
    int dinero;
    string mensajeError;
    Juego* juego;

public:
    Jugador(const string& nuevoNombre, int nuevoDinero);
    
    // Obtener el nombre del jugador
    string getNombre() const;

    // Setter para el nombre del jugador
    void setNombre(const string& nuevoNombre);

    // Obtener el mensaje de error
    string getMensajeError() const;

    // Obtener la cantidad de dinero del jugador
    int getDinero() const;
   
    // Setter para la cantidad de dinero del jugador
    void setDinero(int nuevoDinero);
    
    // Apostar una cantidad específica de dinero en un juego
    bool apostar(int cantidad);

    // Obtener el juego del jugador
    Juego* getJuego() const;

    // Setter para el juego del jugador
    void setJuego(Juego* nuevoJuego);

    bool jugar();
};

#endif
