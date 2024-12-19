//
// Created by Jason on 5/21/2024.
//

#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP
#include "Position.h"
#include "CircleButton.h"

template<typename T, typename S>
void Position::left(const T &constObj, S &obj, float spacing) {
    sf::Vector2f position = constObj.getPosition();
    position.x -= (constObj.getRadius() * 2 + spacing);
    obj.setPosition(position);
    obj.centerText(obj, obj.getText());
}

template<typename T, typename S>
void Position::right(const T &constObj, S &obj, float spacing) {
    sf::Vector2f position = constObj.getPosition();
    position.x += (constObj.getRadius() * 2 + spacing);
    obj.setPosition(position);
    obj.centerText(obj, obj.getText());
}

template<typename T, typename S>
void Position::top(const T &constObj, S &obj, float spacing) {
    sf::Vector2f position = constObj.getPosition();
    position.y -= (constObj.getRadius() * 2 + spacing);
    obj.setPosition(position);
    obj.centerText(obj, obj.getText());
}

template<typename T, typename S>
void Position::bottom(const T &constObj, S &obj, float spacing) {
    sf::Vector2f position = constObj.getPosition();
    position.y += (constObj.getRadius() * 2 + spacing);
    obj.setPosition(position);
    obj.centerText(obj, obj.getText());
}

#endif //SFML_PROJECT_POSITION_CPP
