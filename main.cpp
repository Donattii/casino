#include "Jugador.h"
#include "Ruleta.h"
#include "CarreraCaballos.h"
#include "Blackjack.h"
#include <iostream>

int main() {
    Jugador jugador("Test", 1000.0);

    int opcionJuego;
    do {
        std::cout << "Seleccione el juego:\n";
        std::cout << "1. Ruleta\n";
        std::cout << "2. Carrera de Caballos\n";
        std::cout << "3. Blackjack\n";
        std::cout << "0. Salir\n";
        std::cin >> opcionJuego;

        switch (opcionJuego) {
            system("cls");
            case 1: {
                Ruleta ruleta("Ruleta Europea", 5.0, jugador);
                ruleta.jugar();
                break;
            }
            case 2: {
                float distanciaCarrera;
                std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;
                std::cout << "Ingrese la distancia de la carrera de caballos: ";
                std::cin >> distanciaCarrera;

                CarreraCaballos carreraCaballos("Carrera de Caballos", 5.0, distanciaCarrera, jugador);
                carreraCaballos.jugar();
                break;
            }
            case 3: {
                Blackjack blackjack("Blackjack", 5.0, jugador);
                blackjack.jugar();
                break;
            }
            case 0:
                std::cout << "Saliendo del casino. ¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
    } while (opcionJuego != 0);

    return 0;
}
