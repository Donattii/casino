#include <iostream>
#include "Jugador.h"

using namespace std;

// Constructor de la clase Jugador
Jugador::Jugador(const string& nuevoNombre, int nuevoDinero) {
    nombre = nuevoNombre;
    dinero = nuevoDinero;
}

// Obtener el nombre del jugador
string Jugador::getNombre() const {
    return nombre;
}

// Setter para el nombre del jugador
void Jugador::setNombre(const string& nuevoNombre) {
    nombre = nuevoNombre;
}

// Obtener la cantidad de dinero del jugador
int Jugador::getDinero() const {
    return dinero;
}

// Establecer una nueva cantidad de dinero para el jugador
void Jugador::setDinero(int nuevoDinero) {
    dinero = nuevoDinero;
}

// Apostar una cantidad de dinero en un juego
bool Jugador::apostar(int cantidad) {
    if (cantidad > 0 && cantidad <= dinero) {
        dinero -= cantidad;
        return true;
    } else {
        mensajeError = "\nNo tienes suficiente dinero para apostar esa cantidad.";
        return false;
    }
}

// Obtener el mensaje de error
string Jugador::getMensajeError() const {
    return mensajeError;
}

// Jugar un juego específico y gestionar la apuesta
bool Jugador::jugar() {
    if (apostar(10)) {
        juego->jugar();
        setDinero(getDinero() + juego->getApuesta());
        return true;
    }
    return false;
}

Juego* Jugador::getJuego() const {
    return juego;
}

void Jugador::setJuego(Juego* nuevoJuego) {
    juego = nuevoJuego;
}
