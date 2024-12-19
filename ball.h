//
// Created by Jason on 3/25/2024.
//

#ifndef SFML_PROJECT_BALL_H
#define SFML_PROJECT_BALL_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Ball : public sf::CircleShape  {
private:
 sf::Vector2f windowSize;
 int radius;
 int pointCount;
 float posX;
 float posY;
 sf::Vector2f velocity;
public:
    Ball(sf::Vector2f windowSize, int radius, int pointCount, float posX, float posY, sf::Vector2f velocity);
    Ball();
    void bounce();
    void setWindowSize(sf::Vector2f windowSize);
    sf::Vector2f getWindowSize();
    void setVelocity(sf::Vector2f velocity);
    sf::Vector2f getVelocity();

};



#endif //SFML_PROJECT_BALL_H
