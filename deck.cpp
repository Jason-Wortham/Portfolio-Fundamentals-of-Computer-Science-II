//
// Created by Jason on 4/4/2024.
//

#include "deck.h"

std::string suit, rank;

Deck::Deck() {

    for(int i = 0; i < 4; i ++) {
        switch(i) {
            case 0:
                suit = "Spades";
                break;
            case 1:
                suit = "Hearts";
                break;
            case 2:
                suit = "Clubs";
                break;
            case 3:
                suit = "Diamonds";
                break;
        }
        for(int j = 0; j < 13; j ++) {
            switch(j) {
                case 0:
                    rank = "Ace";
                    break;
                case 1:
                    rank = "Two";
                    break;
                case 2:
                    rank = "Three";
                    break;
                case 3:
                    rank = "Four";
                    break;
                case 4:
                    rank = "Five";
                    break;
                case 5:
                    rank = "Six";
                    break;
                case 6:
                    rank = "Seven";
                    break;
                case 7:
                    rank = "Eight";
                    break;
                case 8:
                    rank = "Nine";
                    break;
                case 9:
                    rank = "Ten";
                    break;
                case 10:
                    rank = "Jack";
                    break;
                case 11:
                    rank = "Queen";
                    break;
                case 12:
                    rank = "King";
                    break;
            }
            Card card(suit, rank);
            deckOfCards.push_back(card);
        }
    }

}

void Deck::addCard(Card card) {
    deckOfCards.push_back(card);
}

void Deck::shuffle() {

    std::vector<Card> deckOfCardsCopy;
    int randomIndex;

    for(int l = 0; l <= deckOfCards.size() - 1; l ++) {
        deckOfCardsCopy.push_back(deckOfCards[l]);
    }

    for(int m = deckOfCards.size() - 1; m > 0; m --) {

        randomIndex = rand() % (m + 1);

        std::swap(deckOfCards[m], deckOfCards[randomIndex]);
    }
}

void Deck::printDeck() {
    for(int k = 0; k <= deckOfCards.size() - 1; k ++) {
        std::cout << k+1 << ": " << deckOfCards[k].getRank() << " of " << deckOfCards[k].getSuit() << std::endl;
    }

}

Card Deck::getCard(int index) {
    return deckOfCards[index];
}


void Deck::setCard(int index, Card card) {
    deckOfCards[index].setSuit(card.getSuit());
    deckOfCards[index].setRank(card.getRank());
}

Card Deck::dealCard() {
    Card cardDuplicate = deckOfCards[0];
    deckOfCards.erase(deckOfCards.begin());

    return cardDuplicate;
}