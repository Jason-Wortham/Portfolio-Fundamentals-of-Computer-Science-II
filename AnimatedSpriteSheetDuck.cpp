//
// Created by Jason on 5/16/2024.
//

#include "AnimatedSpriteSheetduck.h"
#include <iostream>

void AnimatedSpriteSheetDuck::init(const std::string &filepath) {
    if(!texture.loadFromFile(filepath)) {
        exit(28);
    }

    int width = texture.getSize().x;
    int height = texture.getSize().y;
    intRect = sf::IntRect(0, 0, width, height);
    setTexture(texture);
    setTextureRect(intRect);
}

AnimatedSpriteSheetDuck::AnimatedSpriteSheetDuck(const std::string &filepath) {
    init(filepath);
}

AnimatedSpriteSheetDuck::AnimatedSpriteSheetDuck()
        : AnimatedSpriteSheetDuck("lake_background2.png") {

}

void AnimatedSpriteSheetDuck::loadTexture(const std::string& filepath) {
    texture.loadFromFile(filepath);

    int width = texture.getSize().x;
    int height = texture.getSize().y;
    intRect = sf::IntRect(0, 0, width, height);
    setTexture(texture);
    setTextureRect(intRect);
}