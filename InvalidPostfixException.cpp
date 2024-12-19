//
// Created by Jason on 5/22/2024.
//

#include "InvalidPostfixException.h"

const char *InvalidPostfixException::what() const noexcept
{
    return "Invalid postfix expression";
}