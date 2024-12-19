
    //Calculator

#include <SFML/Graphics.hpp>
#include "Portfolio.h"

    int main() {

        sf::RenderWindow window(sf::VideoMode(1920, 1080), "Portfolio Program");

        Portfolio portfolio;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                portfolio.eventHandler(window, event);
            }

            portfolio.update();

            window.clear();
            portfolio.draw(window);
        }

        return 0;
    }
