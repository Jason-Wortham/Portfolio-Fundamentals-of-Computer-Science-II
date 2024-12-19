//
// Created by Jason on 6/9/2024.
//

#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Program.h"
#include "Button.h"

class Portfolio {
public:
    enum PortfolioState {
        MENU,
        RUNNING
    };

    Portfolio();
    ~Portfolio();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderWindow& window);

private:
    std::vector<Program*> programs;
    int currentIndex;
    PortfolioState currentState;

    Button leftButton;
    Button rightButton;
    Button startButton;
    sf::Text title;
    sf::Font font;
};

#endif // PORTFOLIO_H
