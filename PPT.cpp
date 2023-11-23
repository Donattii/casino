#include "PPT.h"
#include <iostream>

PPT::PPT() : Juego("Piedra, Papel o Tijera"), eleccionJugador(0), eleccionDealer(0) {}

int PPT::getEleccionJugador() const {
    return eleccionJugador;
}

int PPT::getEleccionDealer() const {
    return eleccionDealer;
}

bool PPT::jugar() {
    std::cin >> eleccionJugador;

    eleccionDealer = rand() % 3 + 1;

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
