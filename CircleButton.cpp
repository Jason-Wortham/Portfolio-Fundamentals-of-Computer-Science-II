//
// Created by Jason on 5/20/2024.
//

#include "CircleButton.h"

CircleButton::CircleButton()
: CircleButton("", 50.f,
               CalculatorColorPalette::darkGrey,
               CalculatorColorPalette::lightGrey, Fonts::getFont(Fonts::OPEN_SANS_REGULAR))
{

}

CircleButton::CircleButton(const std::string &text)
        : CircleButton(text, 50.f)
{

}

CircleButton::CircleButton(const std::string &text, float radius)
        : CircleButton(text, radius,
                       CalculatorColorPalette::darkGrey,
                       CalculatorColorPalette::lightGrey,
                       Fonts::getFont(Fonts::OPEN_SANS_REGULAR))
{

}

CircleButton::CircleButton(const std::string &text, float radius, const sf::Color defaultColor,
                           const sf::Color hoveredColor, sf::Font& font) : sf::CircleShape(radius),
                           defaultColor(defaultColor), hoveredColor(hoveredColor), text(text, font) {

    setFillColor(defaultColor);
    this -> text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(30);
    setPosition(25, 280);

    centerText(*this, this->text);

    sf::CircleShape::setFillColor(defaultColor);
}

void CircleButton::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isHovered(*this, window))
    {
        sf::CircleShape::setFillColor(hoveredColor);
    }
    else {
        sf::CircleShape::setFillColor(defaultColor);
    }

    if(MouseEvents::isClicked(*this, window))
    {
        sf::CircleShape::setFillColor(sf::Color::White);
    }

}

std::string CircleButton::getValue() const {
    return text.getString();
}

const sf::Color &CircleButton::getDefaultColor() const {
    return defaultColor;
}

void CircleButton::setDefaultColor(const sf::Color &defaultColor) {
    CircleButton::defaultColor = defaultColor;
}

const sf::Color &CircleButton::getHoveredColor() const {
    return hoveredColor;
}

void CircleButton::setHoveredColor(const sf::Color &hoveredColor) {
    CircleButton::hoveredColor = hoveredColor;
}

void CircleButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw((sf::CircleShape)*this, states);
    target.draw(text, states);
}

sf::Text& CircleButton::getText() {
    return CircleButton::text;
}

std::string CircleButton::getString() {
    return text.getString();
}
