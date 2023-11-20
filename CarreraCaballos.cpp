#include "CarreraCaballos.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

CarreraCaballos::CarreraCaballos(std::string nombre, float apuestaMinima, float distanciaCarrera, Jugador& jugador)
    : Juego(nombre, apuestaMinima), distanciaCarrera(distanciaCarrera), jugador(jugador) {

    for (int i = 0; i < 6; ++i) {
        distancias[i] = 0;
    }
}

void CarreraCaballos::apostar(float cantidad) {
}

void CarreraCaballos::avanzarCaballos() {
    for (int i = 0; i < 6; ++i) {
        distancias[i] += rand() % 3 + 1;
    }
}

void CarreraCaballos::imprimirCarrera() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < distancias[i]; ++j) {
            std::cout << ".";
        }
        std::cout << "C" << i + 1 << std::endl;
    }
}

void CarreraCaballos::jugar() {
    system("cls");
    srand(static_cast<unsigned>(time(0)));
    int apuesta;
    std::cout << "Distancia: " << distanciaCarrera << "m" << std::endl;
    std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;
    std::cout << "Ingresa tu apuesta: $";
    std::cin >> apuesta;

    if (apuesta > jugador.getSaldo()) {
        std::cout << "No tienes suficiente saldo. Introduce una apuesta válida." << std::endl;
        return;
    }

    while (jugador.getSaldo() > 0) {
        std::cout << "Apuesta por un caballo (1-6): ";
        int caballoElegido;
        std::cin >> caballoElegido;

        if (caballoElegido < 1 || caballoElegido > 6) {
            std::cout << "Caballo inválido. Introduce un número entre 1 y 6." << std::endl;
            return;
        }

        std::cout << "¡Apostaste $" << apuesta << " por el caballo " << caballoElegido << "!" << std::endl;

        jugador.actualizarSaldo(-apuesta);

        bool hayGanador = false;

        while (true) {
            system("cls");

            avanzarCaballos();
            imprimirCarrera();

            // Comprobar ganador
            for (int i = 0; i < 6; ++i) {
                if (distancias[i] >= distanciaCarrera) {
                    if (i + 1 == caballoElegido) {
                        std::cout << "¡Felicidades! ¡Ganaste $" << apuesta * 5 << "!" << std::endl;
                        jugador.actualizarSaldo(apuesta * 5); // Duplicar la apuesta en caso de victoria
                    } else {
                        std::cout << "¡El caballo " << i + 1 << " ha ganado!" << std::endl;
                    }
                    hayGanador = true;
                    break;
                }
            }

            if (hayGanador) {
                std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;

                std::cout << "Presiona Enter para continuar...";
                std::cin.ignore();
                std::cin.get();
                return;
            }

            Sleep(100);
        }
    }
}
