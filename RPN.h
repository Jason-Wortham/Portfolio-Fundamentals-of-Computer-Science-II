//
// Created by Jason on 5/22/2024.
//

#ifndef RPN_ALGORITHM_RPN_H
#define RPN_ALGORITHM_RPN_H

#include <stack>
#include "InvalidPostfixException.h"
#include "Postfix.h"
#include "Term.h"

class RPN
{
    static Term evaluate(std::stack<Term>& stack, Term term);

public:
    static Term evaluate(Postfix& equation);

};

#endif //RPN_ALGORITHM_RPN_H
