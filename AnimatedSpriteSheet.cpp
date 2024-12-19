//
// Created by Jason on 4/11/2024.
//

#include "AnimatedSpriteSheet.h"

void AnimatedSpriteSheet::init(const std::string &filepath, int rows, int cols) {
    if(!texture.loadFromFile(filepath)) {
        exit(28);
    }
    int width = texture.getSize().x;
    int height = texture.getSize().y;
    intRect.width = width / cols;
    intRect.height = height / rows;
    setTextureRect(intRect);
    setTexture(texture);
}

AnimatedSpriteSheet::AnimatedSpriteSheet(const std::string &filepath, int rows, int cols) {
   init(filepath, rows, cols);
}

AnimatedSpriteSheet::AnimatedSpriteSheet()
: AnimatedSpriteSheet("Deck.png", 4, 13) {

}

void AnimatedSpriteSheet::animate() {
    if(clock.getElapsedTime().asMilliseconds() > 250) {
        if(intRect.left >= texture.getSize().x - intRect.width) {
            intRect.left = 0;
        }
        else {
            intRect.left += intRect.width;
            setTextureRect(intRect);
            clock.restart();
        }
    }
}

void AnimatedSpriteSheet::setRowAndCol(int row, int col) {
    intRect.left = col * intRect.width;
    intRect.top = row * intRect.height;
    setTextureRect(intRect);
}