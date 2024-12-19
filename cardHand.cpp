//
// Created by Jason on 4/4/2024.
//

#include "cardHand.h"

cardHand::cardHand() {

}

void cardHand::addCard(Card card) {
  hand.push_back(card);
}

void cardHand::printHand() {
    for(int i = 0; i <= 4; i ++) {
        std::cout << i+1 << ": " << hand[i].getRank() << " of " << hand[i].getSuit() << std::endl;
    }
}

std::vector<Card> cardHand::getHand() {
    return hand;
}

void cardHand::setHand(std::vector<Card>& hand) {
    for(int i = 0; i <= hand.size(); i ++) {
        cardHand::hand.push_back(hand[i]);
    }
}