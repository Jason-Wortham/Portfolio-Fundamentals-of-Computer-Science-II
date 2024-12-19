//
// Created by Jason on 5/22/2024.
//

#include "RPN.h"
#include "Postfix.h"
#include <cmath>
#include "DivideByZeroException.h"

Term RPN::evaluate(std::stack<Term>& stack, Term term) {

    if (stack.size() < 2) {
        throw InvalidPostfixException();
    }

    Term num2 = stack.top();
    stack.pop();
    Term num1 = stack.top();
    stack.pop();

    if(term.getValue() == "-") {
        Term term(std::to_string(num1.getNumber() - num2.getNumber()));
        return term;
    }
    else if(term.getValue() == "+") {
        Term term(std::to_string(num1.getNumber() + num2.getNumber()));
        return term;
    }
    else if(term.getValue() == "*") {
        Term term(std::to_string(num1.getNumber() * num2.getNumber()));
        return term;
    }
    else if(term.getValue() == "/") {
        if(num2.getNumber() != 0) {
            Term term(std::to_string(num1.getNumber() / num2.getNumber()));
            return term;
        }
        else {
            throw DivideByZeroException();
        }
    }
    else if(term.getValue() == "^") {
        Term term(std::to_string(pow(num1.getNumber(), num2.getNumber())));
        return term;
    }
}

Term RPN::evaluate(Postfix& equation) {

    std::stack<Term> newStack;
    std::stack<Term> stackEquation = equation.getEquation();
    std::stack<Term> backwardsStack;

    while(stackEquation.empty() == false) {
        stackEquation.top().checkNegative();
        backwardsStack.push(stackEquation.top());
        stackEquation.pop();
    }

    while(backwardsStack.empty() == false) {
        Term term = backwardsStack.top();
        backwardsStack.pop();

        if (term.isOperator()) {
            Term result = evaluate(newStack, term);
            newStack.push(result);
        }
        else {
            newStack.push(term);
        }
    }

    return newStack.top();
}