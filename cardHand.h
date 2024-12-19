//
// Created by Jason on 4/4/2024.
//

#ifndef POKER_PROJECT_PART1_CARDHAND_H
#define POKER_PROJECT_PART1_CARDHAND_H
#include "deck.h"

class cardHand {
    private:
        std::vector<Card> hand;

    public:
        cardHand();
        void addCard(Card card);
        std::vector<Card> getHand();
        void setHand(std::vector<Card>& hand);
        void printHand();
};


#endif //POKER_PROJECT_PART1_CARDHAND_H
