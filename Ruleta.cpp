#include "Ruleta.h"
#include <iostream>
#include <random>

std::string determinarColor(int numero) {
    if (numero == 0) {
        return "verde";
    } else if (numero % 2 == 1) {
        return "rojo";
    } else {
        return "negro";
    }
}

Ruleta::Ruleta(std::string nombre, float apuestaMinima, Jugador& jugador)
    : Juego(nombre, apuestaMinima), numeroGanador(0), jugador(jugador) {}

void Ruleta::apostar(float cantidad) {
}

void Ruleta::jugar() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> distribution(0, 36);

    while (true) {
        system("cls");
        std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;
        std::cout << "Elige tu apuesta:\n";
        std::cout << "1. Número específico\n";
        std::cout << "2. Rojo o Negro\n";
        std::cout << "0. Salir\n";

        int opcion;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        if (opcion == 0) {
            break;
        }

        int apuesta;
        std::cout << "Ingresa tu apuesta: $";
        std::cin >> apuesta;

        if (apuesta > jugador.getSaldo()) {
            std::cout << "No tienes suficiente saldo. Ingresa una apuesta válida." << std::endl;
            continue;
        }

        int resultado = distribution(rng);

        if (opcion == 1) {
            std::cout << "Elige un número (0-36): ";
            int numeroElegido;
            std::cin >> numeroElegido;

            if (numeroElegido < 0 || numeroElegido > 36) {
                std::cout << "Número no válido. Apuesta perdida." << std::endl;
            } else {
                std::string colorResultado = determinarColor(resultado);

                std::cout << "La ruleta ha caído en el número " << (resultado == 0 ? "0" : std::to_string(resultado))
                          << " (" << colorResultado << ")";

                if (resultado == numeroElegido) {
                    jugador.actualizarSaldo(apuesta * 35);
                    std::cout << ". ¡Ganaste! Has ganado $" << apuesta * 35 << "." << std::endl;
                } else {
                    jugador.actualizarSaldo(-apuesta);
                    std::cout << ". Perdiste. Has perdido $" << apuesta << "." << std::endl;
                }
            }
        } else if (opcion == 2) {
            char eleccion;
            std::cout << "Elige (r) Rojo o (n) Negro: ";
            std::cin >> eleccion;

            bool esRojo = (resultado != 0 && resultado % 2 == 1);
            std::string colorResultado = determinarColor(resultado);

            std::cout << "La ruleta ha caído en el número " << (resultado == 0 ? "0" : std::to_string(resultado))
                      << " (" << colorResultado << ")";

            if ((esRojo && (eleccion == 'r' || eleccion == 'R')) || (!esRojo && (eleccion == 'n' || eleccion == 'N'))) {
                jugador.actualizarSaldo(apuesta);
                std::cout << ". ¡Ganaste! Has ganado $" << apuesta << "." << std::endl;
            } else {
                jugador.actualizarSaldo(-apuesta);
                std::cout << ". Perdiste. Has perdido $" << apuesta << "." << std::endl;
            }
        }

        std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;

        std::cout << "Presiona Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
    }
}
