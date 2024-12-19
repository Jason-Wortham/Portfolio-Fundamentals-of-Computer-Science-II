//
// Created by Jason on 5/22/2024.
//

#include "Postfix.h"
#include <sstream>

Postfix::Postfix() {

}

Postfix::Postfix(const std::string& postfix) {
    setEquation(postfix);
}


void Postfix::setEquation(const std::string& postfix) {

    clear();

    std::stringstream ss(postfix);
    std::string str;
    while (ss >> str) {
        Term term(str);
        equation.push(term);
    }
}


void Postfix::clear() {
    while(equation.empty() == false) {
        equation.pop();
    }


}

std::stack<Term>& Postfix::getEquation() {
    return equation;
}