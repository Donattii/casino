#ifndef PPT_H
#define PPT_H

#include "Juego.h"

class PPT : public Juego {
private:
    int eleccionJugador;
    int eleccionDealer;

public:
    PPT();
    bool jugar() override;
    
    int getEleccionJugador() const;
    int getEleccionDealer() const;
};

#endif
