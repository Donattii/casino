#ifndef DADOS_H
#define DADOS_H

#include "Juego.h"

class Dados : public Juego {
public:
    Dados();

    int tirarDado() const;
    bool jugar();
};

#endif
