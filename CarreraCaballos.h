#ifndef CARRERACABALLOS_H
#define CARRERACABALLOS_H

#include "Juego.h"
#include "Jugador.h"
#include <string>

class CarreraCaballos : public Juego {
private:
    float distanciaCarrera;
    int distancias[6];
    Jugador& jugador;

public:
    CarreraCaballos(std::string nombre, float apuestaMinima, float distanciaCarrera, Jugador& jugador);
    void apostar(float cantidad) override;
    void jugar() override;
    void avanzarCaballos();
    void imprimirCarrera();
};

#endif
