//
// Created by Jason on 6/7/2024.
//

#include "ButtonDuck.h"

ButtonDuck::ButtonDuck()
        : ButtonDuck("", sf::Vector2f(50.f, 50.f),
                       sf::Color::Black,
                       sf::Color::White, Fonts::getFont(Fonts::OPEN_SANS_REGULAR)) {

}

ButtonDuck::ButtonDuck(const std::string &text)
        : ButtonDuck(text, sf::Vector2f(50.f, 50.f)) {

}

ButtonDuck::ButtonDuck(const std::string &text, sf::Vector2f size)
        : ButtonDuck(text, size,
                        sf::Color::Black,
                        sf::Color::White,
                       Fonts::getFont(Fonts::OPEN_SANS_REGULAR)) {

}

ButtonDuck::ButtonDuck(const std::string &text, sf::Vector2f size, const sf::Color defaultColor,
                           const sf::Color hoveredColor, sf::Font& font) : sf::RectangleShape(size),
                                                                           defaultColor(defaultColor), hoveredColor(hoveredColor), text(text, font) {

    setFillColor(defaultColor);
    this -> text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    setPosition(25, 280);

    centerText(*this, this->text);

    sf::RectangleShape::setFillColor(defaultColor);
}

void ButtonDuck::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(*this, window))
    {
        sf::RectangleShape::setFillColor(hoveredColor);
    }
    else {
        sf::RectangleShape::setFillColor(defaultColor);
    }

    if(MouseEvents::isClicked(*this, window))
    {
        sf::RectangleShape::setFillColor(sf::Color::White);
    }

}

std::string ButtonDuck::getValue() const {
    return text.getString();
}

const sf::Color &ButtonDuck::getDefaultColor() const {
    return defaultColor;
}

void ButtonDuck::setDefaultColor(const sf::Color &defaultColor) {
    ButtonDuck::defaultColor = defaultColor;
}

const sf::Color &ButtonDuck::getHoveredColor() const {
    return hoveredColor;
}

void ButtonDuck::setHoveredColor(const sf::Color &hoveredColor) {
    ButtonDuck::hoveredColor = hoveredColor;
}

void ButtonDuck::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((sf::RectangleShape)*this, states);
    target.draw(text, states);
}

sf::Text& ButtonDuck::getText() {
    return ButtonDuck::text;
}

std::string ButtonDuck::getString() {
    return text.getString();
}
