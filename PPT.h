#ifndef PPT_H
#define PPT_H

#include "Juego.h"

// Clase para representar el juego de Piedra, Papel o Tijera, hereda de la clase Juego
class PPT : public Juego {
private:
    int eleccionJugador;
    int eleccionDealer;

public:
    PPT();

    // Función para realizar un intento en el juego
    bool jugar() override;

    // Obtener la elección del jugador
    int getEleccionJugador() const;

    // Obtener la elección del dealer
    int getEleccionDealer() const;
};

#endif
