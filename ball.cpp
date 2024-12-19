//
// Created by Jason on 3/25/2024.
//

#include "ball.h"

Ball::Ball(sf::Vector2f windowSize, int radius, int pointCount, float posX, float posY, sf::Vector2f velocity) {

    Ball::windowSize = windowSize;
    Ball::radius = radius;
    Ball::pointCount = pointCount;
    Ball::posX = posX;
    Ball::posY = posY;
    Ball::velocity = velocity;

    setRadius(radius);
    setPointCount(pointCount);
    setPosition({posX, posY});

}

Ball::Ball() {

    Ball::windowSize.x = 1920;
    Ball::windowSize.y = 1080;
    Ball::radius = 50;
    Ball::pointCount = 30;
    Ball::posX = 10;
    Ball::posY = 10;
    Ball::velocity.x = 0.3;
    Ball::velocity.y = 0.3;

    setRadius(radius);
    setPointCount(pointCount);
    setPosition({posX, posY});

}

void Ball::bounce() {

    sf::Vector2f position = getPosition();

    if(position.x <= 0 || position.x >= (windowSize.x - radius*2 - 5)) {
        velocity.x *= -1;
    }
    if(position.y <= 0 || position.y >= (windowSize.y - radius*4)) {
        velocity.y *= -1;
    }

    move(velocity);
}

void Ball::setWindowSize(sf::Vector2f windowSize) {
    Ball::windowSize = windowSize;
}

sf::Vector2f Ball::getWindowSize() {
    return windowSize;
}

void Ball::setVelocity(sf::Vector2f velocity) {
    Ball::velocity = velocity;
}

sf::Vector2f Ball::getVelocity() {
    return velocity;
}
