//
// Created by Jason on 5/22/2024.
//

#ifndef RPN_ALGORITHM_INVALIDPOSTFIXEXCEPTION_H
#define RPN_ALGORITHM_INVALIDPOSTFIXEXCEPTION_H
#include <exception>

class InvalidPostfixException : public std::exception
{

public:
    const char* what() const noexcept;
};

#endif //RPN_ALGORITHM_INVALIDPOSTFIXEXCEPTION_H
