//
// Created by Jason on 6/9/2024.
//

#ifndef SFML_PROJECT_POKERPROGRAM_H
#define SFML_PROJECT_POKERPROGRAM_H
#include <SFML/Graphics.hpp>
#include "Program.h"
#include "Fonts.h"


class PokerProgram : public Program {
private:
    sf::Text fullHouseText;
    sf::Text threeKindText;
    sf::Text onePairText;
    sf::Text twoPairText;
    sf::Text highCardText;
    sf::Text royalFlushText;
    sf::Text fourKindText;
    sf::Text straightFlushText;
    sf::Text straightText;
    sf::Text flushText;

    void caclulateProbabilities();
public:
    PokerProgram();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
    sf::Font font;
};


#endif //SFML_PROJECT_POKERPROGRAM_H
