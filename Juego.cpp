#include "Juego.h"

// Constructor de la clase Juego
Juego::Juego(const std::string& nombre) : nombre(nombre), apuesta(0) {}

// Obtener el nombre del juego
const std::string& Juego::getNombre() const {
    return nombre;
}

// Obtener la apuesta actual del juego
int Juego::getApuesta() const {
    return apuesta;
}

// Establecer una nueva apuesta para el juego
void Juego::setApuesta(int nuevaApuesta) {
    apuesta = nuevaApuesta;
}
