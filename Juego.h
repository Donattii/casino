#ifndef JUEGO_H
#define JUEGO_H

#include <string>

class Juego {
protected:
    std::string nombre;
    float apuestaMinima;

public:
    Juego(std::string nombre, float apuestaMinima);
    virtual void apostar(float cantidad) = 0;
    virtual void jugar() = 0;
};

#endif
