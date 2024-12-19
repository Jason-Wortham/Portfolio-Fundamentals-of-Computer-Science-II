//
// Created by Jason on 4/4/2024.
//

#ifndef POKER_PROJECT_PART1_CARD_H
#define POKER_PROJECT_PART1_CARD_H
#include <iostream>


class Card {
    private:
        std::string suit;
        std::string rank;

    public:
        std::string getSuit();
        std::string getRank();
        void setSuit(std::string suit);
        void setRank(std::string rank);
        friend std::ostream& operator<<(std::ostream& out, const Card& card);
        Card(std::string suit, std::string value);
        Card();
};


#endif //POKER_PROJECT_PART1_CARD_H
