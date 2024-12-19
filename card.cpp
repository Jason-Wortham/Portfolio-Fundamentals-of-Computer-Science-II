//
// Created by Jason on 4/4/2024.
//

#include "card.h"

std::string Card::getSuit() {
    return suit;
}

std::string Card::getRank() {
    return rank;
}

void Card::setSuit(std::string suit) {
    Card::suit = suit;
}

void Card::setRank(std::string rank) {
    Card::rank = rank;
}

std::ostream& operator<<(std::ostream& out, const Card& card) {
    out << card.rank << "/" << card.suit;
    return out;
}

Card::Card(std::string suit, std::string rank) {
    Card::suit = suit;
    Card::rank = rank;
}

Card::Card() {
    Card::suit = "null";
    Card::rank = '0';
}