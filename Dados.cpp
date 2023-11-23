#include "Dados.h"

Dados::Dados() : Juego("Dados") {}

int Dados::tirarDado() const {
    return rand() % 6 + 1;
}

bool Dados::jugar() {
    int dadoJugador = tirarDado();
    int dadoDealer = tirarDado();

    if (dadoJugador > dadoDealer) {
        apuesta = 20;
        return true;
    } else {
        return false;
    }
}
