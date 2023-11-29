#include <iostream>
#include "Adivinar.h"

using namespace std;

// Constructor de la clase Adivinar
Adivinar::Adivinar() : Juego("Adivinar"), numeroSecreto(rand() % 5 + 1), intento(0) {}

// Getter para obtener el número de intentos
int Adivinar::getIntento() const {
    return intento;
}

// Getter para obtener el número secreto
int Adivinar::getNumeroSecreto() const {
    return numeroSecreto;
}

// Función para jugar el juego de adivinar
bool Adivinar::jugar() {
    cin >> intento;

    // Verifica si el intento está en el rango válido [1, 5]
    if (intento >= 1 && intento <= 5) {
        // Comprueba si el intento es igual al número secreto
        if (intento == numeroSecreto) {
            apuesta = 50;
            return true;   // Devuelve verdadero si adivina correctamente
        } else {
            return false;  // Devuelve falso si no adivina correctamente
        }
    } else {
        return false;
    }
}
