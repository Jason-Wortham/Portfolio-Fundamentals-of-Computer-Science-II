//
// Created by Jason on 5/20/2024.
//

#include "Calculator.h"
#include "RPN.h"

Calculator::Calculator() {
    Fonts fontManager;

    sf::Font& openSansBold = fontManager.getFont(Fonts::OPEN_SANS_BOLD);
    sf::Font& openSansRegular = fontManager.getFont(Fonts::OPEN_SANS_REGULAR);

    CircleButton button1("1", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    _buttons.push_back(button1);

    CircleButton button2("2", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::right(button1, button2, 20.f);

    _buttons.push_back(button2);

    CircleButton button3("3", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::right(button2, button3, 20.f);

    _buttons.push_back(button3);

    CircleButton buttonX("X", 30, CalculatorColorPalette::orange,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonX.getText().setFillColor(CalculatorColorPalette::charcoal);

    Position::right(button3, buttonX, 20.f);

    _buttons.push_back(buttonX);

    CircleButton button4("4", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button1, button4, 20.f);

    _buttons.push_back(button4);

    CircleButton button5("5", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button2, button5, 20.f);

    _buttons.push_back(button5);

    CircleButton button6("6", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button3, button6, 20.f);

    _buttons.push_back(button6);

    CircleButton buttonD("/", 30, CalculatorColorPalette::orange,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonD.getText().setFillColor(CalculatorColorPalette::charcoal);

    Position::bottom(buttonX, buttonD, 20.f);

    _buttons.push_back(buttonD);

    CircleButton button7("7", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button4, button7, 20.f);

    _buttons.push_back(button7);

    CircleButton button8("8", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button5, button8, 20.f);

    _buttons.push_back(button8);

    CircleButton button9("9", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button6, button9, 20.f);

    _buttons.push_back(button9);

    CircleButton buttonP("+", 30, CalculatorColorPalette::orange,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonP.getText().setFillColor(CalculatorColorPalette::charcoal);

    Position::bottom(buttonD, buttonP, 20.f);

    _buttons.push_back(buttonP);

    CircleButton buttonC("C", 30, CalculatorColorPalette::charcoal,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    Position::bottom(button8, buttonC, 20.f);

    _buttons.push_back(buttonC);

    CircleButton buttonM("-", 30, CalculatorColorPalette::orange,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonM.getText().setFillColor(CalculatorColorPalette::charcoal);

    Position::bottom(buttonP, buttonM, 20.f);

    _buttons.push_back(buttonM);

    CircleButton buttonR("^", 30, CalculatorColorPalette::orange,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonR.getText().setFillColor(CalculatorColorPalette::charcoal);

    Position::bottom(buttonM, buttonR, 20.f);

    _buttons.push_back(buttonR);

    CircleButton buttonE("=", 30, CalculatorColorPalette::charcoal,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    buttonE.getText().setFillColor(sf::Color::White);

    Position::right(buttonC, buttonE, 20.f);

    _buttons.push_back(buttonE);

    CircleButton button0("0", 30, CalculatorColorPalette::darkGrey,
                         CalculatorColorPalette::lightGrey, openSansRegular);

    button0.getText().setFillColor(sf::Color::White);

    Position::left(buttonC, button0, 20.f);

    _buttons.push_back(button0);
}

void Calculator::clear() {
    _display.clear();
}

void Calculator::update(sf::RenderWindow& window) {
    for(int i = 0; i < _buttons.size(); i ++) {
        if(MouseEvents::isClicked(_buttons[i], window) && _buttons[i].getString() != "C") {
            _display.update(_display.getValue() + _buttons[i].getString());
            if(_buttons[i].getString() != "=" && _buttons[i].getString() != "X") {
                postfixString += (" " + _buttons[i].getString());
            }
            else if(_buttons[i].getString() != "=" && _buttons[i].getString() == "X") {
                postfixString += (" *");
            }
        }
        else if(MouseEvents::isClicked(_buttons[i], window) && _buttons[i].getString() == "C") {
            clear();
        }

        if(MouseEvents::isClicked(_buttons[i], window) && _buttons[i].getString() == "="){
            Postfix postfix(postfixString);
            std::string result = RPN::evaluate(postfix).getValue();
            clear();
            postfixString = "";
            _display.update(result);
        }

    }
}

void Calculator::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    sf::RectangleShape background = *this;
    window.draw(background);
    window.draw(_display);
    window.draw(_display.getText(), states);
    for(const auto& b : _buttons)
        window.draw(b);
}

std::vector<CircleButton>& Calculator::getButtons() {
    return _buttons;
}