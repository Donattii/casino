#include "Jugador.h"
#include "Dados.h"
#include "PPT.h"
#include "Adivinar.h"
#include <ctime>
#include <iostream>

int main() {
    // Crear jugador
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
                    std::cout << "El dado del jugador: " << juegoDados.getDadoJugador() << std::endl;
                    std::cout << "El dado del dealer: " << juegoDados.getDadoDealer() << std::endl;

                    if (juegoDados.getDadoJugador() > juegoDados.getDadoDealer()) {
                        std::cout << "¡Felicidades! Ganaste en el juego de dados.\n";
                    } else {
                        std::cout << "Lo siento, perdiste en el juego de dados.\n";
                    }
                    
                    std::cout << "Tu nuevo saldo es: " << jugador.getDinero() << std::endl;
                } else {
                    std::cout << jugador.getMensajeError() << std::endl;
                    std::cout << "Tu saldo actual es: " << jugador.getDinero() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "Elije: 1. Piedra, 2. Papel, 3. Tijera: ";
                PPT juegoPPT;
                int cantidadApostada = 10;

                if (jugador.jugar(juegoPPT)) {
                    int eleccionDealer = juegoPPT.getEleccionDealer();

                    std::cout << "Dealer elige: " << eleccionDealer << std::endl;

                    if (juegoPPT.getEleccionJugador() == eleccionDealer) {
                        std::cout << "¡Empate! No ganas ni pierdes dinero.\n";
                    } else if ((juegoPPT.getEleccionJugador() == 1 && eleccionDealer == 3) ||
                            (juegoPPT.getEleccionJugador() == 2 && eleccionDealer == 1) ||
                            (juegoPPT.getEleccionJugador() == 3 && eleccionDealer == 2)) {
                        std::cout << "¡Felicidades! Ganaste en Piedra, Papel o Tijera.\n";
                    } else {
                        std::cout << "Lo siento, perdiste en Piedra, Papel o Tijera.\n";
                    }

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
                    int intentoJugador = juegoAdivinar.getIntento();
                    int numeroSecreto = juegoAdivinar.getNumeroSecreto();

                    if (intentoJugador == numeroSecreto) {
                        std::cout << "¡Felicidades! Adivinaste el número secreto.\n";
                    } else {
                        std::cout << "Lo siento, no adivinaste el número secreto. Era: " << numeroSecreto << "\n";
                    }

                    std::cout << "Tu nuevo saldo es: " << jugador.getDinero() << std::endl;
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
