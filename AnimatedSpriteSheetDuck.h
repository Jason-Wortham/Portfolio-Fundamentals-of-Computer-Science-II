//
// Created by Jason on 5/16/2024.
//

#ifndef SFML_PROJECT_ANIMATEDSPRITESHEET_H
#define SFML_PROJECT_ANIMATEDSPRITESHEET_H
#include <string>
#include <SFML/Graphics.hpp>

class AnimatedSpriteSheetDuck : public sf::Sprite {
private:
    sf::IntRect intRect;
    sf::Texture texture;
    void init(const std::string& filepath);
public:
    AnimatedSpriteSheetDuck(const std::string& filepath);
    AnimatedSpriteSheetDuck();
    void loadTexture(const std::string& filepath);
};


#endif //SFML_PROJECT_ANIMATEDSPRITESHEET_H