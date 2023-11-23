#include "Jugador.h"
#include "Juego.h"
#include <iostream>

// Constructor de la clase Jugador
Jugador::Jugador(const std::string& nombre, int dinero) : nombre(nombre), dinero(dinero) {}

// Obtener el nombre del jugador
std::string Jugador::getNombre() const {
    return nombre;
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
std::string Jugador::getMensajeError() const {
    return mensajeError;
}

// Jugar un juego específico y gestionar la apuesta
bool Jugador::jugar(Juego& juego) {
    if (apostar(10)) {
        juego.jugar();
        setDinero(getDinero() + juego.getApuesta());
        return true;
    }
    return false;
}
