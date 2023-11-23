#include "Adivinar.h"
#include <iostream>

Adivinar::Adivinar() : Juego("Adivinar"), numeroSecreto(rand() % 5 + 1) {}

bool Adivinar::jugar() {
    int intento;
    std::cin >> intento;

    if (intento >= 1 && intento <= 5) {
        if (intento == numeroSecreto) {
            apuesta = 50;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int Adivinar::getNumeroSecreto() const {
    return numeroSecreto;
}
