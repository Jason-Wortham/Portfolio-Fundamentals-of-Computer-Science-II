//
// Created by Jason on 6/10/2024.
//

#ifndef SFML_PROJECT_CALCULATORPROGRAM_H
#define SFML_PROJECT_CALCULATORPROGRAM_H
#include "Program.h"
#include <SFML/Graphics.hpp>
#include "Calculator.h"

class CalculatorProgram : public Program {
private:
    Calculator calculator;
public:
    CalculatorProgram();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
};


#endif //SFML_PROJECT_CALCULATORPROGRAM_H
