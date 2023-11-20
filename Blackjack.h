#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Juego.h"
#include "Jugador.h"
#include <vector>

enum CardRank { DOS, TRES, CUATRO, CINCO, SEIS, SIETE, OCHO, NUEVE, DIEZ, JOTA, REINA, REY, AS };
enum CardSuit { CORAZONES, DIAMANTES, TREBOLES, PICAS };

struct Card {
    CardRank rank;
    CardSuit suit;
};

class Blackjack : public Juego {
private:
    Jugador& jugador;
    std::vector<Card> deck;

public:
    Blackjack(std::string nombre, float apuestaMinima, Jugador& jugador);
    void apostar(float cantidad) override;
    void jugar() override;
    int getCardValue(const Card& card);
    void printCard(const Card& card);
};

#endif
