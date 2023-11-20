#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    float saldo;

public:
    Jugador(std::string nombre, float saldo);
    std::string getNombre() const;
    float getSaldo() const;
    void apostar(float cantidad);
    void actualizarSaldo(float cantidad);
};

#endif
