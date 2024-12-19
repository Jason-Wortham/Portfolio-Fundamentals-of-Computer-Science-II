//
// Created by Jason on 6/7/2024.
//

#ifndef RPN_ALGORITHM_NEGATIVENUMBEREXCEPTION_H
#define RPN_ALGORITHM_NEGATIVENUMBEREXCEPTION_H
#include <exception>

class NegativeNumberException : public std::exception
{

public:
    const char* what() const noexcept;
};

#endif //RPN_ALGORITHM_NEGATIVENUMBEREXCEPTION_H
