//
// Created by Jason on 5/20/2024.
//

#ifndef SFML_PROJECT_DISPLAY_H
#define SFML_PROJECT_DISPLAY_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "CircleButton.h"
#include "Fonts.h"

class Display : public sf::RectangleShape {
private:
    sf::Text text;
    void positionText();

public:
    //// get the chars typed in the keyboard and display them in the screen
    Display();
    void update(const std::string& text);
    void clear();
    sf::Text getText() const;
    std::string getValue();
};


#endif //SFML_PROJECT_DISPLAY_H
