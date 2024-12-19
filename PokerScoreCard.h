//
// Created by Jason on 4/13/2024.
//

#ifndef POKER_PROJECT_PART1_POKERSCORECARD_H
#define POKER_PROJECT_PART1_POKERSCORECARD_H
#include <vector>
#include <map>

class PokerScoreCard {
public:
    enum Scores{

        ROYAL_FLUSH, //A, K, Q, J, 10, all the same suit.

        STRAIGHT_FLUSH, //five cards of the same suit and consecutive ranking

        FOUR_OF_A_KIND, //four cards of the same ranking

        FULL_HOUSE, //three cards of the same rank along with two cards of the same rank

        FLUSH, //five cards of the same suit

        STRAIGHT, //five cards in consecutive ranking

        THREE_OF_A_KIND, //three cards of the same rank

        TWO_PAIR, //two cards of the same rank along with another two cards of the same rank

        ONE_PAIR, //two cards of the same rank

        HIGH_CARD //highest card in the player’s hand

    };

    static std::map<Scores, std::string> scoresToString;

    static std::string enumToString(Scores score);

    std::vector<Scores> scores;

    void operator+=(const Scores& score);

    friend bool operator==(const PokerScoreCard& p, Scores score);

    int size();

    Scores& operator[](unsigned int index);

    PokerScoreCard();


};


#endif //POKER_PROJECT_PART1_POKERSCORECARD_H
