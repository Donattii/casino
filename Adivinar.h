#ifndef ADIVINAR_H
#define ADIVINAR_H

#include "Juego.h"

class Adivinar : public Juego {
private:
    int numeroSecreto;

public:
    Adivinar();
    bool jugar() override;
    int getNumeroSecreto() const;
};

#endif
