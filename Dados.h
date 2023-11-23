#ifndef DADOS_H
#define DADOS_H

#include "Juego.h"

class Dados : public Juego {
private:
    int dadoJugador;
    int dadoDealer;

public:
    Dados();

    int tirarDado() const;
    bool jugar();
    
    // Métodos para obtener los valores de los dados
    int getDadoJugador() const;
    int getDadoDealer() const;
};

#endif
