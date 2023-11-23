#include "PPT.h"
#include <iostream>

PPT::PPT() : Juego("Piedra, Papel o Tijera") {}

bool PPT::jugar() {
    int eleccionJugador;
    std::cin >> eleccionJugador;

    int eleccionDealer = rand() % 3 + 1;

    if ((eleccionJugador == 1 && eleccionDealer == 3) ||
        (eleccionJugador == 2 && eleccionDealer == 1) ||
        (eleccionJugador == 3 && eleccionDealer == 2)) {
        apuesta = 20;
        return true;
    } else if (eleccionJugador == eleccionDealer) {
        apuesta = 10;
        return false;
    } else {
        return false;
    }
}
