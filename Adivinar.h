#ifndef ADIVINAR_H
#define ADIVINAR_H

#include "Juego.h"

class Adivinar : public Juego {
private:
    int numeroSecreto;
    int intento;

public:
    Adivinar();
    bool jugar() override;
    
    // Métodos para obtener el intento del jugador y el número secreto
    int getIntento() const;
    int getNumeroSecreto() const;
};

#endif
