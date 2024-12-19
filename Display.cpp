//
// Created by Jason on 5/20/2024.
//

#include "Display.h"
#include "CalculatorColorPalette.h"

Display::Display() {
    setPosition(25, 20);
    setSize(sf::Vector2f(300.f, 200.f));
    setFillColor(CalculatorColorPalette::lightGrey);
    setOutlineColor(CalculatorColorPalette::darkGrey);
    setOutlineThickness(5.f);

    Fonts fontManager;
    sf::Font& openSansBold = fontManager.getFont(Fonts::OPEN_SANS_BOLD);

    Display::text.setFont(openSansBold);
    Display::text.setCharacterSize(30);
    Display::text.setFillColor(CalculatorColorPalette::charcoal);
    Display::text.setString("");
    positionText();
}

void Display::positionText() {
    text.setPosition(40, 50);
}

void Display::update(const std::string& text) {
    Display::text.setString(text);
}

void Display::clear() {
    update("");
}

sf::Text Display::getText() const {
    return text;
}

std::string Display::getValue() {
    std::string textString = text.getString();
    return textString;
}