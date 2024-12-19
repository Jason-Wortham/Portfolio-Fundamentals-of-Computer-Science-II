//
// Created by Jason on 6/9/2024.
//

#include "ArrayProgram.h"

ArrayProgram::ArrayProgram() {

}

void ArrayProgram::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(sf::Event::Closed == event.type) {
        window.close();
    }

    grid.eventHandler(window, event);
}

void ArrayProgram::run(sf::RenderWindow& window, sf::RenderStates states) {
    grid.draw(window, sf::RenderStates::Default);
}

void ArrayProgram::update() {

}

std::string ArrayProgram::getTitle() const {
    return "2D Array";
}
