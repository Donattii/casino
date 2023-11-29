#include "Jugador.h"
#include "Dados.h"
#include "PPT.h"
#include "Adivinar.h"
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    // Crear jugador
    string nombreJugador;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombreJugador;

    Jugador jugador(nombreJugador, 100);

    cout << "¡Bienvenido al Casino, " << jugador.getNombre() << "! Tu saldo actual es: " << jugador.getDinero() << std::endl;

    // Menú de juegos
    int opcion;
    do {
        cout << "\n=== DONATI CASINO ===\n";
        cout << "1. Dados\n";
        cout << "2. Piedra, Papel o Tijera\n";
        cout << "3. Adivinar un número\n";
        cout << "0. Salir\n";
        cout << "Seleccione un juego (0-3): ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Dados juegoDados;
                jugador.setJuego(&juegoDados);
                int cantidadApostada = 10;

                if (jugador.jugar()) {
                    cout << "El dado del jugador: " << juegoDados.getDadoJugador() << endl;
                    cout << "El dado del dealer: " << juegoDados.getDadoDealer() << endl;

                    if (juegoDados.getDadoJugador() > juegoDados.getDadoDealer()) {
                        cout << "¡Felicidades! Ganaste en el juego de dados.\n";
                    } else {
                        cout << "Lo siento, perdiste en el juego de dados.\n";
                    }
                    
                    cout << "Tu nuevo saldo es: " << jugador.getDinero() << endl;
                } else {
                    cout << jugador.getMensajeError() << endl;
                    cout << "Tu saldo actual es: " << jugador.getDinero() << endl;
                }
                break;
            }
            case 2: {
                cout << "Elije: 1. Piedra, 2. Papel, 3. Tijera: ";
                PPT juegoPPT;
                jugador.setJuego(&juegoPPT);
                int cantidadApostada = 10;

                if (jugador.jugar()) {
                    int eleccionDealer = juegoPPT.getEleccionDealer();

                    cout << "Dealer elige: " << eleccionDealer << endl;

                    if (juegoPPT.getEleccionJugador() == eleccionDealer) {
                        cout << "¡Empate! No ganas ni pierdes dinero.\n";
                    } else if ((juegoPPT.getEleccionJugador() == 1 && eleccionDealer == 3) ||
                            (juegoPPT.getEleccionJugador() == 2 && eleccionDealer == 1) ||
                            (juegoPPT.getEleccionJugador() == 3 && eleccionDealer == 2)) {
                        cout << "¡Felicidades! Ganaste en Piedra, Papel o Tijera.\n";
                    } else {
                        cout << "Lo siento, perdiste en Piedra, Papel o Tijera.\n";
                    }

                    cout << "Tu nuevo saldo es: " << jugador.getDinero() << endl;
                } else {
                    cout << jugador.getMensajeError() << endl;
                    cout << "Tu saldo actual es: " << jugador.getDinero() << endl;
                }
                break;
            }
            case 3: {
                cout << "Adivina el número del 1 al 5: ";
                Adivinar juegoAdivinar;
                jugador.setJuego(&juegoAdivinar);
                int cantidadApostada = 10;

                if (jugador.jugar()) {
                    int intentoJugador = juegoAdivinar.getIntento();
                    int numeroSecreto = juegoAdivinar.getNumeroSecreto();

                    if (intentoJugador == numeroSecreto) {
                        cout << "¡Felicidades! Adivinaste el número secreto.\n";
                    } else {
                        cout << "Lo siento, no adivinaste el número secreto. Era: " << numeroSecreto << "\n";
                    }

                    cout << "Tu nuevo saldo es: " << jugador.getDinero() << endl;
                } else {
                    cout << jugador.getMensajeError() << endl;
                    cout << "Tu saldo actual es: " << jugador.getDinero() << endl;
                }
                break;
            }
            case 0:
                cout << "¡Gracias por jugar en el Casino, " << jugador.getNombre() << "! Tu saldo final es: " << jugador.getDinero() << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
