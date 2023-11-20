#include "Jugador.h"

Jugador::Jugador(std::string nombre, float saldo) : nombre(nombre), saldo(saldo) {}

std::string Jugador::getNombre() const {
    return nombre;
}

float Jugador::getSaldo() const {
    return saldo;
}

void Jugador::apostar(float cantidad) {
}

void Jugador::actualizarSaldo(float cantidad) {
    saldo += cantidad;
}
