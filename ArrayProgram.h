//
// Created by Jason on 6/9/2024.
//

#ifndef SFML_PROJECT_ARRAYPROGRAM_H
#define SFML_PROJECT_ARRAYPROGRAM_H
#include "Program.h"
#include "SFML/Graphics.hpp"
#include "SFMLgrid.h"

class ArrayProgram : public Program {
private:
    SFMLGrid grid;

public:
    ArrayProgram();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
};


#endif //SFML_PROJECT_ARRAYPROGRAM_H
