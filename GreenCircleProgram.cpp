//
// Created by Jason on 6/9/2024.
//

#include "GreenCircleProgram.h"

GreenCircleProgram::GreenCircleProgram() {
    circle.setRadius(250.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(710.f, 50.f);
}


void GreenCircleProgram::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

void GreenCircleProgram::run(sf::RenderWindow& window, sf::RenderStates states) {
    window.draw(circle);
}


void GreenCircleProgram::update() {

}

std::string GreenCircleProgram::getTitle() const {
    return "Green Circle Program";
}
