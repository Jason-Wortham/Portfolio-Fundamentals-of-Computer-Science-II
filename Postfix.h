//
// Created by Jason on 5/22/2024.
//

#ifndef RPN_ALGORITHM_POSTFIX_H
#define RPN_ALGORITHM_POSTFIX_H
#include <stack>
#include <string>
#include "Term.h"

class Postfix {
    std::stack<Term> equation;

public:
    Postfix();
    Postfix(const std::string& postfix);

    void setEquation(const std::string& postfix);
    void clear();

    std::stack<Term>& getEquation();
};


#endif //RPN_ALGORITHM_POSTFIX_H
