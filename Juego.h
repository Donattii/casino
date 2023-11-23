#ifndef JUEGO_H
#define JUEGO_H

#include <string>

// Clase base para representar un juego
class Juego {
protected:
    std::string nombre;
    int apuesta;

public:
    // Constructor de la clase Juego
    Juego(const std::string& nombre);

    // Función virtual pura para jugar el juego (debe ser implementada por las clases derivadas)
    virtual bool jugar() = 0;

    // Obtener la apuesta actual del juego
    int getApuesta() const;
    
    // Obtener el nombre del juego
    const std::string& getNombre() const;

    // Establecer una nueva apuesta para el juego
    void setApuesta(int nuevaApuesta);
};

#endif
