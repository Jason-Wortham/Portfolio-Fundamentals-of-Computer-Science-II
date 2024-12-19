//
// Created by Jason on 4/4/2024.
//

#ifndef POKER_PROJECT_PART1_DECK_H
#define POKER_PROJECT_PART1_DECK_H
#include "card.h"
#include <vector>


class Deck {
    private:
        std::vector<Card> deckOfCards;

    public:
        Deck();
        void addCard(Card card);
        void shuffle();
        void printDeck();
        Card getCard(int index);
        void setCard(int index, Card card);
        Card dealCard();
};


#endif //POKER_PROJECT_PART1_DECK_H
