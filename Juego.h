#ifndef JUEGO_H
#define JUEGO_H

#include <string>

using namespace std;

// Clase base para representar un juego
class Juego {
protected:
    string nombre;
    int apuesta;

public:
    Juego(const string& nombre);

    // Función virtual para jugar el juego (debe ser implementada por las clases derivadas)
    virtual bool jugar() = 0;

    // Obtener la apuesta actual del juego
    int getApuesta() const;
    
    // Obtener el nombre del juego
    const string& getNombre() const;
};

#endif
