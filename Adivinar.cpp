#include "Adivinar.h"
#include <iostream>

Adivinar::Adivinar() : Juego("Adivinar"), numeroSecreto(rand() % 5 + 1), intento(0) {}

int Adivinar::getIntento() const {
    return intento;
}

int Adivinar::getNumeroSecreto() const {
    return numeroSecreto;
}

bool Adivinar::jugar() {
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
