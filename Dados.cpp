#include "Dados.h"

Dados::Dados() : Juego("Dados"), dadoJugador(0), dadoDealer(0) {}

int Dados::getDadoJugador() const {
    return dadoJugador;
}

int Dados::getDadoDealer() const {
    return dadoDealer;
}

int Dados::tirarDado() const {
    return rand() % 6 + 1;
}

bool Dados::jugar() {
    dadoJugador = tirarDado();
    dadoDealer = tirarDado();

    if (dadoJugador > dadoDealer) {
        apuesta = 20;
        return true;
    } else {
        return false;
    }
}
