#include "Jugador.h"
#include "Dados.h"
#include "PPT.h"
#include "Adivinar.h"
#include <ctime>
#include <iostream>

int main() {

    std::string nombreJugador;
    std::cout << "Ingrese el nombre del jugador: ";
    std::cin >> nombreJugador;

    Jugador jugador(nombreJugador, 100);

    std::cout << "¡Bienvenido al Casino, " << jugador.getNombre() << "! Tu saldo actual es: " << jugador.getDinero() << std::endl;

    // Menú de juegos
    int opcion;
    do {
        std::cout << "\n=== DONATI CASINO ===\n";
        std::cout << "1. Dados\n";
        std::cout << "2. Piedra, Papel o Tijera\n";
        std::cout << "3. Adivinar un número\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione un juego (0-3): ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Dados juegoDados;
                int cantidadApostada = 10;

                if (jugador.jugar(juegoDados)) {
                    std::cout << "¡Ganaste! Tu nuevo saldo es: " << jugador.getDinero() << std::endl;
                } else {
                    std::cout << jugador.getMensajeError() << std::endl;
                    std::cout << "Tu saldo actual es: " << jugador.getDinero() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Elije: 1. Piedra, 2. Papel, 3. Tijera: ";
                PPT juegoPPT;
                int cantidadApostada = 10;  // o cualquier otra cantidad que desees

                if (jugador.jugar(juegoPPT)) {
                    int eleccionDealer = rand() % 3 + 1;
                    std::cout << "Dealer elige: " << eleccionDealer << std::endl;

                    std::cout << "Tu nuevo saldo es: " << jugador.getDinero() << std::endl;
                } else {
                    std::cout << jugador.getMensajeError() << std::endl;
                    std::cout << "Tu saldo actual es: " << jugador.getDinero() << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "Adivina el número del 1 al 5: ";
                Adivinar juegoAdivinar;
                int cantidadApostada = 10;

                if (jugador.jugar(juegoAdivinar)) {
                    std::cout << "¡Ganaste! El número secreto era " << juegoAdivinar.getNumeroSecreto() << ". Tu nuevo saldo es: " << jugador.getDinero() << std::endl;
                } else {
                    std::cout << jugador.getMensajeError() << std::endl;
                    std::cout << "Tu saldo actual es: " << jugador.getDinero() << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "¡Gracias por jugar en el Casino, " << jugador.getNombre() << "! Tu saldo final es: " << jugador.getDinero() << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
        }

    } while (opcion != 0);

    return 0;
}
