//
// Created by Jason on 6/9/2024.
//

#ifndef SFML_PROJECT_ANIMATEDSPRITE_H
#define SFML_PROJECT_ANIMATEDSPRITE_H
#include "Program.h"
#include "AnimatedSpriteSheet.h"

class AnimatedSprite : public Program {
private:
    AnimatedSpriteSheet sprite;
public:
    AnimatedSprite();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void run(sf::RenderWindow& window, sf::RenderStates states);
    void update();
    std::string getTitle() const;
};


#endif //SFML_PROJECT_ANIMATEDSPRITE_H
