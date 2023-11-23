#include "Jugador.h"
#include "Juego.h"
#include <iostream>

Jugador::Jugador(const std::string& nombre, int dinero) : nombre(nombre), dinero(dinero) {}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getDinero() const {
    return dinero;
}

void Jugador::setDinero(int nuevoDinero) {
    dinero = nuevoDinero;
}

bool Jugador::apostar(int cantidad) {
    if (cantidad > 0 && cantidad <= dinero) {
        dinero -= cantidad;
        return true;
    } else {
        mensajeError = "\nNo tienes suficiente dinero para apostar esa cantidad.";
        return false;
    }
}

std::string Jugador::getMensajeError() const {
    return mensajeError;
}

bool Jugador::jugar(Juego& juego) {
    if (apostar(10)) {
        juego.jugar();
        setDinero(getDinero() + juego.getApuesta());
        return true;
    }
    return false;
}
