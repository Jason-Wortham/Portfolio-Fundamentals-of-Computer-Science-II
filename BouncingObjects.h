//
// Created by Jason on 6/9/2024.
//

#ifndef SFML_PROJECT_BOUNCINGOBJECTS_H
#define SFML_PROJECT_BOUNCINGOBJECTS_H
#include "Program.h"
#include "ball.h"

class BouncingObjects : public Program {
private:
    Ball ball;
public:
    BouncingObjects();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
};


#endif //SFML_PROJECT_BOUNCINGOBJECTS_H
