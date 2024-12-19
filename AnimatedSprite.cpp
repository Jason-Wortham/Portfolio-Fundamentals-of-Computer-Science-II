//
// Created by Jason on 6/9/2024.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() {

}

void AnimatedSprite::eventHandler(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::Closed){
        window.close();
    }
}

void AnimatedSprite::run(sf::RenderWindow& window, sf::RenderStates states) {
    window.draw(sprite);
}

void AnimatedSprite::update() {
    sprite.animate();
}

std::string AnimatedSprite::getTitle() const {
    return "Animated Sprite";
}



