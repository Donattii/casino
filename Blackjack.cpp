#include "Blackjack.h"
#include <iostream>
#include <algorithm>
#include <ctime>

Blackjack::Blackjack(std::string nombre, float apuestaMinima, Jugador& jugador)
    : Juego(nombre, apuestaMinima), jugador(jugador) {}

void Blackjack::apostar(float cantidad) {
}

int Blackjack::getCardValue(const Card& card) {
    switch (card.rank) {
        case AS: return 11;
        case DIEZ: case JOTA: case REINA: case REY: return 10;
        default: return static_cast<int>(card.rank) + 2;
    }
}

void Blackjack::printCard(const Card& card) {
    switch (card.rank) {
        case AS: std::cout << "A"; break;
        case DIEZ: std::cout << "10"; break;
        case JOTA: std::cout << "J"; break;
        case REINA: std::cout << "Q"; break;
        case REY: std::cout << "K"; break;
        default: std::cout << static_cast<int>(card.rank) + 2;
    }

    switch (card.suit) {
        case CORAZONES: std::cout << "♥"; break;
        case DIAMANTES: std::cout << "♦"; break;
        case TREBOLES: std::cout << "♣"; break;
        case PICAS: std::cout << "♠"; break;
    }
}

void Blackjack::jugar() {
    while (jugador.getSaldo() > 0) {
        system("cls");

        deck.clear();
        for (int rank = DOS; rank <= AS; ++rank) {
            for (int suit = CORAZONES; suit <= PICAS; ++suit) {
                deck.push_back({ static_cast<CardRank>(rank), static_cast<CardSuit>(suit) });
            }
        }

        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(deck.begin(), deck.end());

        int apuesta;
        std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;
        std::cout << "Ingresa tu apuesta (0 para salir): $";
        std::cin >> apuesta;

        if (apuesta == 0) {
            break;
        }

        if (apuesta > jugador.getSaldo()) {
            std::cout << "No tienes suficiente saldo. Ingresa una apuesta válida." << std::endl;
            continue;
        }

        int playerTotal = 0;

        Card carta1 = deck.back();
        playerTotal += getCardValue(carta1);
        printCard(carta1);
        std::cout << " ";
        deck.pop_back();

        Card carta2 = deck.back();
        playerTotal += getCardValue(carta2);
        printCard(carta2);
        std::cout << std::endl;

        std::cout << "Tu total es: " << playerTotal << std::endl;

        // Jugador: Pedir o Plantarse
        char accion;
        while (true) {
            std::cout << "¿Qué deseas hacer? (h: Pedir carta, s: Plantarte): ";
            std::cin >> accion;

            if (accion == 'h') {
                // Jugador pide una carta
                Card nuevaCarta = deck.back();
                playerTotal += getCardValue(nuevaCarta);
                printCard(nuevaCarta);
                std::cout << " ";
                deck.pop_back();
                std::cout << "Tu total es: " << playerTotal << std::endl;

                if (playerTotal > 21) {
                    std::cout << "Te pasaste. Perdiste." << std::endl;
                    jugador.actualizarSaldo(-apuesta);;
                    break;
                }
            } else if (accion == 's') {
                // Jugador se planta
                break;
            }
        }

        if (playerTotal <= 21) {
            int dealerTotal = 0;
            dealerTotal += getCardValue(deck.back());
            printCard(deck.back());
            std::cout << " ";
            deck.pop_back();
            std::cout << "[Carta Oculta]" << std::endl;

            while (dealerTotal < 17) {
                dealerTotal += getCardValue(deck.back());
                printCard(deck.back());
                std::cout << " ";
                deck.pop_back();
            }
            std::cout << "\nEl total del crupier es: " << dealerTotal << std::endl;

            if (dealerTotal > 21 || (playerTotal <= 21 && dealerTotal < playerTotal)) {
                std::cout << "¡Ganaste!" << std::endl;
                jugador.actualizarSaldo(apuesta * 2);
            } else if (dealerTotal == playerTotal) {
                std::cout << "Empate. Recibes de vuelta tu apuesta." << std::endl;
            } else {
                std::cout << "Perdiste." << std::endl;
                jugador.actualizarSaldo(-apuesta);
            }
        }

        std::cout << "Tu saldo actual es: $" << jugador.getSaldo() << std::endl;

        std::cout << "Presiona Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
    }
}
