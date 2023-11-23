#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

// Clase para representar un jugador
class Jugador {
private:
    std::string nombre;
    int dinero;
    std::string mensajeError;

public:
    // Constructor de la clase Jugador
    Jugador(const std::string& nombre, int dinero);

    // Obtener el mensaje de error
    std::string getMensajeError() const;

    // Obtener el nombre del jugador
    std::string getNombre() const;

    // Obtener la cantidad de dinero del jugador
    int getDinero() const;

    // Establecer una nueva cantidad de dinero para el jugador
    void setDinero(int nuevoDinero);

    // Apostar una cantidad específica de dinero en un juego
    bool apostar(int cantidad);

    // Jugar un juego específico y gestionar la apuesta
    bool jugar(class Juego& juego);
};

#endif
