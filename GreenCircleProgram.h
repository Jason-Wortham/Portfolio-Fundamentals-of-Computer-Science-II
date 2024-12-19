//
// Created by Jason on 6/9/2024.
//

#ifndef SFML_PROJECT_GREENCIRCLEPROGRAM_H
#define SFML_PROJECT_GREENCIRCLEPROGRAM_H

#include "Program.h"
#include <SFML/Graphics.hpp>

class GreenCircleProgram : public Program {
private:
    sf::CircleShape circle;

public:
    GreenCircleProgram();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
};


#endif //SFML_PROJECT_GREENCIRCLEPROGRAM_H
