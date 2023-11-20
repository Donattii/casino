#ifndef RULETA_H
#define RULETA_H

#include "Juego.h"
#include "Jugador.h"
#include <string>

class Ruleta : public Juego {
private:
    int numeroGanador;
    Jugador& jugador;

public:
    Ruleta(std::string nombre, float apuestaMinima, Jugador& jugador);
    void apostar(float cantidad) override;
    void jugar() override;
};

#endif
