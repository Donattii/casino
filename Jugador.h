#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    int dinero;
    std::string mensajeError;

public:
    Jugador(const std::string& nombre, int dinero);
    std::string getMensajeError() const;
    std::string getNombre() const;
    int getDinero() const;
    void setDinero(int nuevoDinero);

    bool apostar(int cantidad);
    bool jugar(class Juego& juego);
};

#endif
