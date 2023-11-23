#ifndef DADOS_H
#define DADOS_H

#include "Juego.h"

// Clase para representar el juego de Dados, hereda de la clase Juego
class Dados : public Juego {
private:
    int dadoJugador;
    int dadoDealer;

public:
    Dados();

    // Simular el lanzamiento de un dado de 6 caras
    int tirarDado() const;

    // Función para realizar un intento en el juego
    bool jugar();
    
    // Obtener el valor del dado del jugador
    int getDadoJugador() const;
    
    // Obtener el valor del dado del dealer
    int getDadoDealer() const;
};

#endif
