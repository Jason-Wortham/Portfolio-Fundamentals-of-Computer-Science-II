//
// Created by Jason on 6/9/2024.
//

#include "PokerProgram.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "AnimatedSpriteSheet.h"
#include "cardHand.h"
#include "cardHandScorer.h"
#include "PokerScoreCard.h"
#include <ctime>

PokerProgram::PokerProgram() {
    font.loadFromFile("OpenSans-Bold.ttf");
    caclulateProbabilities();
}

void PokerProgram::caclulateProbabilities() {
    srand(time(NULL));

    int scoreCount[10] = {0};

    for(int j = 0; j < 1000; j ++) {
        Deck deck1;
        deck1.shuffle();
        cardHand hand1;
        for (int i = 0; i < 5; i++) {
            Card dealtCard = deck1.dealCard();
            hand1.addCard(dealtCard);
        }

        PokerScoreCard pokerScore = cardHandScorer::scorer(hand1);

        for(int i = 0; i < pokerScore.size(); i ++) {
            PokerScoreCard::Scores currentScore = pokerScore[i];
            switch (currentScore) {
                case PokerScoreCard::ROYAL_FLUSH:
                    scoreCount[0]++;
                    break;
                case PokerScoreCard::STRAIGHT_FLUSH:
                    scoreCount[1]++;
                    break;
                case PokerScoreCard::FOUR_OF_A_KIND:
                    scoreCount[2]++;
                    break;
                case PokerScoreCard::FULL_HOUSE:
                    scoreCount[3]++;
                    break;
                case PokerScoreCard::FLUSH:
                    scoreCount[4]++;
                    break;
                case PokerScoreCard::STRAIGHT:
                    scoreCount[5]++;
                    break;
                case PokerScoreCard::THREE_OF_A_KIND:
                    scoreCount[6]++;
                    break;
                case PokerScoreCard::TWO_PAIR:
                    scoreCount[7]++;
                    break;
                case PokerScoreCard::ONE_PAIR:
                    scoreCount[8]++;
                    break;
                case PokerScoreCard::HIGH_CARD:
                    scoreCount[9]++;
                    break;
                default:
                    break;
            }
        }
    }

    int royalFlushProp  = 0;
    int straightFlushProp  = 0;
    int fourKindProp  = 0;
    int fullHouseProp  = 0;
    int flushProp  = 0;
    int straightProp  = 0;
    int threeKindProp  = 0;
    int twoPairProp  = 0;
    int onePairProp  = 0;
    int highCardProp  = 0;

    if(scoreCount[0] > 0)
        royalFlushProp  = scoreCount[9]/scoreCount[0];

    if(scoreCount[1] > 0)
        straightFlushProp  = scoreCount[9]/scoreCount[1];

    if(scoreCount[2] > 0)
        fourKindProp  = scoreCount[9]/scoreCount[2];

    if(scoreCount[3] > 0)
        fullHouseProp  = scoreCount[9]/scoreCount[3];

    if(scoreCount[4] > 0)
        flushProp  = scoreCount[9]/scoreCount[4];

    if(scoreCount[5] > 0)
        straightProp  = scoreCount[9]/scoreCount[5];

    if(scoreCount[6] > 0)
        threeKindProp  = scoreCount[9]/scoreCount[6];

    if(scoreCount[7] > 0)
        twoPairProp  = scoreCount[9]/scoreCount[7];

    if(scoreCount[8] > 0)
        onePairProp  = scoreCount[9]/scoreCount[8];

    if(scoreCount[9] > 0)
        highCardProp  = scoreCount[9]/scoreCount[9];

    std::string royalFlushString = "Royal Flush - 1:" + std::to_string(royalFlushProp);
    std::string straightFlushString = "Straight Flush - 1:" + std::to_string(straightFlushProp);
    std::string fourKindString = "Four of a Kind - 1:" + std::to_string(fourKindProp);
    std::string fullHouseString = "Full House - 1:" + std::to_string(fullHouseProp);
    std::string flushString = "Flush - 1:" + std::to_string(flushProp);
    std::string straightString = "Straight - 1:" + std::to_string(straightProp);
    std::string threeKindString = "Three of a Kind - 1:" + std::to_string(threeKindProp);
    std::string twoPairString = "Two Pair - 1:" + std::to_string(twoPairProp);
    std::string onePairString = "One Pair - 1:" + std::to_string(onePairProp);
    std::string highCardString = "High Card - 1:" + std::to_string(highCardProp);


    fullHouseText.setString(fullHouseString);
    fullHouseText.setFont(font);
    fullHouseText.setCharacterSize(18);
    fullHouseText.setFillColor(sf::Color::White);
    fullHouseText.setPosition(300.f, 25.f);

    threeKindText.setString(threeKindString);
    threeKindText.setFont(font);
    threeKindText.setCharacterSize(18);
    threeKindText.setFillColor(sf::Color::White);
    threeKindText.setPosition(300.f, 100.f);

    onePairText.setString(onePairString);
    onePairText.setFont(font);
    onePairText.setCharacterSize(18);
    onePairText.setFillColor(sf::Color::White);
    onePairText.setPosition(300.f, 180.f);

    twoPairText.setString(twoPairString);
    twoPairText.setFont(font);
    twoPairText.setCharacterSize(18);
    twoPairText.setFillColor(sf::Color::White);
    twoPairText.setPosition(300.f, 260.f);

    highCardText.setString(highCardString);
    highCardText.setFont(font);
    highCardText.setCharacterSize(18);
    highCardText.setFillColor(sf::Color::White);
    highCardText.setPosition(300.f, 340.f);

    royalFlushText.setString(royalFlushString);
    royalFlushText.setFont(font);
    royalFlushText.setCharacterSize(18);
    royalFlushText.setFillColor(sf::Color::White);
    royalFlushText.setPosition(300.f, 415.f);

    straightFlushText.setString(straightFlushString);
    straightFlushText.setFont(font);
    straightFlushText.setCharacterSize(18);
    straightFlushText.setFillColor(sf::Color::White);
    straightFlushText.setPosition(300.f, 495.f);

    fourKindText.setString(fourKindString);
    fourKindText.setFont(font);
    fourKindText.setCharacterSize(18);
    fourKindText.setFillColor(sf::Color::White);
    fourKindText.setPosition(300.f, 580.f);

    flushText.setString(flushString);
    flushText.setFont(font);
    flushText.setCharacterSize(18);
    flushText.setFillColor(sf::Color::White);
    flushText.setPosition(300.f, 660.f);

    straightText.setString(straightString);
    straightText.setFont(font);
    straightText.setCharacterSize(18);
    straightText.setFillColor(sf::Color::White);
    straightText.setPosition(300.f, 735.f);
}

void PokerProgram::run(sf::RenderWindow& window, sf::RenderStates states) {

    AnimatedSpriteSheet sprite("Deck.png", 4, 13);

    //full house
    sprite.setRowAndCol(2,0);
    sprite.setPosition(0, 0);
    window.draw(sprite);

    sprite.setRowAndCol(2,9);
    sprite.setPosition(49, 0);
    window.draw(sprite);

    sprite.setRowAndCol(2,10);
    sprite.setPosition(98, 0);
    window.draw(sprite);

    sprite.setRowAndCol(2,11);
    sprite.setPosition(147, 0);
    window.draw(sprite);

    sprite.setRowAndCol(2,12);
    sprite.setPosition(196, 0);
    window.draw(sprite);

    //three of a kind
    sprite.setRowAndCol(0,0);
    sprite.setPosition(0, 80);
    window.draw(sprite);

    sprite.setRowAndCol(1,0);
    sprite.setPosition(49, 80);
    window.draw(sprite);

    sprite.setRowAndCol(2,1);
    sprite.setPosition(98, 80);
    window.draw(sprite);

    sprite.setRowAndCol(3,0);
    sprite.setPosition(147, 80);
    window.draw(sprite);

    sprite.setRowAndCol(3,11);
    sprite.setPosition(196, 80);
    window.draw(sprite);

    //one pair
    sprite.setRowAndCol(0,8);
    sprite.setPosition(1, 160);
    window.draw(sprite);

    sprite.setRowAndCol(1,3);
    sprite.setPosition(49, 160);
    window.draw(sprite);

    sprite.setRowAndCol(3,11);
    sprite.setPosition(98, 160);
    window.draw(sprite);

    sprite.setRowAndCol(2,6);
    sprite.setPosition(147, 160);
    window.draw(sprite);

    sprite.setRowAndCol(0,11);
    sprite.setPosition(196, 160);
    window.draw(sprite);

    //two pair
    sprite.setRowAndCol(1,7);
    sprite.setPosition(1, 240);
    window.draw(sprite);

    sprite.setRowAndCol(0,3);
    sprite.setPosition(49, 240);
    window.draw(sprite);

    sprite.setRowAndCol(2,7);
    sprite.setPosition(98, 240);
    window.draw(sprite);

    sprite.setRowAndCol(3,4);
    sprite.setPosition(147, 240);
    window.draw(sprite);

    sprite.setRowAndCol(1,4);
    sprite.setPosition(196, 240);
    window.draw(sprite);

    //high card
    sprite.setRowAndCol(3,5);
    sprite.setPosition(1, 320);
    window.draw(sprite);

    sprite.setRowAndCol(2,10);
    sprite.setPosition(49, 320);
    window.draw(sprite);

    sprite.setRowAndCol(3,2);
    sprite.setPosition(98, 320);
    window.draw(sprite);

    sprite.setRowAndCol(0,7);
    sprite.setPosition(147, 320);
    window.draw(sprite);

    sprite.setRowAndCol(1,4);
    sprite.setPosition(196, 320);
    window.draw(sprite);

    //royal flush
    sprite.setRowAndCol(1,0);
    sprite.setPosition(1, 400);
    window.draw(sprite);

    sprite.setRowAndCol(1,9);
    sprite.setPosition(49, 400);
    window.draw(sprite);

    sprite.setRowAndCol(1,10);
    sprite.setPosition(98, 400);
    window.draw(sprite);

    sprite.setRowAndCol(1,11);
    sprite.setPosition(147, 400);
    window.draw(sprite);

    sprite.setRowAndCol(1,12);
    sprite.setPosition(196, 400);
    window.draw(sprite);

    //straight flush
    sprite.setRowAndCol(3,4);
    sprite.setPosition(1, 480);
    window.draw(sprite);

    sprite.setRowAndCol(3,5);
    sprite.setPosition(49, 480);
    window.draw(sprite);

    sprite.setRowAndCol(3,6);
    sprite.setPosition(98, 480);
    window.draw(sprite);

    sprite.setRowAndCol(3,7);
    sprite.setPosition(147, 480);
    window.draw(sprite);

    sprite.setRowAndCol(3,8);
    sprite.setPosition(196, 480);
    window.draw(sprite);

    //four of a kind
    sprite.setRowAndCol(0,7);
    sprite.setPosition(1, 560);
    window.draw(sprite);

    sprite.setRowAndCol(2,7);
    sprite.setPosition(49, 560);
    window.draw(sprite);

    sprite.setRowAndCol(3,7);
    sprite.setPosition(98, 560);
    window.draw(sprite);

    sprite.setRowAndCol(1,7);
    sprite.setPosition(147, 560);
    window.draw(sprite);

    sprite.setRowAndCol(3,10);
    sprite.setPosition(196, 560);
    window.draw(sprite);

    //flush
    sprite.setRowAndCol(3,1);
    sprite.setPosition(1, 640);
    window.draw(sprite);

    sprite.setRowAndCol(3,4);
    sprite.setPosition(49, 640);
    window.draw(sprite);

    sprite.setRowAndCol(3,7);
    sprite.setPosition(98, 640);
    window.draw(sprite);

    sprite.setRowAndCol(3,9);
    sprite.setPosition(147, 640);
    window.draw(sprite);

    sprite.setRowAndCol(3,12);
    sprite.setPosition(196, 640);
    window.draw(sprite);

    //straight
    sprite.setRowAndCol(3,7);
    sprite.setPosition(1, 720);
    window.draw(sprite);

    sprite.setRowAndCol(0,8);
    sprite.setPosition(49, 720);
    window.draw(sprite);

    sprite.setRowAndCol(2,9);
    sprite.setPosition(98, 720);
    window.draw(sprite);

    sprite.setRowAndCol(0,10);
    sprite.setPosition(147, 720);
    window.draw(sprite);

    sprite.setRowAndCol(1, 11);
    sprite.setPosition(196, 720);
    window.draw(sprite);

    window.draw(fullHouseText);
    window.draw(threeKindText);
    window.draw(onePairText);
    window.draw(twoPairText);
    window.draw(highCardText);
    window.draw(royalFlushText);
    window.draw(fourKindText);
    window.draw(straightFlushText);
    window.draw(straightText);
    window.draw(flushText);
}


void PokerProgram::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }

}


void PokerProgram::update() {

}

std::string PokerProgram::getTitle() const {
    return "Poker Program";
}