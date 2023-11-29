#include <iostream>
#include "Juego.h"

using namespace std;

// Constructor de la clase Juego
Juego::Juego(const string& nombre) : nombre(nombre), apuesta(0) {}

// Obtener el nombre del juego
const string& Juego::getNombre() const {
    return nombre;
}

// Obtener la apuesta actual del juego
int Juego::getApuesta() const {
    return apuesta;
}
