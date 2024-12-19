//
// Created by Jason on 5/22/2024.
//

#ifndef RPN_ALGORITHM_TERM_H
#define RPN_ALGORITHM_TERM_H
#include <string>

class Term {
    std::string term;

public:
    Term();
    Term(const std::string& term);
    const std::string& getValue();
    bool isOperator();
    bool isNumber();
    double getNumber();
    void checkNegative();
};


#endif //RPN_ALGORITHM_TERM_H
