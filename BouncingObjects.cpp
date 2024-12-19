//
// Created by Jason on 6/9/2024.
//
#include "BouncingObjects.h"

BouncingObjects::BouncingObjects() {

}

void BouncingObjects::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(event.type == sf::Event::Closed) {
        window.close();
    }
}

void BouncingObjects::run(sf::RenderWindow& window, sf::RenderStates states) {

        ball.setFillColor(sf::Color::Blue);

        window.draw(ball);
}

void BouncingObjects::update() {
    ball.bounce();
}

std::string BouncingObjects::getTitle() const {
    return "Bouncing Objects";
}