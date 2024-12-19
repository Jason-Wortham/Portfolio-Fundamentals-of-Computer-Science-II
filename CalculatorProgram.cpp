//
// Created by Jason on 6/10/2024.
//

#include "CalculatorProgram.h"

CalculatorProgram::CalculatorProgram() {

}
void CalculatorProgram::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if(sf::Event::Closed == event.type) {
        window.close();
    }

    for(int i = 0; i < calculator.getButtons().size(); i++) {
        calculator.getButtons()[i].eventHandler(window, event);
    }

    calculator.update(window);
}

void CalculatorProgram::run(sf::RenderWindow& window, sf::RenderStates states) {
    for(int i = 0; i < calculator.getButtons().size(); i++) {
        window.draw(calculator.getButtons()[i]);
    }
    window.draw(calculator);
}

void CalculatorProgram::update() {

}

std::string CalculatorProgram::getTitle() const {
    return "Calculator";
}