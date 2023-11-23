#ifndef ADIVINAR_H
#define ADIVINAR_H

#include "Juego.h"

// Clase para representar el juego de Adivinar, hereda de la clase Juego
class Adivinar : public Juego {
private:
    int numeroSecreto;
    int intento;

public:
    Adivinar();

    // Función para realizar un intento en el juego
    bool jugar() override;

    // Obtener el intento actual del jugador
    int getIntento() const;
    
    // Obtener el número secreto
    int getNumeroSecreto() const;
};

#endif
