#include "Dados.h"

// Constructor de la clase Dados
Dados::Dados() : Juego("Dados"), dadoJugador(0), dadoDealer(0) {}

// Obtener el valor del dado del jugador
int Dados::getDadoJugador() const {
    return dadoJugador;
}

// Obtener el valor del dado del dealer
int Dados::getDadoDealer() const {
    return dadoDealer;
}

// Simular el lanzamiento de un dado de 6 caras
int Dados::tirarDado() const {
    return rand() % 6 + 1;
}

// Realizar la jugada de dados, establecer la apuesta si el jugador gana
bool Dados::jugar() {
    dadoJugador = tirarDado();
    dadoDealer = tirarDado();

    // Determinar el ganador y establecer la apuesta
    if (dadoJugador > dadoDealer) {
        apuesta = 20;
        return true;
    } else {
        return false;
    }
}
