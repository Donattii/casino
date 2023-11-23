#include "PPT.h"
#include <iostream>

// Constructor de la clase PPT
PPT::PPT() : Juego("Piedra, Papel o Tijera"), eleccionJugador(0), eleccionDealer(0) {}

// Obtener la elección del jugador
int PPT::getEleccionJugador() const {
    return eleccionJugador;
}

// Obtener la elección del dealer
int PPT::getEleccionDealer() const {
    return eleccionDealer;
}

// Iniciar el juego de Piedra, Papel o Tijera
bool PPT::jugar() {
    std::cin >> eleccionJugador;

    eleccionDealer = rand() % 3 + 1;

    // Determinar el resultado del juego y establecer la apuesta
    if ((eleccionJugador == 1 && eleccionDealer == 3) ||
        (eleccionJugador == 2 && eleccionDealer == 1) ||
        (eleccionJugador == 3 && eleccionDealer == 2)) {
        apuesta = 20;
        return true;   // Devolver verdadero si el jugador gana
    } else if (eleccionJugador == eleccionDealer) {
        apuesta = 10;
        return false;  // Devolver falso si hay un empate
    } else {
        return false;  // Devolver falso si el jugador pierde
    }
}
