//
// Created by Jason on 5/30/2024.
//

#ifndef PORTFOLIO_PROGRAM_H
#define PORTFOLIO_PROGRAM_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Program {
public:
    virtual void eventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void run(sf::RenderWindow& window, sf::RenderStates states) = 0;
    virtual void update() = 0;
    virtual std::string getTitle() const = 0;
};

#endif //PORTFOLIO_PROGRAM_H
