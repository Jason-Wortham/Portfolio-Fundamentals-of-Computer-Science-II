//
// Created by Jason on 4/13/2024.
//

#include "cardHandScorer.h"

 PokerScoreCard cardHandScorer::scorer(cardHand hand) {

    PokerScoreCard scoreCard;
    int cardTypes[13] = {0};
    bool sameSuit = false;
    bool isTwoPair = false;

    for (int i = 0; i < hand.getHand().size(); i++) {
        if(hand.getHand()[i].getRank() == "Ace") {
            cardTypes[0] ++;
        }
        else if(hand.getHand()[i].getRank() == "Two") {
            cardTypes[1] ++;
        }
        else if(hand.getHand()[i].getRank() == "Three") {
            cardTypes[2] ++;
        }
        else if(hand.getHand()[i].getRank() == "Four") {
            cardTypes[3] ++;
        }
        else if(hand.getHand()[i].getRank() == "Five") {
            cardTypes[4] ++;
        }
        else if(hand.getHand()[i].getRank() == "Six") {
            cardTypes[5] ++;
        }
        else if(hand.getHand()[i].getRank() == "Seven") {
            cardTypes[6] ++;
        }
        else if(hand.getHand()[i].getRank() == "Eight") {
            cardTypes[7] ++;
        }
        else if(hand.getHand()[i].getRank() == "Nine") {
            cardTypes[8] ++;
        }
        else if(hand.getHand()[i].getRank() == "Ten") {
            cardTypes[9] ++;
        }
        else if(hand.getHand()[i].getRank() == "Jack") {
            cardTypes[10] ++;
        }
        else if(hand.getHand()[i].getRank() == "Queen") {
            cardTypes[11] ++;
        }
        else if(hand.getHand()[i].getRank() == "King") {
            cardTypes[12] ++;
        }
    }

    scoreCard += PokerScoreCard::HIGH_CARD;

     if(hand.getHand()[0].getSuit() == hand.getHand()[1].getSuit() && hand.getHand()[1].getSuit() == hand.getHand()[2].getSuit() && hand.getHand()[2].getSuit() == hand.getHand()[3].getSuit() && hand.getHand()[3].getSuit() == hand.getHand()[4].getSuit()) {
         sameSuit = true;
     }

    if(sameSuit == true) {
        scoreCard += PokerScoreCard::FLUSH;
    }

    if(cardTypes[0] == 1 && cardTypes[9] == 1 && cardTypes[10] == 1 && cardTypes[11] == 1 && cardTypes[12] == 1 && sameSuit == true) {
        scoreCard += PokerScoreCard::ROYAL_FLUSH;
    }

    int count;

    for(int j = 0; j < 13; j++) {

        if(cardTypes[j] == 1) {
            for(int k = j; k < 5; k++) {
                if (cardTypes[k] == 1) {
                    count++;
                }
            }
        }

        if(count == 5 && sameSuit == true) {
            scoreCard += PokerScoreCard::STRAIGHT_FLUSH;
        }
        if(count == 5) {
            scoreCard += PokerScoreCard::STRAIGHT;
        }

        break;
    }

    int sameCard;

    for(int k = 0; k < 13; k ++) {
        if(cardTypes[k] == 4) {
            scoreCard += PokerScoreCard::FOUR_OF_A_KIND;
        }
        if(cardTypes[k] == 3) {
            scoreCard += PokerScoreCard::THREE_OF_A_KIND;
        }
        if(cardTypes[k] == 2 && isTwoPair == false) {
            scoreCard += PokerScoreCard::ONE_PAIR;
        }
        for(int l = 0; l < 13; l ++) {
            if(cardTypes[k] == 2 && cardTypes[l] == 2 && k != l && isTwoPair == false) {
                scoreCard += PokerScoreCard::TWO_PAIR;
                isTwoPair = true;
            }
            if(cardTypes[k] == 2 && cardTypes[l] == 3 && k != l) {
                scoreCard += PokerScoreCard::FULL_HOUSE;
            }
        }

    }

    return scoreCard;

}