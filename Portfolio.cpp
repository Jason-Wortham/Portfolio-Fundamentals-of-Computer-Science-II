//
// Created by Jason on 6/9/2024.
//
#include "Portfolio.h"
#include "GreenCircleProgram.h"
#include "PokerProgram.h"
#include "BouncingObjects.h"
#include "ArrayProgram.h"
#include "CalculatorProgram.h"
#include "AnimatedSprite.h"
#include "DuckLakeDash.h"
#include <iostream>

Portfolio::Portfolio() : currentIndex(0),
                        currentState(MENU),
                        leftButton("Previous", sf::Vector2f(140.f, 50.f), sf::Color::White, sf::Color::Blue, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), sf::Vector2f(150, 900)),
                        rightButton("Next", sf::Vector2f(100.f, 50.f), sf::Color::White, sf::Color::Blue, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), sf::Vector2f(1700, 900)),
                        startButton("Start", sf::Vector2f(100.f, 50.f), sf::Color::White, sf::Color::Blue, Fonts::getFont(Fonts::OPEN_SANS_REGULAR), sf::Vector2f(900, 900)) {

    title.setString("");
    title.setCharacterSize(100);
    font.loadFromFile("OpenSans-Bold.ttf");
    title.setFont(font);
    title.setFillColor(sf::Color::White);

    programs.push_back(new GreenCircleProgram());
    programs.push_back(new PokerProgram());
    programs.push_back(new BouncingObjects());
    programs.push_back(new ArrayProgram());
    programs.push_back(new CalculatorProgram());
    programs.push_back(new AnimatedSprite());
    programs.push_back(new DuckLakeDash());
}

Portfolio::~Portfolio() {
    for(int i = 0; i < programs.size(); i++) {
        delete programs[i];
    }
}

void Portfolio::eventHandler(sf::RenderWindow& window, sf::Event event) {
    leftButton.eventHandler(window, event);
    rightButton.eventHandler(window, event);

    if(currentState == MENU) {
        startButton.eventHandler(window, event);

        if(MouseEvents::isClicked(leftButton, window)) {
            if(currentIndex > 0) {
                currentIndex --;
            }
        }
        if(MouseEvents::isClicked(rightButton, window)) {
            if(currentIndex < programs.size()) {
                if(currentIndex < (programs.size() - 1)) {
                    currentIndex ++;
                }
            }
        }
        if(MouseEvents::isClicked(startButton, window)) {
            currentState = RUNNING;
            programs[currentIndex]->run(window, sf::RenderStates::Default);
        }
    }
    else if(currentState == RUNNING) {
        programs[currentIndex]->eventHandler(window, event);

        if(MouseEvents::isClicked(leftButton, window)) {
            window.clear();
            if(currentIndex > 0) {
                if(currentIndex > 0) {
                    currentIndex --;
                }
            }
            currentState = MENU;
        }
        if(MouseEvents::isClicked(rightButton, window)) {
            window.clear();
            if(currentIndex < programs.size()) {
                if(currentIndex < (programs.size() - 1)) {
                    currentIndex ++;
                }
            }
            std::cout << currentIndex;
            currentState = MENU;
        }
    }
}

void Portfolio::update() {
    if(currentState == RUNNING) {
        programs[currentIndex]->update();
    }
}

void Portfolio::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    if(currentState == MENU) {
        window.draw(startButton);
        title.setString(programs[currentIndex]->getTitle());
        sf::FloatRect titleBounds = title.getLocalBounds();
        title.setOrigin(titleBounds.width / 2, titleBounds.height / 2);
        title.setPosition(window.getSize().x / 2, window.getSize().y / 2);
        window.draw(title);
    }
    else if(currentState == RUNNING) {
        programs[currentIndex]->run(window, sf::RenderStates::Default);
    }

    window.draw(leftButton);
    window.draw(rightButton);

    window.display();
}
