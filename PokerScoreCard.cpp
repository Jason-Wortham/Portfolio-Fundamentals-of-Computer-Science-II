//
// Created by Jason on 4/13/2024.
//

#include "PokerScoreCard.h"

void PokerScoreCard::operator+=(const Scores& score) {
    scores.push_back(score);
}

bool operator==(const PokerScoreCard& p, PokerScoreCard::Scores score) {
    int sameScore = 0;
    for(int i = 0; i < p.scores.size(); i++) {
        if(p.scores[i] == score) {
            sameScore ++;
        }
    }
    if(sameScore > 0) {
        return true;
    }
    else {
        return false;
    }
}

int PokerScoreCard::size() {
    return scores.size();
}

PokerScoreCard::Scores& PokerScoreCard::operator[](unsigned int index) {
    return scores[index];
}

PokerScoreCard::PokerScoreCard() {

}

std::map<PokerScoreCard::Scores, std::string> PokerScoreCard::scoresToString = { { PokerScoreCard::ROYAL_FLUSH, "Royal Flush" },
                                                        { PokerScoreCard::STRAIGHT_FLUSH, "Straight Flush" },
                                                        { PokerScoreCard::FOUR_OF_A_KIND, "Four of a Kind" },
                                                        { PokerScoreCard::FULL_HOUSE, "Full House" },
                                                        { PokerScoreCard::FLUSH, "Flush" },
                                                        { PokerScoreCard::STRAIGHT, "Straight" },
                                                        { PokerScoreCard::THREE_OF_A_KIND, "Three of a Kind" },
                                                        { PokerScoreCard::TWO_PAIR, "Two Pair" },
                                                        { PokerScoreCard::ONE_PAIR, "One Pair" },
                                                        { PokerScoreCard::HIGH_CARD, "High Card" } };

std::string PokerScoreCard::enumToString(PokerScoreCard::Scores score) {
    return scoresToString[score];
}