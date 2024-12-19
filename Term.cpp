//
// Created by Jason on 5/22/2024.
//

#include "Term.h"
#include "NotANumberException.h"
#include "NegativeNumberException.h"

Term::Term() {

}

Term::Term(const std::string& term) {
    Term::term = term;
}

const std::string &Term::getValue() {
    return term;
}

bool Term::isOperator() {
    if(term == "+" || term == "-" || term == "*" || term == "/" || term == "^") {
        return true;
    }
    else {
        return false;
    }
}

bool Term::isNumber() {
    if(isOperator() == true) {
        return false;
    }
    else {
        return true;
    }
}

double Term::getNumber() {
    if(isNumber() == true) {
        return stod(getValue());
    }
    else {
        throw NotANumberException();
    }
}

void Term::checkNegative() {
    if(isNumber() == true){
        if(getNumber() < 0) {
            throw NegativeNumberException();
        }
    }
}