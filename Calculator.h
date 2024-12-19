//
// Created by Jason on 5/20/2024.
//

#ifndef SFML_PROJECT_CALCULATOR_H
#define SFML_PROJECT_CALCULATOR_H
#include <SFML/Graphics.hpp>
#include "CircleButton.h"
#include "Display.h"
#include <vector>
#include "Position.h"
#include "Fonts.h"

class Calculator : public sf::RectangleShape {
private:
    Display _display;
    std::vector<CircleButton> _buttons;
    std::string postfixString = "";

public:
    Calculator();
    void clear();
    void update(sf::RenderWindow& window);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    std::vector<CircleButton>& getButtons();
};


#endif //SFML_PROJECT_CALCULATOR_H
