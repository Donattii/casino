#ifndef JUEGO_H
#define JUEGO_H

#include <string>

class Juego {
protected:
    std::string nombre;
    int apuesta;

public:
    Juego(const std::string& nombre);

    virtual bool jugar() = 0;

    int getApuesta() const;
    const std::string& getNombre() const;
    void setApuesta(int nuevaApuesta);
};

#endif
