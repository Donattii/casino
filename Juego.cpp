#include "Juego.h"

Juego::Juego(const std::string& nombre) : nombre(nombre), apuesta(0) {}

const std::string& Juego::getNombre() const {
    return nombre;
}

int Juego::getApuesta() const {
    return apuesta;
}

void Juego::setApuesta(int nuevaApuesta) {
    apuesta = nuevaApuesta;
}
